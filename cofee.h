
#ifndef MAIN_H_INCLUDED // Header guard to prevent multiple inclusions
#define MAIN_H_INCLUDED // Define to mark the start of the header file
#include<stdio.h>

void displayMenu();
void displaySizeOptions(const char *beverage, float smallPrice, float mediumPrice, float largePrice);
void processChoice(int choice, float *price);
#endif
