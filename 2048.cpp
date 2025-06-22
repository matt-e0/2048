#include <iostream>

void printBoard(int board[4][4]) {
    for(int i=0; i<4; i++){
        for (int value : board[i]) {
            if (value == 0) {
                std::cout << "[" << " " << "]" << " ";
            } else {
                std::cout << "[" << value << "]" << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
};

void down(int board[4][4]) {
    for(int i = 3; i>0; i--){
        for(int j = 0; j<4; j++){
            if(board[i-1][j] == board[i][j] && board[i][j] != 0 && board[i-1][j] != 0) {
                //std::cout << "hit, " << board[i][j] << " is now " << board[i][j] * 2 << "\n";
                board[i-1][j] = 0;
                board[i][j] *= 2;
            } 
        }
    }
    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            if(board[i][j] != 0 && board[i+1][j] == 0) {
                board[i+1][j] = board[i][j];
                board[i][j] = 0;
            } 
        }
    }
    printBoard(board);
};

void up(int board[4][4]) {
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(board[i+1][j] == board[i][j] && board[i][j] != 0 && board[i+1][j] != 0) {
                //std::cout << "hit, " << board[i][j] << " is now " << board[i][j] * 2 << "\n";
                board[i+1][j] = 0;
                board[i][j] *= 2;
            } 
        }
    }
    for(int i = 3; i>0; i--){
        for(int j = 0; j<4; j++){
            if(board[i][j] != 0 && board[i-1][j] == 0) {
                board[i-1][j] = board[i][j];
                board[i][j] = 0;
            } 
        }
    }
    printBoard(board);
};

void left(int board[4][4]) {
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(board[i][j+1] == board[i][j] && board[i][j] != 0 && board[i][j+1] != 0) {
                //std::cout << "hit, " << board[i][j] << " is now " << board[i][j] * 2 << "\n";
                board[i][j+1] = 0;
                board[i][j] *= 2;
            } 
        }
    }
    for(int i = 0; i<4; i++){
        for(int j = 3; j>0; j--){
            if(board[i][j] != 0 && board[i][j-1] == 0) {
                board[i][j-1] = board[i][j];
                board[i][j] = 0;
            } 
        }
    }
    printBoard(board);
};

void right(int board[4][4]) {
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(board[i][j+1] == board[i][j] && board[i][j] != 0 && board[i][j+1] != 0) {
                //std::cout << "hit, " << board[i][j] << " is now " << board[i][j] * 2 << "\n";
                board[i][j+1] = 0;
                board[i][j] *= 2;
            } 
        }
    }
    for(int i = 0; i<4; i++){
        for(int j = 3; j>0; j--){
            if(board[i][j] != 0 && board[i][j-1] == 0) {
                board[i][j-1] = board[i][j];
                board[i][j] = 0;
            } 
        }
    }
    printBoard(board);
};

// Test
int main() {
    bool exit = false;

    int board[4][4] = {
        {1,0,0,0},
        {0,0,0,1},
        {0,0,1,0},
        {0,1,1,0}
    };
    // printBoard(board);
    


    while(exit == false) {
        printBoard(board);
        //down(board);
        //up(board);
        //left(board);
        right(board);
        char x;
        std::cin >> x;
        if (x=='e') {
            exit = true;
        }           
    }
    std::cout << "Exited\n";
    return 0;
}

