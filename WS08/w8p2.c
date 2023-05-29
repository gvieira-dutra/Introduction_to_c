/*
*****************************************************************************
                          Workshop - #8 (P2)
Full Name  : Gleison vieira dutra	
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
#include "w8p2.h"


// ----------------------------------------------------------------------------
// PART-1

int i;

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

	printf("\nCat Food Product #%d\n", position + 1);
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
	struct ReportData data[MAX_PROD] = {{ 0 }};
	openingMessage(MAX_PROD);
	int cheapestSKU;
	double cheapestPrice;
	int cheapestIndex;
	

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

	printf("\n");
	displayReportHeader();

	for (i = 0; i < MAX_PROD; i++)
	{
		data[i] = calculateReportData(info[i]);
	}
	
	cheapestPrice = 999999;
	cheapestSKU = 999999;

	for (i = 0; i < MAX_PROD; i++)
	{
		if (data[i].costCalPerServing < cheapestPrice) {
			cheapestPrice = data[i].costCalPerServing;
			cheapestSKU = data[i].sku;
			cheapestIndex = i;
		}
	}

	for (i = 0; i < MAX_PROD; i++)
	{
		displayReportData(data[i], cheapestSKU);
	}
	
	printf("\n");
	displayFinalAnalysis(info[cheapestIndex]);


	return;
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pounds, double* weightKG)
{
	double num;

	num = *pounds / POUND_TO_KG;

	if (weightKG != NULL)
	{
		*weightKG = num;
	}

	return num;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* weightGrams)
{
	int num; 
	
	num = convertLbsKg(pounds, NULL)*1000;
	
	if (weightGrams != NULL)
	{
		*weightGrams = num;
	}
	return num;
}

// 10. convert lbs: kg and g
void convertLbs(double* pounds, double* weightKG, int* weightGrams) 
{
	int numG;
	double numD;

	numD = convertLbsKg(pounds, NULL) ;
	
	if (weightKG != NULL)
	{
		*weightKG = numD;
	}

	numG = convertLbsG(pounds, NULL);

	if (weightGrams != NULL)
	{
		*weightGrams = numG;
	}

	return;
}


// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGram, const int totalGrams, double* numOfServings)
{
	double num = (double)totalGrams/servingSizeGram;

	if (numOfServings != NULL)
	{
		*numOfServings = num;
	}

	return num;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* totalNumOfServings, double* costPerServing)
{
	double num = *price / *totalNumOfServings;

	if (costPerServing != NULL)
	{
		*costPerServing = num;
	}
	return num;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const int* numOfCal, double* costPerCal)
{
	double num = *price / *numOfCal ;
	
	if (costPerCal != NULL)
	{
		*costPerCal = num;
	}
	return num;
}


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFood)
{
	struct ReportData report;

	//report.calories = 9;

	report.calories = catFood.caloriesPerServings;
	report.sku = catFood.sku;
	report.price = catFood.price;
	report.weightPounds = catFood.prodWeight;

	report.weightKG = convertLbsKg(&report.weightPounds, NULL);
	report.weightGram = convertLbsG(&report.weightPounds, NULL);
	report.totalServings = calculateServings(NUM_GRAMS, report.weightGram, &report.totalServings);

	report.costPerServing = calculateCostPerServing(&report.price, &report.totalServings, &report.costPerServing);
	
	report.costCalPerServing = calculateCostPerCal(&report.costPerServing, &report.calories, &report.costCalPerServing);

	/*
	int sku;
	double price;
	int calories;
	double weightPounds;
	*/
	

	return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	//printf("Analysis Report (Note: Serving = %dg\n", ???);
	printf("Analysis Report (Note: Serving = %dg)\n", NUM_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData data, const int cheapest)
{
	if (data.sku == cheapest) {
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n", data.sku, data.price, data.weightPounds, data.weightKG, data.weightGram, data.calories, data.totalServings, data.costPerServing, data.costCalPerServing);
	}
	else{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n", data.sku, data.price, data.weightPounds, data.weightKG, data.weightGram, data.calories, data.totalServings, data.costPerServing, data.costCalPerServing);
	}
	return;
}

// 17. Display the findings (cheapest)23332


void displayFinalAnalysis(const struct CatFoodInfo CatFood) 
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", CatFood.sku, CatFood.price);
	printf("Happy shopping!\n");
	return;
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
