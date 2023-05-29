/*
*****************************************************************************
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    double price1, price2, price3;
    double taxes1, taxes2, taxes3, taxes4;
    double subTotal1, subTotal2, subTotal3, subTotal4;
    double total1, total2, total3, total4;
    int pattyCart, taxesInt, tomCart, salCart;
    double average1;
    int loonies, toonies, quarters, dimes, nickels, pennies, remainBal;
    

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
    scanf("%d", &pattyCart);
    
    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tomCart);

    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &salCart);

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");

    subTotal1 = pattyCart * price1;
        taxes1 = ((TAX * subTotal1 * 100) + 0.5);
    taxesInt = taxes1;
    taxes1 = taxesInt;
    taxes1 /= 100;
    total1 = subTotal1 + taxes1;
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, price1, pattyCart, subTotal1, taxes1, total1);

    subTotal2 = salCart * price2;
    taxes2 = ((TAX * subTotal2 * 100) + 0.5);
    taxesInt = taxes2;
    taxes2 = taxesInt;
    taxes2 /= 100;
    total2 = subTotal2 + taxes2;
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, price2, salCart, subTotal2, taxes2, total2);

    subTotal3 = tomCart * price3;
    taxes3 = ((TAX * subTotal3 * 100) + 0.5);
    taxesInt = taxes3;
    taxes3 = taxesInt;
    taxes3 /= 100;
    total3 = subTotal3 + taxes3;
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, price3, tomCart, subTotal3, taxes3, total3);

    subTotal4 = subTotal1 + subTotal2 + subTotal3;
    taxes4 = taxes1 + taxes2 + taxes3;
    total4 = total1 + total2 + total3;

    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", subTotal4, taxes4, total4);
    
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n");

    printf("\nSales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", subTotal4);
    
    subTotal4 = subTotal4 * 100;
    toonies = subTotal4 / 200;
    remainBal = (int)subTotal4 % 200;    
    printf("Toonies %4d %9.4lf\n", toonies, (double)remainBal/100);

    loonies = remainBal / 100;
    remainBal = remainBal % 100;
    printf("Loonies %4d %9.4lf\n", loonies, (double)remainBal / 100);

    quarters = remainBal / 25;
    remainBal = remainBal % 25;
    printf("Quarters %3d %9.4lf\n", quarters, (double)remainBal / 100);

    dimes = remainBal / 10;
    remainBal = remainBal % 10;
    printf("Dimes %6d %9.4lf\n", dimes, (double)remainBal / 100);
    
    nickels = remainBal / 5;
    remainBal = remainBal % 5;
    printf("Nickels %4d %9.4lf\n", nickels, (double)remainBal / 100);

    pennies = remainBal / 1;
    remainBal = remainBal % 1;
    printf("Pennies %4d %9.4lf\n", pennies, (double)remainBal / 100);
    
    average1 = subTotal4 / (salCart + tomCart + pattyCart);
    printf("\nAverage cost/shirt: $%.4lf\n", average1/100);

    printf("\nSales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", total4);

    total4 = total4 * 100;
    toonies = total4 / 200;
    remainBal = (int)total4 % 200;
    printf("Toonies %4d %9.4lf\n", toonies, (double)remainBal / 100);

    loonies = remainBal / 100;
    remainBal = remainBal % 100;
    printf("Loonies %4d %9.4lf\n", loonies, (double)remainBal / 100);

    quarters = remainBal / 25;
    remainBal = remainBal % 25;
    printf("Quarters %3d %9.4lf\n", quarters, (double)remainBal / 100);

    dimes = remainBal / 10;
    remainBal = remainBal % 10;
    printf("Dimes %6d %9.4lf\n", dimes, (double)remainBal / 100);

    nickels = remainBal / 5;
    remainBal = remainBal % 5;
    printf("Nickels %4d %9.4lf\n", nickels, (double)remainBal / 100);

    pennies = remainBal / 1;
    remainBal = remainBal % 1;
    printf("Pennies %4d %9.4lf\n", pennies, (double)remainBal / 100);

    average1 = total4 / (salCart + tomCart + pattyCart);
    printf("\nAverage cost/shirt: $%.4lf\n", average1/100);


    return 0;

}