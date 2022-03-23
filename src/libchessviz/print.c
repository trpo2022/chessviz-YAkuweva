#include "print.h"

void print(char board[9][9])
{
    system("clear");
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}
