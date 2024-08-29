// main.c
#include <stdio.h>
#include <stdlib.h>
#include "cofee.h"
#include "displaymenu.c"
#include "displaySizeOptions.c"
#include "processChoice.c"


int main() {
    int choice;
    char continue_choice;

    // Create an array of beverages
    Beverage *beverages = (Beverage *)malloc(5 * sizeof(Beverage));

    // Initialize the beverages
    beverages[0].name = "Coffee";
    beverages[0].description = "A hot drink made from roasted coffee beans.";
    beverages[0].small_price = 30.0;
    beverages[0].medium_price = 40.0;
    beverages[0].large_price = 50.0;

    beverages[1].name = "Tea";
    beverages[1].description = "A soothing hot drink made from cured or fresh tea leaves.";
    beverages[1].small_price = 25.0;
    beverages[1].medium_price = 35.0;
    beverages[1].large_price = 45.0;

    beverages[2].name = "Soda";
    beverages[2].description = "A refreshing carbonated soft drink.";
    beverages[2].small_price = 20.0;
    beverages[2].medium_price = 30.0;
    beverages[2].large_price = 40.0;

    beverages[3].name = "Apple Juice";
    beverages[3].description = "A sweet beverage made from pressed apples.";
    beverages[3].small_price = 35.0;
    beverages[3].medium_price = 45.0;
    beverages[3].large_price = 55.0;

    beverages[4].name = "Lassi";
    beverages[4].description = "A traditional yogurt-based drink from India.";
    beverages[4].small_price = 40.0;
    beverages[4].medium_price = 50.0;
    beverages[4].large_price = 60.0;

    do {
        display_menu();
        choice = get_valid_integer_input("Enter your choice: ");
        if (choice == 7) {
            printf("Thank you for using the vending machine.\n");
            free(beverages); // Free the allocated memory
            return 0;
        }
        process_choice(choice, beverages);

        // Ask if user wants to continue
        continue_choice = get_valid_char_input("\nDo you want to continue? (y/n): ", "yn");

    } while (continue_choice == 'y');

    printf("Thank you for using the vending machine.\n");
    free(beverages); // Free the allocated memory

    return 0;
}
