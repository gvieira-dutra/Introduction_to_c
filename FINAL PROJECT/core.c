/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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
#include <ctype.h>
#include <string.h>
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//This function should check is user input is a valid Integer.
int inputInt(void)
{
    char newline = 'x';
    int value;

    do {

        scanf("%d%c", &value, &newline);
        if (newline != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

        //printf("%d%c", value, newline);
    } while (newline != '\n');

    return value;
}

//This function should check if the value entered by the user is or not a positive integer. 
int  inputIntPositive(void)
{
    int positive;

    do {
        positive = inputInt();
        if (positive <= 0) {
            printf("ERROR! Value must be > 0: ");
        }
    } while (positive <= 0);

    return positive;
}

//This function will receive 2 arguments and check if the 1st is lower than 2nd. 
int inputIntRange(int lower, int upper)
{
    int rangeInput;

    do {
        rangeInput = inputInt();
        if (rangeInput < lower || rangeInput > upper)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
        }

    } while (rangeInput < lower || rangeInput > upper);

    return rangeInput;
}

// This function should check for user input and return one single, valid character as the output.
char inputCharOption(const char list[])
{
    char userChar, secondEntry;
    int i, valid = 0;

    do {
        scanf("%c%c", &userChar, &secondEntry);

        if (secondEntry != '\n')
        {
            printf("ERROR: Character must be one of [%s]: ", list);
            clearInputBuffer();
        }
        else
        {
            for (i = 0; list[i] != '\0' && valid == 0; i++)
            {
                if (list[i] == userChar)
                {
                    valid = 1;
                }
            }
            if (valid == 0)
            {
                printf("ERROR: Character must be one of [%s]: ", list);
            }
        }
    } while (valid == 0);

    return userChar;

}

//This function should obtain a string from the user, the string must have a specific size. 
void inputCString(char* cString, int minimum, int maximum)
{
    int i, length;
    char userString[99] = { '\0' };

    do {
        length = 0;
        scanf("%[^\n]*c", userString);
        clearInputBuffer();

        for (i = 0; userString[i] != '\0'; i++)
        {
            length++;
        }
        if (length < minimum || length > maximum)
        {
            if (minimum == maximum)
            {
                printf("ERROR: String length must be exactly %d chars: ", minimum);
            }
            else
            {
                if (length > maximum)
                {
                    printf("ERROR: String length must be no more than %d chars: ", maximum);
                }
                else
                {
                    printf("ERROR: String length must be between %d and %d chars: ", minimum, maximum);
                }
            }
        }
        else
        {
            strcpy(cString, userString);
        }

    } while (length < minimum || length > maximum);



    return;
}

//This function should display a phone-number consisting of an array of 10-characters digits
void displayFormattedPhone(const char* phonestringAddress)
{

    int i, valid = 0, count = 0;

    if (phonestringAddress != NULL)
    {
        for (i = 0; phonestringAddress[i] != '\0'; i++)
        {
            count++;

            if (!(isdigit(phonestringAddress[i])))
            {
                valid = 1;
            }
        }

        if (valid == 0 && count == 10)
        {
            for (i = 0; phonestringAddress[i] != '\0'; i++)
            {
                if (i == 0)
                {
                    printf("(%c", phonestringAddress[i]);
                }
                else if (i == 2)
                {
                    printf("%c)", phonestringAddress[i]);
                }
                else if (i == 5)
                {
                    printf("%c-", phonestringAddress[i]);
                }
                else
                {
                    printf("%c", phonestringAddress[i]);
                }
            }
        }
        else
        {
            printf("(___)___-____");
        }

    }
    else
    {
        printf("(___)___-____");
    }

    return;
}


//This function should obtain a valid phone number from the user. 
void phoneValidation(char* cString, int minimum, int maximum)
{
    int i, length;
    int flag = 0;
    char userString[99] = { '\0' };

    do {
        flag = 0;
        length = 0;
        scanf("%[^\n]*c", userString);
        clearInputBuffer();

        for (i = 0; userString[i] != '\0'; i++)
        {
            length++;
        }
        
        if (length != minimum)
        {
            printf("Invalid %d-digit number! Number: ", maximum);
        }
        else 
        {
            for (i = 0; userString[i] <  minimum; i++)
            {
                if (isdigit(userString[i]))
                {
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                printf("Invalid %d-digit number! Number: ", maximum);
            }
        }

    } while (length != minimum || flag == 1);

    strcpy(cString, userString);

    return;
}