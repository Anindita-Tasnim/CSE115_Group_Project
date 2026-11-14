#include <stdio.h>
#define VAT_RATE 0.05

// Global variables
double serving = 8.00, scaling, ingredient_amount;
double cost_per_kg, cost, vat, total, total_ingredient;
int guest, code;

// Function prototypes
void banner(void);
double calc_scaling(void);
double calc_total_ingredient(double);
double calc_total_cost(double);
void show_summary(int count, double grand_total);
void exit_program(void);


int main(void)
{
    printf("\n+========================================+\n");
    printf("   Catering Order and Recipe Scaling\n");
    printf("+========================================+\n");

    int choice, count = 0;
    double s, t, c;
    double grand_total = 0.0;

    do
    {
        banner();

        printf("Enter your choice: ");
        scanf(" %d", &choice);
        printf("\n");
        switch (choice)
        {
            case 1:
                s = calc_scaling();
                t = calc_total_ingredient(s);

                printf("\nOrder added successfully!\n");
                break;
            case 2:
                c = calc_total_cost(t);
                break;

            case 3:
                count++;
                grand_total += c;

                show_summary(count, grand_total);
                break;

            case 4:
                exit_program();
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}


// Function 1: Display menu
void banner(void)
{
    printf("MENU:\n");
    printf("\n");
    printf("1. Add Catering Order\n");
    printf("2. Calculate Total Cost.\n");
    printf("3. Show Total Records and Grand Total Cost\n");
    printf("4. Exit\n");
    printf("\n");
}


// Function 2: Calculate scaling factor
double calc_scaling(void)
{
    do
    {
        printf("Enter number of guests: ");
        scanf(" %d", &guest);

        if (guest <= 0)
        {
            printf("Invalid! Guest number must be positive.\n");
        }

    } while (guest <= 0);
    printf("Enter dish code: ");
    scanf(" %d", &code);
    scaling = (double)guest / serving;
    printf("---------------------------------\n");
    printf("Scaling factor = %.2lf\n", scaling);
    printf("---------------------------------\n");


    return scaling;
}


// Function 3: Calculate total ingredient
double calc_total_ingredient(double s)
{


    do
    {
        printf("Enter main ingredient amount in grams: ");
        scanf("%lf", &ingredient_amount);

        if (ingredient_amount <= 0)
        {
            printf("Invalid! Amount must be positive.\n");
        }

    } while (ingredient_amount <= 0);

    total_ingredient = s * ingredient_amount;
    printf("---------------------------------\n");
    printf("Total ingredient = %.2lf grams\n", total_ingredient);
    printf("---------------------------------\n");

    return total_ingredient;
}


// Function 4: Calculate total cost
double calc_total_cost(double t)
{
    do
    {
        printf("Enter cost per kg: ");
        scanf(" %lf", &cost_per_kg);

        if (cost_per_kg < 0)
        {
            printf("Invalid! Cost cannot be negative.\n");
        }

    } while (cost_per_kg < 0);

    cost = (t / 1000) * cost_per_kg;

    vat = cost * VAT_RATE;

    total = cost + vat;
    printf("---------------------------------\n");
    printf("Cost = %.2lf\n", cost);
    printf("VAT = %.2lf\n", vat);
    printf("Total cost = %.2lf\n", total);
    printf("---------------------------------\n");
    return total;
}
void show_summary(int count, double grand_total)
{
    printf("------------------------------------------\n");
    printf("            Order Summary\n");
    printf("------------------------------------------\n");

    if (count == 0)
    {
        printf("No orders recorded yet.\n");
        return;
    }

    printf("Total records : %d\n", count);
    printf("Grand total   : %.2lf\n", grand_total);
}

// Function 5: Exit program
void exit_program(void)
{
    printf("\nThank you for using the program!\n");
}
