#include <stdio.h>

int m, n;
char board[15][15];

int isSafe(int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        if (board[i][col] == 'X') {
            return 0;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'X') {
            return 0;
        }
    }

    for (i = row, j = col; j < n && i >= 0; i--, j++) {
        if (board[i][j] == 'X') {
            return 0;
        }
    }

    return 1;
}

int solve(int row) {
    if (row >= m) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (board[row][i] == '?' && isSafe(row, i)) {
            board[row][i] = 'X';

            if (solve(row + 1)) {
                return 1;
            }
            board[row][i] = '?';
        }
    }

    return 0;
}

int main() {
    scanf("%d%d", &m, &n);

    for (int i = 0; i < m; i++) {
        scanf("%s", board[i]);
    }

    if (solve(0)) {
        printf("YES\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                printf("%c", board[i][j] == '?' ? '.' : board[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("NO");
    }

    return 0;
}
