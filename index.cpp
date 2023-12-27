#include <iostream> 


// board 
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
int row, column;
char turn = 'X';
bool draw = false;

// display board
void display_board() {
    std::cout << "     |     |      \n";

    std::cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    std::cout << "     |     |      \n";

    std::cout << "\n";
}

void player_turn(){
    if(turn == 'X'){
        std::cout << "ntPlayer-1 [X] turn: ";
    }
    else if(turn == 'O') {
        std::cout << "ntPlayer-2 [O] turn: ";
    }
     std::cin>>choice;

     switch (choice){
     case1: row = 0; column = 0; break;
     case2: row = 0; column = 1; break;
     case3: row = 0; column = 2; break;
     case4: row = 1; column = 0; break;
     case5: row = 1; column = 1; break;
     case6: row = 1; column = 2; break;
     case7: row = 2; column = 0; break;
     case8: row = 2; column = 1; break;
     case9: row = 2; column = 2; break;
     default:
        std::cout<<"error";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column != 'O']) {
        board[row][column] = 'X';
        turn = 'O';
    }else {
        std:: cout<< "Box is full, Pick andother box!";
        player_turn();
    }

    display_board();
    
}

bool gameover(){ 
    for (int i = 0; i < 3; i++) {
        if ((board[0][0] == board[1][1] && board[i][0] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[0][i] == board[2][i])) {
            return false;
        }

        if (board[0][0]== board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

        for(int i= 0; i <3; i++)
        for(int j= 0; j <3; j++)

        if(board[i][j]!= 'X' && board[i][j] != 'O')
        return true;

        draw = true;
        return false; 
    }
}

int main () {
    std::cout << "ttt T I C K -- T A C -- T O E -- G A M Ettt";
    std::cout << "ntttt T W O P L A Y E R Sntt";

    while(gameover()) {
        display_board();
        player_turn();
        gameover();
    }
    if(turn == 'X' && draw == false){ 
        std::cout << "CONGRATS player ' X ' you won!";
    } 
    else if(turn == 'O' && draw == false) {
         std::cout << "CONGRATS player ' O ' you won!";
    }
    else 
    std:: cout << "ITS A DRAW!";
}
