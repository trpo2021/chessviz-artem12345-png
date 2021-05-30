#include "turning.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9
#define NUMBER_OF_STRINGS 8
#define ASCII_ZERO 48

void turning(char board[SIZE][SIZE])
{
    int first_letter, first_number, second_letter, second_number, figure;
    char turn[6];

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            printf("%2c", board[i][j]);
        printf("\n");
    }

    scanf("%s", turn);

    if (check(turn) == 1) {
        first_letter = letter_assignment(turn, 0);
        first_number = number_assignment(turn, 1);
        second_letter = letter_assignment(turn, 3);
        second_number = number_assignment(turn, 4);

        figure = board[first_number][first_letter];
        board[first_number][first_letter] = ' ';
        board[second_number][second_letter] = figure;
    }
}

int check(char* turn)
{
    if ((turn[0] == 'a' || turn[0] == 'b' || turn[0] == 'c' || turn[0] == 'd'
         || turn[0] == 'e' || turn[0] == 'f' || turn[0] == 'g'
         || turn[0] == 'h')
        && (turn[1] == '1' || turn[1] == '2' || turn[1] == '3' || turn[1] == '4'
            || turn[1] == '5' || turn[1] == '6' || turn[1] == '7'
            || turn[1] == '8')
        && turn[2] == '-'
        && (turn[3] == 'a' || turn[3] == 'b' || turn[3] == 'c' || turn[3] == 'd'
            || turn[3] == 'e' || turn[3] == 'f' || turn[3] == 'g'
            || turn[3] == 'h')
        && (turn[4] == '1' || turn[4] == '2' || turn[4] == '3' || turn[4] == '4'
            || turn[4] == '5' || turn[4] == '6' || turn[4] == '7'
            || turn[4] == '8')) {
        return 1;
    } else
        return -1;
}

int letter_assignment(char* turn, int i)
{
    if (turn[i] == 'a')
        return 1;
    if (turn[i] == 'b')
        return 2;
    if (turn[i] == 'c')
        return 3;
    if (turn[i] == 'd')
        return 4;
    if (turn[i] == 'e')
        return 5;
    if (turn[i] == 'f')
        return 6;
    if (turn[i] == 'g')
        return 7;
    if (turn[i] == 'h')
        return 8;
    return 0;
}

int number_assignment(char* turn, int i)
{
    return abs((int)turn[i] - ASCII_ZERO - NUMBER_OF_STRINGS);
}