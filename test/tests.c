#include "ctest.h"
#include <libchess/turning.h>

CTEST(checks, check_1)
{
    char turn[6] = "e2-e4";
    int result = check(turn);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(checks, check_2)
{
    char turn[6] = "12345";
    int result = check(turn);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(checks, check_3)
{
    char turn[6] = "e2 e4";
    int result = check(turn);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(letter_assignments, l_assignment_1)
{
    char turn[6] = "e2-e4";
    int index = 0;
    int result = letter_assignment(turn, index);
    int expected = 5;
    ASSERT_EQUAL(expected, result);
}

CTEST(letter_assignments, l_assignment_2)
{
    char turn[6] = "e2-e4";
    int index = 1;
    int result = letter_assignment(turn, index);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(letter_assignments, l_assignment_3)
{
    char turn[6] = "a2-a4";
    int index = 0;
    int result = letter_assignment(turn, index);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(number_assignments, n_assignment_1)
{
    char turn[6] = "e2-e4";
    int index = 1;
    int result = number_assignment(turn, index);
    int expected = 6;
    ASSERT_EQUAL(expected, result);
}

CTEST(number_assignments, n_assignment_2)
{
    char turn[6] = "e2-e4";
    int index = 4;
    int result = number_assignment(turn, index);
    int expected = 4;
    ASSERT_EQUAL(expected, result);
}

CTEST(number_assignments, n_assignment_3)
{
    char turn[6] = "e2-e3";
    int index = 4;
    int result = number_assignment(turn, index);
    int expected = 5;
    ASSERT_EQUAL(expected, result);
}