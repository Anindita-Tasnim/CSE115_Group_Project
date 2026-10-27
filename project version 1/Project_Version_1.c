#include <stdio.h>
int main (void)
{
    printf("=============================================\n");
    printf("    Catering Order and Recipe Scaling     \n");
    printf("=============================================\n");
    printf("\n");
    printf("MENU:\n");
    printf("1. Add a dish to the order\n");
    printf("2. Scale a recipe\n");
    printf("3. Build shopping list\n");
    printf("4. Cost per head\n");
    printf("5. Search by dish\n");
    printf("6. Save & load\n");
    printf("7. Exit\n");
    printf("\n");


    printf("CURRENT ORDER\n");
    printf("--------------------------------------------------------------------------------");
    printf("\n");
    printf("%-8s%-20s%-15s%-15s%10s%12s", "Code", "Name", "Serving", "Main Ingredient", "Cost/kg","Guests\n" );
    printf("--------------------------------------------------------------------------------\n");
    printf("%-8s%-20s%-15s%-15s%10s%12s", "101", "Chicken Biryani", "8", "250 g", "450.00", "140\n");
    printf("%-8s%-20s%-15s%-15s%10s%12s", "102", "Beef Korma", "8", "300 g", "500.00", "140\n");
    printf("%-8s%-20s%-15s%-15s%10s%12s", "103", "Vegetable Pulao", "8", "200 g", "250.00", "140\n");
    printf("\n");

    return 0;
}
