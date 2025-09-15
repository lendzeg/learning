/*
Nelson Rodriguez
2025-03-18
================

Activity: print a square of starts using nested loops
=====================================================

Create a program that displays on the screen a square of n x n stars, 
with the integer n given as an input.
*/

#include <stdio.h>

int main(void){
    
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}