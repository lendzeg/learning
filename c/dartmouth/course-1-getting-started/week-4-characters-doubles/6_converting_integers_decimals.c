/*
Nelson Rodriguez
2025-03-13
==================

Activity: convert integers to doubles
========================================

You are helping a teacher average grades. 
You get bored computing averages by hand, so you decide to write a computer program to do the work for you.

Your program must first read an integer indicating the number of grades to be averaged. 
Next, your program will read the grades one by one, all of which are integers as well. 
Finally, your program will calculate and print the average of the grades to two decimal places.
*/

#include <stdio.h>

int main(void) {
    int numGrades;
    scanf("%d", &numGrades);

    int sum = 0;
    int grade;

    for (int i = 0; i < numGrades; i++) {
        scanf("%d", &grade);
        sum += grade;
    }

    double average = (double)sum / numGrades;
    printf("%.2lf\n", average);

    return 0;
}