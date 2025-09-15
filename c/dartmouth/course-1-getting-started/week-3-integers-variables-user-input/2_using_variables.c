/*
Nelson Rodriguez
2025-03-12
================

Activity: assign, re-assign, and update a variable
==================================================
*/

#include <stdio.h>

int main(void){
    int pollution = 0;
    pollution = 34;
    printf("%d\n", pollution);

    pollution = pollution + 34;
    printf("%d\n", pollution);

    pollution = pollution - 8;
    pollution = pollution - 20;
    printf("%d\n", pollution);

    pollution = 10;
    pollution = pollution + 12;
    printf("%d\n", pollution);
}