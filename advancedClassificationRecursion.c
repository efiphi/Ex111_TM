#include "NumClass.h"

int countDigits(int);

int isArmstrongRecursive(int, int);

int power(int,int);

int isPalindromeRecursive(int, int, int);

int isPalindromeRecursive(int n, int originalNumber, int reversedNumber){
    if(n==0){
        return (reversedNumber == originalNumber)? 1 : 0;
    }
    int digit = n%10;
    reversedNumber = reversedNumber * 10 + digit;

    return isPalindromeRecursive(n/10, originalNumber, reversedNumber);

}

int isPalindrome(int n){
    return isPalindromeRecursive(n,n,0);
}
// Function to check if a number is an Armstrong number using recursion
int countDigits(int n) {
    return (n == 0) ? 0 : 1 + countDigits(n / 10);
}

int power(int base, int exponent){
    return (exponent==0) ? 1 : base* power(base, exponent-1);
}

int isArmstrongRecursive(int n, int numDigits) {
    // Base case: single-digit numbers are Armstrong numbers
    if (n == 0)
        return 0;

    int digit = n % 10;
    return power(digit, numDigits) + isArmstrongRecursive(n / 10, numDigits);
}

int isArmstrong(int n) {
    int numDigits = countDigits(n);
    return (n == isArmstrongRecursive(n, numDigits)) ? 1 : 0;
}