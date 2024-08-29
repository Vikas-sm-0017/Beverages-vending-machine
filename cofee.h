// coffee.h

#ifndef COFEE_H
#define COFEE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for beverages
typedef struct {
    char *name;
    char *description;
    float small_price;
    float medium_price;
    float large_price;
    char size_choice;  // Store size choice as char
    float price;
    char sugar_choice; // Store sugar choice as char
} Beverage;

// Function prototypes
void log_choice_to_file(Beverage beverage, int cups);
void view_transaction_history();
int get_valid_integer_input(const char *prompt);
char get_valid_char_input(const char *prompt, const char *valid_choices);
float get_valid_float_input(const char *prompt);
void display_menu();
void display_size_options(Beverage *beverage);
void process_choice(int choice, Beverage *beverages);

#endif // COFFEE_H
