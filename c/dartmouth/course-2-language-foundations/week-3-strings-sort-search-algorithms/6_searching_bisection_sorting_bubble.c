/*
Nelson Rodriguez
2025-03-20
================

Activity: Activity: find repeat letters in a word
=================================================

You are still conducting linguistic research! This time, you'd like to write a program 
to find out how many letters occur multiple times in a given word. Your program should 
read a word from the input and then sort the letters of the word alphabetically 
(by their ASCII codes). Next, your program should iterate through the letters of the word 
and compare each letter with the one following it. If these equal each other, you increase 
a counter by 1, making sure to then skip ahead far enough so that letters that occur more 
than twice are not counted again. You may assume that the word you read from the input has 
no more than 50 letters, and that the word is all lowercase.
*/

#include <stdio.h>

int main() {
    char word[51];  // Assuming the word has no more than 50 letters + 1 for null terminator
    int count = 0;

    scanf("%s", word);

    int length = 0;
    while (word[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (word[j] > word[j + 1]) {
                char temp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < length - 1; i++) {
        if (word[i] == word[i + 1]) {
            count++;
            while (word[i] == word[i + 1]) { // to skip consecutive duplicates
                i++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}