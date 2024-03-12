#include "NumClass.h"


// Function to check if a number is an Armstrong number
int isArmstrong(int n) {
    int originalNumber = n;
    int numDigits =0;
    int sum = 0;

    int temp = n;
    while (temp>0){
        temp/=10;
        ++numDigits;
        
    }


    
    temp=n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, numDigits);
        temp /= 10;
    }

    return (sum == originalNumber) ? 1 : 0;
}

int isPalindrome(int n) {
    int originalNumber = n;
    int reversedNumber = 0;

    while (n > 0) {
        int digit = n % 10;
        reversedNumber = reversedNumber * 10 + digit;
        n /= 10;
    }

    return (reversedNumber == originalNumber) ? 1 : 0;
}
