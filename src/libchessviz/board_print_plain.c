#include "board_print_plain.h"
#include "board.h"
#include <stdio.h>

extern char init_desk[8][8];
extern char desk[8][8];

void print_desk()
{
    int i, j;
    for (i = 0; i < 8; i++) {
        printf("%d", (i + 1));
        printf("|");

        //        cout << setw(2) << i + 1 << "|";
        for (j = 0; j < 8; j++) {
            if (desk[i][j] == ' ')
                printf("_|");
            //                cout << setw(3) << "_|";
            else {
                printf("%c", desk[i][j]);
                printf("|");
            }
            //    cout << setw(2) << desk[i][j] << "|";
        }
        printf("\n");
    }
    printf("  ");
    // cout << "  ";
    for (i = 0; i < 8; i++) {
        printf("%c", (i + 97));
        printf(" ");
    }
    //   cout << setw(3) << (char)(i + 97);
    printf("\n");
}
