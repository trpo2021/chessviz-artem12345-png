#include <ctype.h>
#include <libchess/turning.h>
#include <stdio.h>

#define SIZE 9

int main()
{
    char board[SIZE][SIZE];
    int i, j, ch;

    for (i = 1; i < 9; ++i)
        board[1][i] = 'p';

    for (i = 1; i < 9; ++i)
        board[6][i] = 'P';

    for (i = 1; i < 9; ++i)
        board[8][i] = 96 + i;

    for (i = 0; i < 8; ++i)
        board[i][0] = 48 + (8 - i);

    for (i = 2; i < 6; ++i)
        for (j = 1; j < 9; ++j)
            board[i][j] = ' ';

    board[0][1] = 'r';
    board[0][2] = 'n';
    board[0][3] = 'b';
    board[0][4] = 'q';
    board[0][5] = 'k';
    board[0][6] = 'b';
    board[0][7] = 'n';
    board[0][8] = 'r';
    board[8][0] = ' ';

    for (i = 1; i < 9; ++i)
        board[7][i] = toupper(board[0][i]);

    printf("Введите что-нибудь, если хотите начать игру\n");

    while ((ch = getchar()) != EOF)
        turning(board);
}