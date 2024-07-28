// process_choice.c

#include <stdio.h>
#include <stdlib.h>
#include "coffee.h"

void log_choice_to_file(Beverage beverage, int cups) {
    FILE *file = fopen("beverage_log.txt", "a"); // Open file for appending
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "Beverage: %s, Size: %c, Sugar: %c, Cups: %d, Total Price: Rs%.2f\n",
            beverage.name, beverage.size_choice, beverage.sugar_choice, cups, beverage.price * cups);
    fclose(file);
}

void view_transaction_history() {
    FILE *file = fopen("beverage_log.txt", "r"); // Open file for reading
    if (file == NULL) {
        printf("No transaction history available.\n");
        return;
    }

    printf("\nTransaction History:\n");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

int get_valid_integer_input(const char *prompt) {
    int value;
    char term;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d%c", &value, &term) != 2 || term != '\n') {
            while (getchar() != '\n'); // Clear invalid input
            printf("Invalid input. Please enter a valid integer.\n");
        } else {
            break;
        }
    }
    return value;
}

char get_valid_char_input(const char *prompt, const char *valid_choices) {
    char choice;
    int valid = 0;
    while (!valid) {
        printf("%s", prompt);
        scanf(" %c", &choice);
        while (getchar() != '\n'); // Clear remaining input
        for (int i = 0; valid_choices[i] != '\0'; i++) {
            if (choice == valid_choices[i]) {
                valid = 1;
                break;
            }
        }
        if (!valid) {
            printf("Invalid choice. Please enter one of the following: %s\n", valid_choices);
        }
    }
    return choice;
}

float get_valid_float_input(const char *prompt) {
    float value;
    char term;
    while (1) {
        printf("%s", prompt);
        if (scanf("%f%c", &value, &term) != 2 || term != '\n') {
            while (getchar() != '\n'); // Clear invalid input
            printf("Invalid input. Please enter a valid amount.\n");
        } else {
            break;
        }
    }
    return value;
}

void process_choice(Beverage *beverages, int choice) {
    display_size_options(beverages[choice - 1]);

    beverages[choice - 1].size_choice = get_valid_char_input("Enter size choice (s/m/l): ", "sml");

    // Determine price based on size
    switch (beverages[choice - 1].size_choice) {
        case 's':
            printf("You selected Small %s.\n", beverages[choice - 1].name);
            beverages[choice - 1].price = beverages[choice - 1].small_price;
            break;
        case 'm':
            printf("You selected Medium %s.\n", beverages[choice - 1].name);
            beverages[choice - 1].price = beverages[choice - 1].medium_price;
            break;
        case 'l':
            printf("You selected Large %s.\n", beverages[choice - 1].name);
            beverages[choice - 1].price = beverages[choice - 1].large_price;
            break;
    }

    // If valid price is chosen, proceed with cup count and confirmation
    int cups = get_valid_integer_input("Enter the number of cups: ");
    while (cups <= 0) {
        printf("Invalid number of cups. Please enter a positive integer.\n");
        cups = get_valid_integer_input("Enter the number of cups: ");
    }

    // Check for sugar preference if Coffee or Tea is selected
    if (choice == 1 || choice == 2) {
        beverages[choice - 1].sugar_choice = get_valid_char_input("Do you want sugar? (y/n): ", "yn");
        printf("You selected %s with %s.\n", beverages[choice - 1].name,
               (beverages[choice - 1].sugar_choice == 'y') ? "sugar" : "no sugar");
    } else {
        beverages[choice - 1].sugar_choice = 'n'; // Default for non-sugar drinks
    }

    float total_price = beverages[choice - 1].price * cups;
    printf("Total Price for %d cups: Rs%.2f\n", cups, total_price);

    char confirm_choice = get_valid_char_input("Do you want to confirm this choice? (y/n): ", "yn");

    if (confirm_choice == 'y') {
        printf("Selection confirmed.\n");

        // Payment process
        float payment = 0.0;
        while (payment < total_price) {
            payment = get_valid_float_input("Enter payment amount: Rs ");
            if (payment < total_price) {
                printf("Insufficient payment. Please enter at least Rs %.2f.\n", total_price);
            }
        }

        // Display change if any
        if (payment > total_price) {
            printf("Payment accepted. Your change is Rs %.2f.\n", payment - total_price);
        } else {
            printf("Payment accepted. No change.\n");
        }

        log_choice_to_file(beverages[choice - 1], cups); // Log the choice to a file
    } else {
        printf("You chose to correct your selection.\n");
    }
}
