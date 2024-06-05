#include <stdio.h>
#include "cofee.h"
#include "displaymenu.c"
#include "displaySizeOptions.c"
#include "processChoice.c"
int main()
{
    int choice;
    char continue_choice;
    char confirm_choice;
    float price;

    do
{
        displayMenu();
        scanf("%d", &choice);
        processChoice(choice, &price);

        // Display price and ask for confirmation
        if (price > 0.0)
        {
            printf("Price: Rs%.2f\n", price);
            printf("Do you want to confirm this choice? (y/n): ");
            scanf(" %c", &confirm_choice);
            if (confirm_choice != 'y' && confirm_choice != 'Y')
            {
                printf("You chose to correct your selection.\n");
                continue;
            }
        }

        // Ask if user wants to continue
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &continue_choice);
    }
    while(continue_choice == 'y' || continue_choice == 'Y');

    printf("Exiting the vending machine.\n");

    return 0;
}
