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

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #2 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////
//This function should check is user input is a valid Integer.
int inputInt(void);

//This function should check if the value entered by the user is or not a positive integer. 
int inputIntPositive(void);

//This function will receive 2 arguments and check if the 1st is lower than 2nd. 
int inputIntRange(int lower, int upper);

// This function should check for user input and return one single, valid character as the output.
char inputCharOption(const char list[]);

//This function should obtain a string from the user, the string must have a specific size. 
void inputCString(char* cString, int minimum, int maximum);

//This function should display a phone-number consisting of an arrray of 10-characters digits
void displayFormattedPhone(const char* phonestringAddress);

//This function should obtain a string from the user, the string must have a specific size. 
void phoneValidation(char* cString, int minimum, int maximum);


// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
