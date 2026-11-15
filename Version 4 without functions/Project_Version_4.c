#include <stdio.h>
#define VAT_RATE 0.05
#define serving 8.00

int main (void)
{
        printf("=============================================\n");
        printf("    Catering Order and Recipe Scaling     \n");
        printf("=============================================\n");
    int n, code, guest, count = 0;
    double scaling, ingredient_amount, grand_total = 0.0;

    do
    {
            printf("\n");
            printf("MENU:\n");
            printf("1. Add a dish to the order\n");
            printf("2. Scale a recipe\n");
            printf("3. Build shopping list\n");
            printf("4. Cost per head\n");
            printf("5. Show records and grand total\n");
            printf("6. Exit\n");
            printf("\n");

        printf("Enter your choice from the Menu: ");
        scanf("%d", &n);
        printf("\n");
        switch (n)
        {
            case 1:
                {
                     printf("CURRENT ORDER\n");
                     printf("--------------------------------------------------------------------------------");
                     printf("\n");
                     printf("%-8s%-20s%-15s%-15s%10s", "Code", "Name", "Serving", "Main Ingredient", "Cost/kg\n");
                     printf("--------------------------------------------------------------------------------\n");
                     printf("%-8s%-20s%-15s%-15s%10s", "101", "Chicken Biryani", "8", "250 g", "450.00\n");
                     printf("%-8s%-20s%-15s%-15s%10s", "102", "Beef Korma", "8", "300 g", "500.00\n");
                     printf("%-8s%-20s%-15s%-15s%10s", "103", "Vegetable Pulao", "8", "200 g", "250.00\n");
                     printf("\n");
                    printf("Enter dish code: ");
                    scanf("%d", &code);
                      while(code < 101 || code > 103)
                      {
                          printf("Invalid code.\n");
                          printf("Enter dish code from the Menu: ");
                          scanf("%d", &code);
                      }
                    printf("The dish you chose is %d.\n", code);
                    break;
                }
            case 2:
                {
                    printf("Enter number of guests: ");
                    scanf("%d", &guest);
                      while (guest < 8)
                      {
                         printf("Guest number should be more than Eight.\n");
                         printf("Enter number of guests: ");
                         scanf("%d", &guest);
                      }

                          scaling = (double)guest / serving;
                          printf("-------------------------------\n");
                          printf("Scaling factor : %.2f \n", scaling);
                          printf("-------------------------------\n");

                    break;
                }
            case 3:
                {
                    if (code == 101)
                       {
                         printf("--------------------------------------------------\n");
                         printf("The dish you chose    : Chicken biryani.\n");
                         printf("Main Ingredient amount: 250 grams.\n");
                         printf("--------------------------------------------------\n");
                              ingredient_amount = 250.0 * scaling;
                       }
                    else if (code == 102)
                       { printf("--------------------------------------------------\n");
                         printf("The dish you chose    : Beef korma.\n");
                         printf("Main Ingredient amount: 200 grams.\n");
                         printf("--------------------------------------------------\n");
                         ingredient_amount = 200.0 * scaling;
                       }
                    else
                       { printf("--------------------------------------------------\n");
                         printf("The dish you chose    : Vegetable polau.\n");
                         printf("Main Ingredient amount: 300 grams.\n");
                         printf("--------------------------------------------------\n");
                         ingredient_amount = 300.0 * scaling;
                       }
                       printf("Shopping list:  %.2lf grams of main ingredient.\n", ingredient_amount);
                       printf("--------------------------------------------------\n");
                       break;
                }

            case 4:
                {
                    double cost_per_kg, dish_cost, per_head;


                    if (code == 101)
                        cost_per_kg = 450.00;
                    else if (code == 102)
                        cost_per_kg = 500.00;
                    else
                        cost_per_kg = 250.00;

                    dish_cost = (ingredient_amount / 1000.0) * cost_per_kg;
                    per_head  = dish_cost / guest;
                    count++;
                    grand_total += dish_cost;

                    printf("--------------------------------------------------\n");
                    printf("Dish cost      : %.2lf\n", dish_cost);
                    printf("Guests         : %d\n", guest);
                    printf("Cost per head  : %.2lf\n", per_head);
                    printf("--------------------------------------------------\n");
                    break;
                }
            case 5:
                {
                    printf("--------------------------------------------------\n");
                    printf("            ORDER SUMMARY\n");
                    printf("--------------------------------------------------\n");

                    if (count == 0)
                    {
                        printf("No orders recorded yet.\n");
                    }
                    else
                    {
                        printf("Total records : %d\n", count);
                        printf("Grand total   : %.2lf\n", grand_total);
                    }
                    break;
            case 6: printf("THANK YOU FOR USING THE PROGRAM!!GOODBYE!\n");  break;
            default: printf("Invalid choice.\n");



       }
    }
    }
    while(n != 6);

    return 0;
}
