/*
*****************************************************************************
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3



int main(void)
{
    const int JAN = 1, DEC=12;
    int i;
    double morningR, eveningR, morningT=0, eveningT=0;
    int yearLog, monthLog;

    printf("General Well-being Log\n");
    printf("======================\n");

    do {

        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf(" %d %d", &yearLog, &monthLog);


        if (yearLog < MIN_YEAR || yearLog > MAX_YEAR) {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (monthLog < JAN || monthLog > DEC) {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }

    } while (((yearLog < MIN_YEAR || yearLog > MAX_YEAR) || (monthLog < 1 || monthLog > 12)));

    printf("\n*** Log date set! ***\n");

    for (i = 1; i < LOG_DAYS + 1; i++) {

        printf("\n");

    switch (monthLog) {
    case 1:
        printf("%d-JAN", yearLog);
        break;
    case 2:
        printf("%d-FEB", yearLog);
        break;
    case 3:
        printf("%d-MAR", yearLog);
        break;
    case 4:
        printf("%d-APR", yearLog);
        break;
    case 5:
        printf("%d-MAY", yearLog);
        break;
    case 6:
        printf("%d-JUN", yearLog);
        break;
    case 7:
        printf("%d-JUL", yearLog);
        break;
    case 8:
        printf("%d-AUG", yearLog);
        break;
    case 9:
        printf("%d-SEP", yearLog);
        break;
    case 10:
        printf("%d-OCT", yearLog);
        break;
    case 11:
        printf("%d-NOV", yearLog);
        break;
    default:
        printf("%d-DEZ", yearLog);
        break;
    }

    if (i < 10) {
        printf("-0%d\n", i);
    }
    else
    {
        printf("-%d\n", i);
    }

    do {
        printf("   Morning rating (0.0-5.0): ");
        scanf("%lf", &morningR);
        if (morningR < 0 || morningR >5) {
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
        } 
        else {
            morningT += morningR;
        }

    } while (morningR < 0 || morningR > 5);

    do {
        printf("   Evening rating (0.0-5.0): ");
        scanf("%lf", &eveningR);
        if (eveningR < 0 || eveningR >5) {
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
        }
        else {
            eveningT += eveningR;
        }
    } while (eveningR < 0 || eveningR > 5);

    }

    printf("\nSummary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", morningT);
    printf("Evening total rating: %6.3lf\n", eveningT);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", morningT+eveningT);

    printf("Average morning rating: %4.1lf\n", morningT / LOG_DAYS);
    printf("Average evening rating: %4.1lf\n", eveningT / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating: %4.1lf\n", (morningT+eveningT)/(LOG_DAYS*2) );


    return 0;
}