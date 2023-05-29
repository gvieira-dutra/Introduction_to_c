/*
*****************************************************************************
                          Workshop - #3 (P1)
Full Name  : Gleison Vieira Dutra
Student ID#: 113297220
Email      : gvieira-dutra@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    const int prod1ID = 111, prod2ID = 222, prod3ID = 111;
    const double price1 = 111.49, price2 = 222.99, price3 = 334.49;
    double average;
    char tax1 = 'Y', tax2 = 'N', tax3 = 'N';

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", prod1ID);
    printf("  Taxed: %c\n", tax1);
    printf("  Price: $%.4lf\n", price1);
    
    printf("\nProduct-2 (ID:%d)\n", prod2ID);
    printf("  Taxed: %c\n", tax2);
    printf("  Price: $%.4lf\n", price2);
    
    printf("\nProduct-3 (ID:%d)\n", prod3ID);
    printf("  Taxed: %c\n", tax3);
    printf("  Price: $%.4lf\n", price3);

    average = (price1 + price2 + price3)/3;

    printf("\nThe average of all prices is: $%.4lf\n", average);

    printf("\nAbout Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");

    printf("\nSome Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n", tax1=='Y');
    printf("\n2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", tax1=='Y' && tax2=='N' && tax3=='N');
    printf("\n3. Is product 3 less than testValue ($330.99)? -> %d\n", price3 < testValue);
    printf("\n4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n", price3 > price1+price2);
    printf("\n5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n", price1 >= price3-price2, price3-price2);
    printf("\n6. Is the price of product 2 equal to or more than the average price? -> %d\n", price2>=average);
    printf("\n7. Based on product ID, product 1 is unique -> %d\n", (prod1ID != prod2ID) && (prod1ID != prod3ID));
    printf("\n8. Based on product ID, product 2 is unique -> %d\n", (prod2ID != prod1ID) && (prod2ID != prod3ID));
    printf("\n9. Based on product ID, product 3 is unique -> %d\n", (prod3ID != prod1ID) && (prod3ID != prod2ID));



    return 0;
}