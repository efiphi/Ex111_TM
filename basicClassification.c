#include "NumClass.h"

int factorial(int);

int isPrime(int n){
    if (n < 1) {
        return 0;  
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return 0;  // If n is divisible by any number between 2 and sqrt(n), it's not prime
        }
    }

    return 1;  // If no divisors were found, the number is prime
}

int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

// Function to check if a number is a strong number
int isStrong(int n) {
    int originalNumber = n;
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        int factorial=1;

        for(int i=1;i<=digit; ++i){
            factorial*=i;
        }
        sum+= factorial;
        n/=10;
    }

    return (sum == originalNumber) ? 1 : 0;
}