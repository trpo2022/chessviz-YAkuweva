#include "../src/libchessviz/board.h"
#include "../src/libchessviz/board_print_plain.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char init_desk[8][8]
        = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
           {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
           {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'}};

char desk[8][8]
        = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
           {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
           {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'}};

char p[8];
int b[5];

//-------------------------------------------------------------

CTEST(InputData, checkinput) // Тест ввода
{
    strcpy(p, "A2qA3"); // Ввод неправильного формата
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    int c1 = check_input(b, p);

    strcpy(p, "A2-A3"); // Обычный ход
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    int c2 = check_input(b, p);

    strcpy(p, "A2-A9"); // Выход за пределы доски
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    int c3 = check_input(b, p);

    strcpy(p, "kavo?"); // Ввод неправильного формата данных
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    int c4 = check_input(b, p);

    const int exp1 = 0;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}

//-------------------------------------------------------------

CTEST(Moving, checkpeshka) // Тест белой пешки
{
    strcpy(p, "B7-B6"); // Ход на одну клетку
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c1 = check_peshka(b);

    strcpy(p, "D7-D5"); // Первый ход на две клетки
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c2 = check_peshka(b);

    strcpy(p, "B6-B4"); // Не первый ход на две клетки
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c3 = check_peshka(b);

    strcpy(p, "B6-С5"); // Ход по диагонали
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c4 = check_peshka(b);

    strcpy(p, "B6-B7"); // Ход назад
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c5 = check_peshka(b);

    strcpy(p, "С7-С5"); // Первый ход через фигуру
    desk[5][2] = 'N';
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c6 = check_peshka(b);

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);

    //   desk[8][8] = init_desk[8][8];
}

//-------------------------------------------------------------
/*
CTEST(Moving, check_peshka) // Тест чёрной пешки
{
    strcpy(p, "A2-A3"); // Ход на одну клетку
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c1 = check_peshka(b);

    strcpy(p, "B2-B4"); // Первый ход на две клетки
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c2 = check_peshka(b);

    strcpy(p, "A3-A5"); // Не первый ход на две клетки
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c3 = check_peshka(b);

    strcpy(p, "B4-С5"); // Ход по диагонали
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c4 = check_peshka(b);

    strcpy(p, "B4-B3"); // Ход назад
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c5 = check_peshka(b);

    strcpy(p, "С2-С4"); // Первый ход через фигуру
    desk[2][2] = 'N';
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c6 = check_peshka(b);

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);

    desk[8][8] = init_desk[8][8];
}
*/
//-------------------------------------------------------------

CTEST(Moving, checkladya) // Тест ладьи
{
    desk[6][0] = ' ';

    strcpy(p, "A8-A5"); // Ход вверх
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c1 = check_ladya(b);

    strcpy(p, "A5-D5"); // Ход вправо
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c2 = check_ladya(b);

    strcpy(p, "D5-A5"); // Ход влево
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c3 = check_ladya(b);

    strcpy(p, "A5-A8"); // Ход вниз
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c4 = check_ladya(b);

    strcpy(p, "A8-A2"); // Ход взятия
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c5 = check_ladya(b);

    strcpy(p, "A2-С4"); // Ход по диагонали
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c6 = check_ladya(b);

    desk[3][0] = 'P';
    strcpy(p, "A2-A6"); // Ход через фигуру
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c7 = check_ladya(b);

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 0;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);

    //  desk[8][8] = init_desk[8][8];
}

//-------------------------------------------------------------

CTEST(Moving, checkhorse) // Тест horse
{
    strcpy(p, "B8-C6"); // Ход прямо вправо
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c1 = check_horse(b);

    strcpy(p, "C6-B4"); // Ход прямо влево
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c2 = check_horse(b);

    strcpy(p, "B4-D3"); // Ход вправо вверх
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c3 = check_horse(b);

    strcpy(p, "D3-С5"); // Ход вниз влево
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c4 = check_horse(b);

    strcpy(p, "C5-A4"); // Ход влево вверх
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c5 = check_horse(b);

    strcpy(p, "A4-B2"); // Ход со взятием
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c6 = check_horse(b);

    strcpy(p, "B2-D1"); // Ход со взятием через фигуру
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c61 = check_horse(b);

    strcpy(p, "D1-E3"); // Ход вниз вправо
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c7 = check_horse(b);

    strcpy(p, "E3-C2"); // Ход влево вверх
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c8 = check_horse(b);

    strcpy(p, "C2-C5"); // Ход на три клетки
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c9 = check_horse(b);

    strcpy(p, "C2-C4"); // Ход на две клетки
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c10 = check_horse(b);

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp61 = 1;
    const int exp7 = 1;
    const int exp8 = 1;
    const int exp9 = 0;
    const int exp10 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4 - 1, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp61, c61);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);
    ASSERT_EQUAL(exp10, c10);

    // desk[8][8] = init_desk[8][8];
}

//-------------------------------------------------------------

CTEST(Moving, checkelephant) // Тест elephant
{
    desk[6][3] = ' ';

    strcpy(p, "C8-F5"); // Ход вправо вверх
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c1 = check_elephant(b);

    strcpy(p, "F5-D3"); // Ход влево вверх
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c2 = check_elephant(b);

    strcpy(p, "D3-B5"); // Ход влево вниз
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c3 = check_elephant(b);

    strcpy(p, "B5-C6"); // Ход вправо вниз
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c4 = check_elephant(b);

    strcpy(p, "C6-G2"); // Ход со взятием
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c5 = check_elephant(b);

    desk[2][5] = 'N';
    strcpy(p, "G2-D5"); // Ход через фигуру
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c6 = check_elephant(b);

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);

    //  desk[8][8] = init_desk[8][8];
}

//-------------------------------------------------------------

CTEST(Moving, checkking) // Тест короля
{
    desk[6][3] = ' ';
    strcpy(p, "D8-D7"); // Ход вверх
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c1 = check_king(b);

    strcpy(p, "D7-C6"); // Ход влево вверх
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c2 = check_king(b);

    strcpy(p, "C6-D5"); // Ход вправо вниз
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c3 = check_king(b);

    desk[3][3] = 'p';
    strcpy(p, "D5-D4"); // Ход со взятием
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c4 = check_king(b);

    strcpy(p, "D4-E5"); // Ход вниз вправо
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c5 = check_king(b);

    strcpy(p, "E5-D6"); // Ход вниз влево
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c6 = check_king(b);

    strcpy(p, "D6-B6"); // Ход на две клетки по горизонтали
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c7 = check_king(b);

    strcpy(p, "D6-D4"); // Ход на две клетки по вертикали
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c8 = check_king(b);

    strcpy(p, "D6-B4"); // Ход на две клетки по диагонали
    for (int i = 0; i < 5; i++)
        b[i] = p[i];
    check_figure_move(b);
    int c9 = check_king(b);

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 0;
    const int exp8 = 0;
    const int exp9 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);

    // desk[8][8] = init_desk[8][8];
}
