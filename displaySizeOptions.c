#include "cofee.h"
void displaySizeOptions(const char *beverage, float smallPrice, float mediumPrice, float largePrice)
{
    printf("\n%s Sizes:\n", beverage);
    printf("s. Small   - Rs %.2f\n", smallPrice);
    printf("m. Medium  - Rs %.2f\n", mediumPrice);
    printf("l. Large   - Rs %.2f\n", largePrice);
    printf("Enter size choice (s/m/l): ");
}
