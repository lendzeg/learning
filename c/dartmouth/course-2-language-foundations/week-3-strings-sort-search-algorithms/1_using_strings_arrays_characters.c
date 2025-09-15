/*
Nelson Rodriguez
2025-03-19
================

Activity: repeat a word read from the user input
================================================

Write a C-program that prints out a word as many times as specified. 
The number of repetitions and the word should be given as input to the program. 
You may assume that the word has no more than 100 characters 
(be sure to also reserve space for the null terminator, \0, though!).
*/

#include <stdio.h>

int main(void){
    int times=0;
    scanf("%d", &times);
    
    char word[101]; 
    scanf("%s", word); // Remember: In scanf, string don't use ampersand
    
    for(int i=0; i<times; i++){
        printf("%s\n", word);
    }
    
    return 0;
}