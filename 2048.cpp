#include <iostream>
#include <conio.h>

void printBoard(int board[4][4], int score) {
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
    std::cout << "Score: " << score << "\n";
};

void down(int board[4][4], int &score) {
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
                score += board[i][j];
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

void up(int board[4][4], int &score) {
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
                score += board[i][j];
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

void left(int board[4][4], int &score) {
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
                score += board[i][j];
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

void right(int board[4][4], int &score) {
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
                score += board[i][j];
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

void updateBoard(int board[4][4], bool &exit) {
    // Check if board is full
    bool isSpace = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                isSpace = true;
            }
        }
    }
    if (isSpace) {
        // Generate 2 or 4
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
    } else {
        std::cout << "You lose! Press any key other than w,a,s,d" << "\n";
        exit = true;
    }
}

// Test
int main() {
    bool exit = false;
    int  score = 0;

    int board[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    // printBoard(board);
    


    while(exit == false) {
        updateBoard(board, exit);
        printBoard(board, score);
        char x = _getch();
        //std::cin >> x;
        switch(x) {
            case 'w':
                up(board, score);
                break;
            case 's':
                down(board, score);
                break;
            case 'a':
            left(board, score);
                break;
            case 'd':
            right(board, score);
                break;
            default:
                exit = true;
        }  
    }
    std::cout << "Exited\n";
    return 0;
}

