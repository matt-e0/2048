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
void incrementScore(int score, int value) {
    score += value;
}
void down(int board[4][4]) {
    // Slide down
    for (int j = 0; j < 4; j++) { // i represents rows, j represents columns
        for (int i = 2; i >= 0; i--) { // Starting just above the botttom row..
            if (board[i][j] != 0) { // Check each cell above current position
                int k = i;
                while (k < 3 && board[k+1][j] == 0) {
                    board[k+1][j] = board[k][j];
                    board[k][j] = 0;
                    k++; // Slide number
                }
            }
        }
    }
    // Compare neighbour
    for(int i = 3; i>0; i--){
        for(int j = 0; j<4; j++){
            if(board[i-1][j] == board[i][j] && board[i][j] != 0) {
                board[i-1][j] = 0;
                board[i][j] *= 2;
            } 
        }
    }
    //Slide again 
    for (int j = 0; j < 4; j++) {
        for (int i = 2; i >= 0; i--) {
            if (board[i][j] != 0) {
                int k = i;
                while (k < 3 && board[k+1][j] == 0) {
                    board[k+1][j] = board[k][j];
                    board[k][j] = 0;
                    k++;
                }
            }
        }
    }
    //printBoard(board);
};

void up(int board[4][4]) {
    // Slide up
    for (int j = 0; j < 4; j++) {
        for (int i = 1; i <= 3; i++) {
            if (board[i][j] != 0) {
                int k = i;
                while (k > 0 && board[k-1][j] == 0) {
                    board[k-1][j] = board[k][j];
                    board[k][j] = 0;
                    k--;
                }
            }
        }
    }
    // Compare neighbour
    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            if(board[i+1][j] == board[i][j] && board[i][j] != 0) {
                board[i+1][j] = 0;
                board[i][j] *= 2;
            } 
        }
    }
    //Slide again 
    for (int j = 0; j < 4; j++) {
        for (int i = 1; i <= 3; i++) {
            if (board[i][j] != 0) {
                int k = i;
                while (k > 0 && board[k-1][j] == 0) {
                    board[k-1][j] = board[k][j];
                    board[k][j] = 0;
                    k--;
                }
            }
        }
    }
    //printBoard(board);
};

void left(int board[4][4]) {
    // Slide left
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 3; j++) {
            if (board[i][j] != 0) { 
                int k = j;
                while (k > 0 && board[i][k-1] == 0) {
                    board[i][k-1] = board[i][k];
                    board[i][k] = 0;
                    k--;
                }
            }
        }
    }
    // Compare neighbour
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == board[i][j + 1] && board[i][j] != 0) {
                board[i][j] *= 2;
                board[i][j + 1] = 0;
            }
        }
    }
    //Slide again 
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 3; j++) {
            if (board[i][j] != 0) { 
                int k = j;
                while (k > 0 && board[i][k-1] == 0) {
                    board[i][k-1] = board[i][k];
                    board[i][k] = 0;
                    k--;
                }
            }
        }
    }
    //printBoard(board);
};

void right(int board[4][4]) {
    // Slide left
    for (int i = 0; i < 4; i++) {
        for (int j = 2; j >= 0; j--) {
            if (board[i][j] != 0) { 
                int k = j;
                while (k < 3 && board[i][k+1] == 0) {
                    board[i][k+1] = board[i][k];
                    board[i][k] = 0;
                    k++;
                }
            }
        }
    }
    // Compare neighbour
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (board[i][j] == board[i][j - 1] && board[i][j] != 0) {
                board[i][j] *= 2;
                board[i][j - 1] = 0;
            }
        }
    }
    //Slide again 
    for (int i = 0; i < 4; i++) {
        for (int j = 2; j >= 0; j--) {
            if (board[i][j] != 0) { 
                int k = j;
                while (k < 3 && board[i][k+1] == 0) {
                    board[i][k+1] = board[i][k];
                    board[i][k] = 0;
                    k++;
                }
            }
        }
    }
    //printBoard(board);
};

void updateBoard(int board[4][4]) {
    srand(time(0));
    int randomNum = rand() % 100;
    if (randomNum <= 89) {
        bool hasUpdated = false;
        while (hasUpdated == false) {
                int randRow = rand() % 4;
                int randColumn = rand() % 4;
                if (board[randRow][randColumn] == 0) {
                    board[randRow][randColumn] = 2;
                    hasUpdated = true;
                }
        }
    } else {
                bool hasUpdated = false;
        while (hasUpdated == false) {
                int randRow = rand() % 4;
                int randColumn = rand() % 4;
                if (board[randRow][randColumn] == 0) {
                    board[randRow][randColumn] = 4;
                    hasUpdated = true;
                }
        }
    }
}

// Test
int main() {
    bool exit = false;

    int board[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    // printBoard(board);
    


    while(exit == false) {
        updateBoard(board);
        printBoard(board);
        char x;
        std::cin >> x;
        switch(x) {
            case 'w':
                up(board);
                break;
            case 's':
                down(board);
                break;
            case 'a':
            left(board);
                break;
            case 'd':
            right(board);
                break;
            default:
                exit = true;
        }  
    }
    std::cout << "Exited\n";
    return 0;
}

