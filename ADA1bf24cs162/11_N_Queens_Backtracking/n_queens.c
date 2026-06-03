#include <stdio.h>

#define MAX 20

int board[MAX][MAX];
int N;

int isSafe(int row, int col) {
    int i, j;

    for (i = 0; i < row; i++) {
        if (board[i][col])
            return 0;
    }

    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0;
    }

    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j])
            return 0;
    }

    return 1;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solveNQueens(int row) {
    if (row == N) {
        printBoard();
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            solveNQueens(row + 1);

            board[row][col] = 0;
        }
    }
}

int main() {
    printf("Enter N: ");
    if (scanf("%d", &N) != 1) return 1;

    solveNQueens(0);

    return 0;
}
