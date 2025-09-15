/*
Nelson Rodriguez
2025-03-29
================


Activity: Use recursion to compute the sum of digits
====================================================
Please write a C-program that uses a recursive function called "sumOfDigits()" 
to compute the sum of the digits of a number. To do so, your main function should 
first read an integer number as input and then call sumOfDigits(), which should 
in turn call itself until there are no digits left to sum, at which point the final 
sum should display to the user.
*/

#include <stdio.h>

int sumOfDigits(int);

int main(){
    int number, sum;
    scanf("%d", &number);
    sum = sumOfDigits(number);
    printf("%d", sum);
    return 0;
}

int sumOfDigits(int n){
    if (n%10==0) { // stop condition
        // printf("%d", n/10); // to debug
        return n/10;
    }
    else { // next calling
        // printf("%d", n%10); // to debug
        return n%10 + sumOfDigits(n/10);
    }
}