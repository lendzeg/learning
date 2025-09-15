/*
Nelson Rodriguez
2025-03-12
================

Activity: read an integer and print the corresponding multiplication table
==========================================================================

n this activity, you want to improve your existing multiplication program (that prints the 8 times table). 
Your program should read an integer from the user (not you) and print the multiplication table 
for the number that they enter. To test if your program works, we will try running your code with several 
different inputs so make sure you don't hard code the solution.

Example 1

Input:
8
Output:
0x8 = 0
1x8 = 8
...
10x8 = 80

Example 2

Input:
5
Output:
0x5 = 0
1x5 = 5
...
10x5 = 50

Warning: You will be graded on your output, so do not include any print statements that prompt a user for input.
*/

#include <stdio.h>

int main(void){
    int number;
    int i;
    int product = 0;
    
    scanf("%d", &number);
    
    for(i = 0; i < 11; i++){
        printf("%dx%d = %d\n", i, number, product);
        product = product + number;
    }
    
    return 0;
}