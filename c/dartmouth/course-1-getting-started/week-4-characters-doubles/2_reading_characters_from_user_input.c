/*
Nelson Rodriguez
2025-03-13
===================

Activity: read characters
=========================

Write a C-program that reads an input character (using scanf) and displays 
the following pyramid pattern using the character read: 

Examples:

Input
#

Output
++++#++++
+++###+++
++#####++
+#######+
#########

Input
o

Output
++++o++++
+++ooo+++
++ooooo++
+ooooooo+
ooooooooo
*/

#include <stdio.h>

int main(void){
    char x;
    scanf("%c\n", &x);
    printf("++++%c++++\n", x);
    printf("+++%c%c%c+++\n",x,x,x);
    printf("++%c%c%c%c%c++\n",x,x,x,x,x);
    printf("+%c%c%c%c%c%c%c+\n",x,x,x,x,x,x,x);
    printf("%c%c%c%c%c%c%c%c%c\n",x,x,x,x,x,x,x,x,x);
}