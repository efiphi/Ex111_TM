#include <stdio.h>
#include <stdbool.h>
#include "NumClass.h"

int main(){
    int start, end;

    printf("Enter the start number: ");
    scanf("%d", &start);

    printf("Enter the end number: ");
    scanf("%d", &end);

    // Validate input
    if (start > end) {
        printf("Invalid input: Start number should be less than or equal to the end number.\n");
        return 1;
    }

    printf("The Armstrong numbers are: ");
    for (int i = start; i <= end; ++i) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    

    printf("The Palindrome numbers are: ");
    for (int i = start; i <= end; ++i) {
        if (isPalindrome(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    

    printf("The Prime numbers are: ");
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    

    printf("The Strong numbers are: ");
    for (int i = start; i <= end; ++i) {
        if (isStrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    

    

   

    return 0;

    
}