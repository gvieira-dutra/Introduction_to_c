/******************************************************************************
                          Workshop - #6 (P1)
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
#define wishMax 10
#define wishMin 0
#include <stdio.h>

int main(void)
{
    const double minSal = 500, maxSal = 400000, minCost = 100;
    double income, totalCost,  prityAmount;
    int wishL, i, forecast, prityType, financingPossible;
    double cost[10];
    int important[10];
    char financing[10];


    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");


    do {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &income);

        if (income < minSal)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (income > maxSal)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
    } while (income < minSal || income > maxSal);

    do {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &wishL);

        if (wishL <= wishMin || wishL > wishMax)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
    } while (wishL <= wishMin || wishL > wishMax);

    for (i = 0; i < wishL; i++)
    {

        printf("\nItem-%d Details:\n", i + 1);
        do {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);

            if (cost[i] < minCost)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", minCost);
            }
        } while (cost[i] < minCost);

        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &important[i]);

            if (important[i] < 1 || important[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (important[i] < 1 || important[i] > 3);

        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financing[i]);
            if (financing[i] != 'y' && financing[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (financing[i] != 'y' && financing[i] != 'n');

    }

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    totalCost = 0;
    for (i = 0; i < wishL; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, important[i], financing[i], cost[i]);
        totalCost = totalCost + cost[i];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", totalCost);

    do {

        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &forecast);

        if (forecast < 0 || forecast > 2) 
        {
            printf("\nERROR: Invalid menu selection.\n");
        }
        else if (forecast == 1) {
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", totalCost);
            printf("Forecast: %d years, %d months\n", ((int)(totalCost / income) / 12), ((int)(totalCost / income + .9) % 12));

            financingPossible = 0;
            for (i = 0; i < wishL; i++)
            {
                if (financing[i] == 'y')
                {
                    financingPossible++;
                }
            }
            if (financingPossible != 0)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
        }
        else if (forecast == 2) 
        {
            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf("%d", &prityType);

            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", prityType);

            prityAmount = 0;
            financingPossible = 0;
            for (i = 0; i < wishL; i++)
            {
                if (important[i] == prityType)
                {
                    prityAmount = prityAmount + cost[i];
                    if (financing[i] == 'y')
                    {
                        financingPossible++;
                    }
                }
            }
            printf("Amount:   $%1.2lf\n", prityAmount);
            printf("Forecast: %d years, %d months\n", ((int)(prityAmount / income) / 12), ((int)(prityAmount / income + .9) % 12));

            if (financingPossible != 0)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");

            }
         printf("====================================================\n");
            

            }

        } while (forecast != 0);






        printf("\nBest of luck in all your future endeavours!\n");

        return 0;
    }