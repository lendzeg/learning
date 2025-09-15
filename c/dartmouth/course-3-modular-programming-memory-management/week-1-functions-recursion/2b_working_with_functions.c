/*
Nelson Rodriguez
2025-03-28
================

Activity: Find the smallest number
==================================
The goal of this problem is to find the smallest integer in a list of numbers.
To help you with this task, please write a function called min() that finds and 
returns the smallest amongst two integers (be sure to also write a prototype 
for this function). The function thus takes two integers as input and returns 
the smallest of the two. This function will use an if statement with a condition 
that contains either "less than" or "greater than".

Next, please use min() in your main function to work your way through an entire 
list of numbers in order to find its minimum. The first number you read gives 
the number of elements in the list of integers under consideration. 

You will then read the integer values, using min() to keep only the smallest 
integer read at each step. In the end, please print out the smallest integer in the list.
*/

#include <stdio.h>

int min(int, int); // Prototype

int main(void){
    
    int n; // array dimension
    scanf("%d", &n);
    
    int array[n];
    for(int i=0; i<n; i++){
        scanf("%d", &array[i]); // enter elements
    }
    
    int minVal = array[0]; // assume first array element as minimum
    
    for(int i=1; i<n; i++){
        minVal = min(minVal,array[i]);
    }
    
    printf("%d", minVal);
    return 0;
}

int min(int a, int b){ // Definition
    if(a < b) return a;
    else return b;
}