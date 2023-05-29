/*
*****************************************************************************
                          Workshop - #2 (P1)
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

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';

    double price1, price2, price3, taxes, subTotal, total;
    int shoppingCart, taxesInt;


    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &price1);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &price2);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &price3);

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", price1);
    printf("MEDIUM : $%.2lf\n", price2);
    printf("LARGE  : $%.2lf\n", price3);

    printf("\nPatty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shoppingCart);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", shoppingCart);
    
    subTotal = shoppingCart * price1;
    printf("Sub-total: $%.4lf\n", subTotal);

    taxes = ((TAX * subTotal * 100) + 0.5);
    taxesInt = taxes;
    taxes = taxesInt;
    taxes  /= 100;
    printf("Taxes    : $ %.4lf\n", taxes);
    
    total = subTotal + taxes;
    printf("Total    : $%.4lf\n", total);

   


    return 0;
}
