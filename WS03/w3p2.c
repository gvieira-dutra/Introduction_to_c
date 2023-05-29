/*
*****************************************************************************
                          Workshop - #3 (P2)
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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
     
    char type1, type2, type3;
    char size1, size2, size3;
    char strength, withCream, maker;
    int numOfServings;
    int weight1 = 250, weight2 = 500, weight3 = 1000;
    char cream1, cream2, cream3;
    double temp1=65.7, temp2=70.0, temp3=80.5;
    const double GRAMS_IN_LBS = 453.5924;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\nEnter the coffee product information being sold today...\n");
    printf("\nCOFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type1);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &size1);
    printf("Bag weight (g): ");
    scanf("%d", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf", &temp1);
    
    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type2);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &size2);
    printf("Bag weight (g): ");
    scanf("%d", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf", &temp2);
    
    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type3);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &size3);
    printf("Bag weight (g): ");
    scanf("%d", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf", &temp3);

    

    printf("\n---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", type1 == 'l' || type1 == 'L', !(type1 == 'l' || type1 == 'L'), size1 == 'c' || size1 == 'C', !(size1 == 'c' || size1 == 'C'), weight1, weight1 / GRAMS_IN_LBS, cream1 == 'y' || cream1 == 'Y', temp1, (temp1 * 1.8) + 32.0);
    printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", type2 == 'l' || type2 == 'L', !(type2 == 'l' || type2 == 'L'), size2 == 'c' || size2 == 'C', !(size2 == 'c' || size2 == 'C'), weight2, weight2 / GRAMS_IN_LBS, cream2 == 'y' || cream2 == 'Y', temp2, (temp2 * 1.8) + 32.0);
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", type3 == 'l' || type3 == 'L', !(type3 == 'l' || type3 == 'L'), size3 == 'c' || size3 == 'C', !(size3 == 'c' || size3 == 'C'), weight3, weight3 / GRAMS_IN_LBS, cream3 == 'y' || cream3 == 'Y', temp3, (temp3 * 1.8) + 32.0);

    printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n");

    printf("\nCoffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &strength);   
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &withCream);   
    printf("Typical number of daily servings: ");
    scanf("%d", &numOfServings);   
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &maker);



    printf("\nThe below table shows how your preferences align to the available products:\n");

    printf("\n--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", ((type1 == 'l' || type1 == 'L') && (strength == 'm' || strength == 'M')) || ((type1 == 'b' || type1 == 'B') && (strength == 'r' || strength == 'R')), ((size1 == 'c' || size1 == 'C') && (maker == 'r' || maker == 'R')) || ((size1 == 'f' || size1 == 'F') && (maker == 'c' || maker == 'C')), ((weight1 >= 0 && weight1 <= 250) && (numOfServings >= 1 && numOfServings <= 4)) || ((weight1 >= 251 && weight1 <= 500) && (numOfServings >= 5 && numOfServings <= 9)) || ((weight1 >= 501) && (numOfServings >= 10)), ((withCream == 'y' || withCream == 'Y') && (cream1 == 'y' || cream1 == 'Y')) || ((withCream == 'n' || withCream == 'N') && (cream1 == 'n' || cream1 == 'N')), ((maker == 'r' || maker == 'R') && (temp1 >= 60 && temp1 <= 69.9)) || ((maker =='c' || maker=='C')&&(temp1>=70.0)));
      printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", ((type2 == 'l' || type2 == 'L') && (strength == 'm' || strength == 'M')) || ((type2 == 'b' || type2 == 'B') && (strength == 'r' || strength == 'R')), ((size2 == 'c' || size2 == 'C') && (maker == 'r' || maker == 'R')) || ((size2 == 'f' || size2 == 'F') && (maker == 'c' || maker == 'C')), ((weight2 >= 0 && weight2 <= 250) && (numOfServings >= 1 && numOfServings <= 4)) || ((weight2 >= 251 && weight2 <= 500) && (numOfServings >= 5 && numOfServings <= 9)) || ((weight2 >= 501) && (numOfServings >= 10)), ((withCream == 'y' || withCream == 'Y') && (cream2 == 'y' || cream2 == 'Y')) || ((withCream == 'n' || withCream == 'N') && (cream2 == 'n' || cream2 == 'N')), ((maker == 'r' || maker == 'R') && (temp2 >= 60 && temp2 <= 69.9)) || ((maker == 'c' || maker == 'C') && (temp2 >= 70.0)));;
      printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", ((type3 == 'l' || type3 == 'L') && (strength == 'm' || strength == 'M')) || ((type3 == 'b' || type3 == 'B') && (strength == 'r' || strength == 'R')), ((size3 == 'c' || size3 == 'C') && (maker == 'r' || maker == 'R')) || ((size3 == 'f' || size3 == 'F') && (maker == 'c' || maker == 'C')), ((weight3 >= 0 && weight3 <= 250) && (numOfServings >= 1 && numOfServings <= 4)) || ((weight3 >= 251 && weight3 <= 500) && (numOfServings >= 5 && numOfServings <= 9)) || ((weight3 >= 501) && (numOfServings >= 10)), ((withCream == 'y' || withCream == 'Y') && (cream3 == 'y' || cream3 == 'Y')) || ((withCream == 'n' || withCream == 'N') && (cream3 == 'n' || cream3 == 'N')), ((maker == 'r' || maker == 'R') && (temp3 >= 60 && temp3 <= 69.9)) || ((maker == 'c' || maker == 'C') && (temp3 >= 70.0)));

    printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n");

    printf("\nCoffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &withCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &numOfServings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &maker);

  

      printf("\nThe below table shows how your preferences align to the available products:\n");

      printf("\n--------------------+--------------------+-------------+-------+--------------\n");
      printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
      printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
      printf("--+-----------------+--------------------+-------------+-------+--------------\n");
      printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", ((type1 == 'l' || type1 == 'L') && (strength == 'm' || strength == 'M')) || ((type1 == 'b' || type1 == 'B') && (strength == 'r' || strength == 'R')), ((size1 == 'c' || size1 == 'C') && (maker == 'r' || maker == 'R')) || ((size1 == 'f' || size1 == 'F') && (maker == 'c' || maker == 'C')),((weight1 >= 0 && weight1 <= 250) && (numOfServings >= 1 && numOfServings <= 4)) || ((weight1 >= 251 && weight1 <= 500) && (numOfServings >= 5 && numOfServings <= 9)) || ((weight1 >= 501) && (numOfServings >= 10)), ((withCream == 'y' || withCream == 'Y') && (cream1 == 'y' || cream1 == 'Y')) || ((withCream == 'n' || withCream == 'N') && (cream1 == 'n' || cream1 == 'N')), ((maker == 'r' || maker == 'R') && (temp1 >= 60 && temp1 <= 69.9)) || ((maker =='c' || maker=='C')&&(temp1>=70.0)));
      printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", ((type2 == 'l' || type2 == 'L') && (strength == 'm' || strength == 'M')) || ((type2 == 'b' || type2 == 'B') && (strength == 'r' || strength == 'R')), ((size2 == 'c' || size2 == 'C') && (maker == 'r' || maker == 'R')) || ((size2 == 'f' || size2 == 'F') && (maker == 'c' || maker == 'C')), ((weight2 >= 0 && weight2 <= 250) && (numOfServings >= 1 && numOfServings <= 4)) || ((weight2 >= 251 && weight2 <= 500) && (numOfServings >= 5 && numOfServings <= 9)) || ((weight2 >= 501) && (numOfServings >= 10)), ((withCream == 'y' || withCream == 'Y') && (cream2 == 'y' || cream2 == 'Y')) || ((withCream == 'n' || withCream == 'N') && (cream2 == 'n' || cream2 == 'N')), ((maker == 'r' || maker == 'R') && (temp2 >= 60 && temp2 <= 69.9)) || ((maker == 'c' || maker == 'C') && (temp2 >= 70.0)));;
      printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", ((type3 == 'l' || type3 == 'L') && (strength == 'm' || strength == 'M')) || ((type3 == 'b' || type3 == 'B') && (strength == 'r' || strength == 'R')), ((size3 == 'c' || size3 == 'C') && (maker == 'r' || maker == 'R')) || ((size3 == 'f' || size3 == 'F') && (maker == 'c' || maker == 'C')), ((weight3 >= 0 || weight3 <= 250) && (numOfServings >= 1 && numOfServings <= 4)) || ((weight3 >= 251 || weight3 <= 500) && (numOfServings >= 5 && numOfServings <= 9)) || ((weight3 >= 501) && (numOfServings >= 10)), ((withCream == 'y' || withCream == 'Y') && (cream3 == 'y' || cream3 == 'Y')) || ((withCream == 'n' || withCream == 'N') && (cream3 == 'n' || cream3 == 'N')), ((maker == 'r' || maker == 'R') && (temp3 >= 60 && temp3 <= 69.9)) || ((maker == 'c' || maker == 'C') && (temp3 >= 70.0)));



      printf("\nHope you found a product that suits your likes!\n");

    return 0;
}


