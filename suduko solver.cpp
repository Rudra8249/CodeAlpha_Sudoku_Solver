#include <iostream>
using namespace std;

const int SIZE = 9;

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Check if a number is safe to place at grid[row][col]
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check the row and column
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num)
            return false;
    }

    // Check the 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

// Recursive function to solve the Sudoku
bool solveSudoku(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            // If the cell is empty
            if (grid[row][col] == 0) {
                // Try numbers 1 to 9
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;

                        // Recursively try to solve the rest
                        if (solveSudoku(grid))
                            return true;

                        // Backtrack if not valid
                        grid[row][col] = 0;
                    }
                }

                // No valid number found, trigger backtracking
                return false;
            }
        }
    }

    // All cells filled correctly
    return true;
}

int main() {
    // 0 means empty cell
    int grid[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) {
        cout << "Solved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists!";
    }

    return 0;
}
