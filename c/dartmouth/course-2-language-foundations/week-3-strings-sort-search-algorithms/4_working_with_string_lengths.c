/*
Nelson Rodriguez
2025-03-20
================

Activity: Find the longest word in a text
=========================================

Your job is to find the length of the longest word in a text with no punctuation or 
special characters of any kind - only contains words. To do so, please write a C-program 
that takes as a input first the number of words in a text, followed by all of the words in the text. 
The output of your program should be the length of the longest word in the text.

To simplify your program, you can assume that the longest word will not exceed 100 characters.
*/

#include <stdio.h>

int main(void){
    
    int words=0; // enter number of words
    scanf("%d", &words);
    
    char word[101];
    int j=0; // to count and move through word characters 
    int max=0;
    
    for (int i=0; i<words; i++){
        scanf("%s", word); // enter the word
        j=0; // to star from the beginning with each new word
        while(word[j] != '\0'){
            j++;
        }
        if (j>max){
            max = j;
        }
    }
    
    printf("%d", max);
}