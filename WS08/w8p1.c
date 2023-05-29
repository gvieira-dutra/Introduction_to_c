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


// System Libraries
#include <stdio.h>


// User Libraries
#include "w8p1.h"

//int i;

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number)
{
	//printf("*number = %d", number);
	int value;
	//number = &value;

	do {
		scanf("%d", &value);
		if (value <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (value <= 0);

	if (number != NULL)
	{
		*number = value;
	}
	
	//printf("*number = %d", number);

	return value;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number)
{
	double valueD;

	do {
		scanf("%lf", &valueD);
		if (valueD <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (valueD <= 0);

	if (number != NULL)
	{
		*number = valueD;
	}


	return valueD;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numberOfProducts)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PROD);
	printf("NOTE: A 'serving' is %dg\n", NUM_GRAMS);

}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int position)
{
	int int1 = 0;
	struct CatFoodInfo info2[MAX_PROD];

	printf("\nCat Food Product #%d\n", position+1);
	printf("--------------------\n");
	printf("SKU           : ");
	info2[position].sku = getIntPositive(&int1);
	
	printf("PRICE         : $");
	info2[position].price = getDoublePositive(NULL);

	printf("WEIGHT (LBS)  : ");
	info2[position].prodWeight = getDoublePositive(NULL);

	printf("CALORIES/SERV.: ");
	info2[position].caloriesPerServings = getIntPositive(&int1);

	return info2[position];
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int cal)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, cal);
}

// 7. Logic entry point
void start(void) 
{
	int i;
	struct CatFoodInfo info[MAX_PROD] = {{ 0 }};
	openingMessage(MAX_PROD);

	for (i = 0; i < MAX_PROD; i++)
	{
		info[i] = getCatFoodInfo(i);
	}

	printf("\n");
	displayCatFoodHeader();

	for (i = 0; i < MAX_PROD; i++)
	{
		displayCatFoodData(info[i].sku, &info[i].price, &info[i].prodWeight, info[i].caloriesPerServings);
	

	}

}
