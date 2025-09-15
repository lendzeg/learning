/*
Nelson Rodriguez
2025-03-18
================

Activity: branch inside a loop, how many big cities?
====================================================
You want to determine the number of cities in a given region that have 
a population strictly greater than 10,000. To do this, you write a program 
that first reads the number of cities in a region as an integer, and then 
the populations for each city one by one (also integers).
*/

#include <stdio.h>

int main(void){
    
    int cities, population, bigCity=0;
    scanf("%d", &cities);
    
        for(int i=0; i<cities; i++){
        scanf("%d", &population);
        if(population > 10000){
            bigCity += 1;
        }
    }
    
    printf("%d", bigCity);
    
    return 0;
}