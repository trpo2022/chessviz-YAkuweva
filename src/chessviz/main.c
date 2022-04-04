#include "libchessviz/board.h"
#include "libchessviz/board_print_plain.h"
#include <stdio.h>

char init_desk[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'}};

char desk[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                   {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                   {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'}};

int main()
{
    char p[5];
    int b[5];
    int s = 0;

    clear();
    printf("Zdravstvuite\n\nWhite (big)\n\n");

    while (1) {
        print_desk();
        input(p, b);
        clear();

        while (!check_input(b, p) || !check_figure_move(b) || !Player(b, s)) {
            printf("Error..\n\n");
            print_desk();
            printf("\n");
            input(p, b);
            clear();
        }

        move(b);
        s++;
    }
}

