#include "cofee.h"
void processChoice(int choice, float *price)
{
    char size_choice;
    switch (choice)
{
        case 1:
            displaySizeOptions("Coffee", 30.0, 40.0, 50.0);
            scanf(" %c", &size_choice);
            switch (size_choice)
{
                case 's':
                    printf("You selected Small Coffee.\n");
                    *price = 30.0;
                    break;
                case 'm':
                    printf("You selected Medium Coffee.\n");
                    *price = 40.0;
                    break;
                case 'l':
                    printf("You selected Large Coffee.\n");
                    *price = 50.0;
                    break;
                default:
                    printf("Invalid size choice. Please enter 's', 'm', or 'l'.\n");
                    *price = 0.0;
}
            break;
        case 2:
            displaySizeOptions("Tea", 25.0, 35.0, 45.0);
            scanf(" %c", &size_choice);
            switch (size_choice)
{
                case 's':
                    printf("You selected Small Tea.\n");
                    *price = 25.0;
                    break;
                case 'm':
                    printf("You selected Medium Tea.\n");
                    *price = 35.0;
                    break;
                case 'l':
                    printf("You selected Large Tea.\n");
                    *price = 45.0;
                    break;
                default:
                    printf("Invalid size choice. Please enter 's', 'm', or 'l'.\n");
                    *price = 0.0;
}
            break;
        case 3:
            displaySizeOptions("Soda", 20.0, 30.0, 40.0);
            scanf(" %c", &size_choice);
            switch (size_choice)
{
                case 's':
                    printf("You selected Small Soda.\n");
                    *price = 20.0;
                    break;
                case 'm':
                    printf("You selected Medium Soda.\n");
                    *price = 30.0;
                    break;
                case 'l':
                    printf("You selected Large Soda.\n");
                    *price = 40.0;
                    break;
                default:
                    printf("Invalid size choice. Please enter 's', 'm', or 'l'.\n");
                    *price = 0.0;
}
            break;
        case 4:
            printf("Exiting the vending machine.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            *price = 0.0;
}
}
