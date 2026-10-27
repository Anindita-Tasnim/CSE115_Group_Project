#include <stdio.h>
#define VAT_RATE 0.05

//function prototypes//
void banner(void);  //displays banner//
double calc_scaling(void);  //calculates scaling factor//
double calc_total_ingredient(double); //calculates total amount of ingredient in grams//
double calc_total_cost(double);  //calculates total cost of ingredients including vat//
void display_result (double, double, double); //displays result chart//

int main (void)  //main function//
{
    banner();

    double s;
    s = calc_scaling();

    double t;
    t = calc_total_ingredient(s);

    double c;
    c = calc_total_cost(t);


    display_result(s, t, c);

    return 0;
}

void banner(void) //first function definition//
{
    printf("+========================================+\n");
    printf("   Catering Order and Recipe Scaling\t      \n");
    printf("+========================================+\n");
    printf("\n");
}

double calc_scaling(void) //second function definition//
{
    double serving = 8.00, scaling;
    int guest;

    printf("Enter number of guests: ");
    scanf("%d", &guest);
      scaling = (double)(guest / serving);

    return scaling;
}
double calc_total_ingredient(double scaling) //third function definition//
{
    int code;
    double ingredient_amount;
    printf("Enter dish code: ");
    scanf("%d", &code);
    printf("Enter main ingredient amount in grams: ");
    scanf("%lf", &ingredient_amount);

    return (scaling * ingredient_amount);

}
double calc_total_cost(double t) //fourth function definition//
{
   double cost_per_kg, cost, vat, total;
    printf("Enter cost per kg: ");
    scanf("%lf", &cost_per_kg);
      cost = (t / 1000) * cost_per_kg;
      vat = cost * VAT_RATE;
      total = cost + vat;

    return total;


}
void display_result (double s, double t, double c) //fifth function definition//
{
     printf("\n");
     printf("------------------------------------------------------------------------------\n");
     printf("%-20s%-22s%-22s\t|\n", "Scaling Factor", "Total Ingredient", "Total Cost");
     printf("------------------------------------------------------------------------------\n");
     printf("%-20.2f%-22.2f%-22.2f\t|\n", s , t, c);
     printf("------------------------------------------------------------------------------\n");
}

