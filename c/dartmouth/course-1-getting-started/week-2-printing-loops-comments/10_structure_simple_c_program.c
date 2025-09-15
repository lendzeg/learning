/*
Nelson Rodriguez
2025-03-12
==================

Activity: put lines in the correct order
========================================

Please arrange the following program segments in the correct order 
so that it prints "I love love love programming!"

Then use comments to label the pieces of the program (preprocessor directive, 
variable declaration, executable statement, return statement, main function).
*/

// preprocessor directive
#include <stdio.h>

// main function
int main(void){
    
    // variable declaration
    int i;
    
    // executable statement
    printf("I ");

    for(i = 0; i < 3 ; i++) {
        printf("love ");
    }
    printf("programming!");
    
    // return statement
    return(0);
    
}