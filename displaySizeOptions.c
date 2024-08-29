// display_size_options.c

#include "cofee.h"

void display_size_options(Beverage *beverage) {
    printf("\n%s: %s\n", beverage->name, beverage->description);
    printf("%s Sizes:\n", beverage->name);
    printf("s. Small   - Rs %.2f\n", beverage->small_price);
    printf("m. Medium  - Rs %.2f\n", beverage->medium_price);
    printf("l. Large   - Rs %.2f\n", beverage->large_price);
}
