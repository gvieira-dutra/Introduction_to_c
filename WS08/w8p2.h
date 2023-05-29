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


// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PROD 3
#define NUM_GRAMS 64
#define POUND_TO_KG 2.20462


// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    int caloriesPerServings;
    double prodWeight;
};

struct ReportData
{
    int sku;
    double price;
    int calories;
    double weightPounds;
    double weightKG;
    int weightGram;
    double totalServings;
    double costPerServing;
    double costCalPerServing;

};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
 double convertLbsKg(const double* pounds, double* weightKG);

// 9. convert lbs: g
 int convertLbsG(const double* pounds, int* weightGrams);

// 10. convert lbs: kg / g
 void convertLbs(double* pounds, double* weightKG, int* weightGrams);

// 11. calculate: servings based on gPerServ
 double calculateServings(const int servingSizeGram, const int totalGrams, double* numOfServings);

// 12. calculate: cost per serving
 double calculateCostPerServing(const double* price, const double* totalNumOfServings, double* costPerServing);

// 13. calculate: cost per calorie
 double calculateCostPerCal(const double* price, const int* numOfCal, double* costPerCal);

// 14. Derive a reporting detail record based on the cat food product data
 struct ReportData calculateReportData(const struct CatFoodInfo catFood);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData Data, const int cheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo CatFood);

// ----------------------------------------------------------------------------

