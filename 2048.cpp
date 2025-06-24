#include <iostream>
#include <iomanip>
#include <string>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

void printBoard(int board[4][4], int score) {
    // Check largest number for grid spacing
    int maxVal = 0; 
    for(int i=0; i<4; i++){
        for (int j=0; j<4; j++) {
            if (board[i][j] > maxVal) {
                maxVal = board[i][j];
            }
        }
    }
    // Determine the required space width
    int width = (maxVal == 0) ? 1 : std::to_string(maxVal).length() + 1;
    // Print the board
    for(int i=0; i<4; i++){
        for (int value : board[i]) {
            if (value == 0) {
                std::cout << "[" << std::setw(width) << " " << "]" << " ";
            } else {
                std::cout << "[" << std::setw(width) << value << "]" << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "Score: " << score << "\n";
};

char getInput() {
    #ifdef _WIN32 // Windows
        return _getch();
    #else // Linux / Mac
        struct termios oldt, newt;
        char ch;
        tcgetattr(STDIN_FILENO, &oldt);           // Get terminal attributes
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);         // Disable buffered I/O and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Apply changes
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restore original settings
        return ch;
    #endif
}

void down(int board[4][4], int &score) {
    // Slide down
    for (int j=0; j<4; j++) { // i represents rows, j represents columns
        for (int i=2; i>=0; i--) { // Starting just above the botttom row..
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
    for(int i=3; i>0; i--){
        for(int j=0; j<4; j++){
            if(board[i-1][j] == board[i][j] && board[i][j] != 0) {
                board[i-1][j] = 0;
                board[i][j] *= 2;
                score += board[i][j];
            } 
        }
    }
    //Slide again 
    for (int j=0; j<4; j++) {
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
    for (int j=0; j<4; j++) {
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
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(board[i+1][j] == board[i][j] && board[i][j] != 0) {
                board[i+1][j] = 0;
                board[i][j] *= 2;
                score += board[i][j];
            } 
        }
    }
    //Slide again 
    for (int j=0; j<4; j++) {
        for (int i=1; i<=3; i++) {
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
    for (int i=0; i<4; i++) {
        for (int j=1; j<=3; j++) {
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
    for (int i=0; i<4; i++) {
        for (int j=0; j< 3; j++) {
            if (board[i][j] == board[i][j + 1] && board[i][j] != 0) {
                board[i][j] *= 2;
                board[i][j + 1] = 0;
                score += board[i][j];
            }
        }
    }
    //Slide again 
    for (int i=0; i<4; i++) {
        for (int j=1; j<=3; j++) {
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
    // Slide right
    for (int i=0; i<4; i++) {
        for (int j=2; j>=0; j--) {
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
    for (int i=0; i<4; i++) {
        for (int j=3; j>0; j--) {
            if (board[i][j] == board[i][j - 1] && board[i][j] != 0) {
                board[i][j] *= 2;
                board[i][j - 1] = 0;
                score += board[i][j];
            }
        }
    }
    //Slide again 
    for (int i=0; i<4; i++) {
        for (int j=2; j>=0; j--) {
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

bool hasMoves(int board[4][4]) { // Checks to see if there are any valid moves when board is full
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            if (board[i][j] == 0) return true;
            if (i < 3 && board[i][j] == board[i+1][j]) return true;
            if (j < 3 && board[i][j] == board[i][j+1]) return true;
        }
    }
    return false;
}


void updateBoard(int board[4][4], bool &exit) {
    // Check if board is full (or if 2048 has been reached)
    bool isSpace = false;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (board[i][j] == 0) {
                isSpace = true;
            }
            if (board[i][j] == 2048) {
                std::cout << "\n" << "You win! Keep playing or press a key other than w,a,s,d to exit" << "\n";
            }
        }
    }
    if (isSpace) {
        // Generate 2 or 4
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
        if (!isSpace && !hasMoves(board)) {
            std::cout << "\n" << "You lose! Press any key: " << "\n";
            exit = true;
        }
    }
}

// Main
int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif
    std::cout << "Welcome to my game of 2048, the controls are: " << "\n";
    std::cout << "      ^: w" << "\n" << "<-: a  v: s  ->: d" << "\n";
    std::cout << "Press any key to continue: " << "\n";
    getInput();

    srand(time(0));
    bool exit = false;
    int  score = 0;

    int board[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    
    while(exit == false) {
        updateBoard(board, exit);
        printBoard(board, score);
        char x = getInput();
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

