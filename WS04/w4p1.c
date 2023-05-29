/*
*****************************************************************************
                          Workshop - #4 (P1)
Full Name  : Gleison Vieira Dutra
Student ID#: 119237220
Email      : gvieira-dutra@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int num, i;
    char letter;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");

    do {

        printf("\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &letter, &num);

        if (letter != 'D' && letter != 'W' && letter != 'F' && letter != 'Q') {
            printf("ERROR: Invalid entered value(s)!\n");
        }
        else if ((letter != 'Q') && (num < 3 || num >20)) {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
        }
        else if (letter == 'Q' && num != 0) {
            printf("ERROR: To quit, the number of iterations should be 0!\n");
        }
        else if (letter == 'D') {
            printf("DO-WHILE: ");
            do{
                printf("D");
                num--;
            } while (num > 0);
            printf("\n");
        }
        else if (letter == 'W') {
            printf("WHILE   : ");
            while (num > 0) {
                printf("W");
                num--;
            }
            printf("\n");
        }
        else if (letter == 'F') {
            printf("FOR     : ");
            for (i = 0; i < num; i++) {
                printf("F");
             }
            printf("\n");
        }
        
    } while (!(letter == 'Q' && num == 0));

    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");





    return 0;
}