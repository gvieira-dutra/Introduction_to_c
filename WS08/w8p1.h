/*
*****************************************************************************
                          Workshop - #8 (P1)
Full Name  : GLEISON VIEIRA DUTRA
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
#define MAX_PROD 3
#define NUM_GRAMS 64


// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int sku;
    double price;
    int caloriesPerServings;
    double prodWeight;
};


// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int prod);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int index);


// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int cal);

// 7. Logic entry point
void start(void);
