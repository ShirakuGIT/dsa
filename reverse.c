#include <stdio.h>

int reverse(int number, int rev) {
    if (number == 0) 
        return rev;
    return reverse(number / 10, rev * 10 + number % 10);
}

int main() {
    int number = 12345;
    int reversedNumber = reverse(number, 0);
    printf("Original: %d, Reversed: %d\n", number, reversedNumber);
    return 0;
}
