#include <stdio.h>
#include <cs50.h>

int main (void) {

    long long cardnumber;

    // do-while-loop to prompt user to enter cc number
    do {
        printf("Number:");
        cardnumber=get_long_long();
    }

    while (cardnumber < 0);

    // Determine if entry is valid

    int count=0;

    long long digits = cardnumber;
    while (digits > 0)
    {
        digits= digits/10;
        count++;
    }

    if ((count !=13) && (count !=15) && (count != 16)) {
        printf("INVALID\n");
        return 0;
    }

    digits = cardnumber;
    for (int i = 0; i < count - 2; i++) {
        digits /= 10;
    }

    if (digits != 34 && digits != 37 &&
        digits != 51 && digits != 52 &&
        digits != 53 && digits != 54 &&
        digits != 55 && digits / 10 != 4) {
            printf("INVALID\n");
            return 0;
        }
    int first_digits = digits;

    // loop to validate credit card checksum
    int sum = 0;
    digits = cardnumber;
    while (digits > 0){
        int hun = digits % 100;
        int ten = hun / 10;
        int one = hun % 10;
        ten *= 2;

        sum += ten / 10 + ten % 10 + one;
        digits/=100;
    }

    if(sum % 10 != 0) {
        printf("INVALID\n");
    } else if (first_digits == 34 || first_digits == 37) {
        printf("AMEX\n");
    } else if (first_digits / 10 == 4) {
        printf("VISA\n");
    } else {
        printf("MASTERCARD\n");
    }

    return 0;

}