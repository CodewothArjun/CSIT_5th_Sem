#include <stdio.h>
#define N 8  // Change this value to solve for different board sizes

int board[N];

// Function to print the board
void printSolution() {
    printf("One of the solutions:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at board[row][col]
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||                         // Same column
            board[i] - i == col - row ||               // Same major diagonal
            board[i] + i == col + row)                 // Same minor diagonal
            return 0;
    }
    return 1;
}

// Recursive utility function to solve N-Queens
int solveNQueens(int row) {
    if (row == N) {
        printSolution();
        return 1; // Return 1 to stop after first solution
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (solveNQueens(row + 1))
                return 1;
        }
    }

    return 0; // Backtrack
}

int main() {
    if (!solveNQueens(0)) {
        printf("No solution exists.\n");
    }
    return 0;
}
