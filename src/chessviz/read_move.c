#include "read_move.h"
#include <libchessviz/print.h>
char turn[5];

void yf_cord_check(int* yf)
{
    switch (turn[3]) {
    case 'a':
        *yf = 1;
        break;
    case 'b':
        *yf = 2;
        break;
    case 'c':
        *yf = 3;
        break;
    case 'd':
        *yf = 4;
        break;
    case 'e':
        *yf = 5;
        break;
    case 'f':
        *yf = 6;
        break;
    case 'g':
        *yf = 7;
        break;
    case 'h':
        *yf = 8;
        break;
    default:
        *yf = 0;
    }
}
void ys_cord_check(int* ys)
{
    switch (turn[0]) {
    case 'a':
        *ys = 1;
        break;
    case 'b':
        *ys = 2;
        break;
    case 'c':
        *ys = 3;
        break;
    case 'd':
        *ys = 4;
        break;
    case 'e':
        *ys = 5;
        break;
    case 'f':
        *ys = 6;
        break;
    case 'g':
        *ys = 7;
        break;
    case 'h':
        *ys = 8;
        break;
    default:
        *ys = 0;
    }
}
int move_true_check(char board[9][9], int color)
{
    int xs, ys, xf, yf;
    if (color == 0) {
        xs = 56 - turn[1];
        xf = 56 - turn[4];
    } else {
        xs = 56 - turn[1];
        xf = 56 - turn[4];
    }
    ys_cord_check(&ys);
    yf_cord_check(&yf);
    if (ys == 0) {
        print_err();
        return 0;
    }
    if (yf == 0) {
        print_err();
        return 0;
    }
    if (((board[xs][ys] == 'P' || board[xs][ys] == 'p') && abs(xf - xs) == 1
         && ys == yf)
        || ((board[xs][ys] == 'P' || board[xs][ys] == 'p')
            && (board[xf][yf] == 'P' || board[xf][yf] == 'p')
            && abs(xf - xs) == 1 && abs(ys - yf) == 1))
        move(board, xs, xf, ys, yf);
    else {
        print_err();
        print(board);
        return 0;
    }
    print(board);
    return 1;
}
void print_err()
{
    printf("Wrong coordinates, try again.\n");
}
void move(char board[9][9], int xs, int xf, int ys, int yf)
{
    board[xf][yf] = board[xs][ys];
    board[xs][ys] = ' ';
}
void read_move(char board[9][9], int finish, int turnsc)
{
    if (board[1][1] == 0) {
    }
    while (finish != 1) {
        if (turnsc == 0)
            printf("Turn White\n");
        else
            printf("Turn Black\n");
        scanf("%s", turn);
        if ((turn[0] >= 97 && turn[0] <= 104)) {
            if ((turn[3] >= 97 && turn[3] <= 104)) {
                if ((turn[1] >= 49 && turn[1] <= 56)) {
                    if ((turn[4] >= 49 && turn[4] <= 56)) {
                        if (turnsc == 1) {
                            if (move_true_check(board, turnsc) == 1)
                                turnsc = 0;
                        } else {
                            if (move_true_check(board, turnsc) == 1)
                                turnsc = 1;
                        }
                    } else {
                        void print_err();
                    }
                } else {
                    void print_err();
                }
            } else {
                void print_err();
            }
        } else {
            void print_err();
        }
    }
}
