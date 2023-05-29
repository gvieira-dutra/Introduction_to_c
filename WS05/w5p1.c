/*
*****************************************************************************
                          Workshop - #5 (P1)
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


int main(void)
{
    const int JAN = 1, DEC = 12;
    int yearLog, monthLog;

    printf("General Well-being Log\n");
    printf("======================\n");

    do{
        
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf(" %d %d", &yearLog, &monthLog);


        if (yearLog < MIN_YEAR || yearLog > MAX_YEAR) {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (monthLog < JAN || monthLog > DEC) {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        } 

    } while (((yearLog < MIN_YEAR || yearLog > MAX_YEAR) || (monthLog < 1 || monthLog > 12)));

    printf("\n*** Log date set! ***\n\n");
    
    switch (monthLog) {
    case 1:
        printf("Log starting date: %d-JAN-01\n", yearLog);
        break;
    case 2:
        printf("Log starting date: %d-FEB-01\n", yearLog);
        break;
    case 3:
        printf("Log starting date: %d-MAR-01\n", yearLog);
        break;
    case 4:
        printf("Log starting date: %d-APR-01\n", yearLog);
        break;
    case 5:
        printf("Log starting date: %d-MAY-01\n", yearLog);
        break;
    case 6:
        printf("Log starting date: %d-JUN-01\n", yearLog);
        break;
    case 7:
        printf("Log starting date: %d-JUL-01\n", yearLog);
        break;
    case 8:
        printf("Log starting date: %d-AUG-01\n", yearLog);
        break;
    case 9:
        printf("Log starting date: %d-SEP-01\n", yearLog);
        break;
    case 10:
        printf("Log starting date: %d-OCT-01\n", yearLog);
        break;
    case 11:
        printf("Log starting date: %d-NOV-01\n", yearLog);
        break;
    default:
        printf("Log starting date: %d-DEZ-01\n", yearLog);
        break;

    }

    return 0;
}