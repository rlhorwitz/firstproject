#include <stdio.h>
#include <cs50.h>

int main(void) {

    int height;

    // Do-While Loop
    do {
        printf("Height: ");
        height = get_int();
    } while ( height < 0 || height > 23);
    // For loop to print the pyramids
    for (int i = 1; i <= height; i++) {
        for (int p = 1; p <= height - i; p++ ) {
            printf(" ");
        }
        for (int h = 1; h <= i + 1; h++) {
            printf("#");
        }
        printf("  ");
        for (int s = 1; s <= i + 1; s++) {
            printf("#");
        }
        printf("\n");
    }
}

