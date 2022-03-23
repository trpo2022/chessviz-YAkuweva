#ifndef read_move_H
#define read_move_H

void read_move(char board[9][9], int finish, int turnsc);
void move(char board[9][9], int xs, int xf, int ys, int yf);
int move_true_check(char board[9][9], int color);
void print_err();
void yf_cord_check(int* yf);
void ys_cord_check(int* ys);
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#endif
