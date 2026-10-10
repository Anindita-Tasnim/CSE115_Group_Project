#include <stdio.h>
#define VAT_RATE 0.05

int main (void)
{
    int code, guest;
    double scaling_factor, ingredient_amount, cost_per_kg , vat, total, total_ingredient, serving = 8.00, cost;


    printf("Enter number of guests: ");
    scanf("%d",&guest);

      scaling_factor = (double)(guest / serving);   /*calculates total serving of dish needed*/

    printf("Enter dish code: ");
    scanf("%d", &code);

    printf("Enter main ingredient amount in grams: ");
    scanf("%lf", &ingredient_amount);

      total_ingredient = scaling_factor * ingredient_amount;    /*calculates total ingredient needed*/

    printf("Enter cost per kg: ");
    scanf("%lf", &cost_per_kg);

      cost = (total_ingredient / 1000) * cost_per_kg;        /*total cost excluding vat*/

      vat = cost * VAT_RATE;

      total = cost + vat;       /*cost including vat*/


     printf("\n");
     printf("--------------------------------------------------------------------------------------------------------\n");
     printf("%-8s%-20s%-22s%-25s%-18s%-12s\n", "Code", "Scaling Factor", "Total Ingredient", "Cost Without Vat", "Vat","Total cost" );
     printf("--------------------------------------------------------------------------------------------------------\n");
     printf("%-8d%-20.2f%-22.2f%-25.2f%-18.2f%-12.2f\n", code, scaling_factor , total_ingredient ,cost ,vat ,total);
     printf("--------------------------------------------------------------------------------------------------------\n");
     printf("\n");
     printf("Total cost of the dish is: %.2f", total);
     printf("\n");


     return 0;

}

