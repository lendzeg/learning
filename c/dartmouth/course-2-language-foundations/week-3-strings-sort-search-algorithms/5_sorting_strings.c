/*
Nelson Rodriguez
2025-03-20
================

Activity: is there a 't' in this word?
======================================

You are conducting a linguistic study and are interested in finding words 
that contain the letter 't' or 'T' in the first half of the word 
(including the middle letter if there is one). Specifically, if the first 
half of the word does contain a 't' or a 'T', your program should output a 1. 
If the first half does not contain the letter 't' or 'T', but the second half does, 
then your program should output a 2. Otherwise, if there is no 't' or 'T' in the word at all, 
your program's output should be -1. You may assume that the word entered does not have more than 50 letters.
*/

#include <stdio.h>

int main(void){
    
    char word[51];
    scanf("%s", word);
    
    int l=0; // to track the character
    int type=0; // the word type 1 2 or -1
    
    while(word[l] != '\0') l++; // calculates the word length
    
    // Finding the index where the first half ends
    int middle;
    if (l%2==0) middle = l/2-1; 
    else middle = l/2;
    
    
    // finding or not the index of t or T in the word
    int i=0;
    while('t' != word[i] && 'T' != word[i] && i<l) i++;
    
    if(i<=middle){
        printf("%d", 1);
    } else if(i<l){
        printf("%d", 2);
    } else {
        printf("%d", -1);
    }
    
    return 0;
}