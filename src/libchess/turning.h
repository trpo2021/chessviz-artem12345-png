#ifndef TURNING_H
#define TURNING_H

#define SIZE 9

void turning(char board[SIZE][SIZE]);

int check(char* turn);

int letter_assignment(char* turn, int i);

int number_assignment(char* turn, int i);

#endif