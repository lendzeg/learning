/*
Nelson Rodriguez
2028-03-18
================

Activity: array computation
===========================

You plan to make a delicious meal and want to take the money you need to buy the ingredients. 
Fortunately you know in advance the price per pound of each ingredient as well as the exact 
amount you need. The program should read in the number of ingredients 
(up to a maximum of 10 ingredients), then for each ingredient the price per pound. 
Finally your program should read the weight necessary for the recipe 
(for each ingredient in the same order). Your program should calculate 
the total cost of these purchases, then display it with 6 decimal places.
*/

#include <stdio.h>

int main(void){
    
    int ingredients;
    scanf("%d", &ingredients);
    
    double prices[ingredients], weights[ingredients];
    
    for (int i=0; i<ingredients; i++){
        scanf("%lf", &prices[i]);
    }
    
    for (int i=0; i<ingredients; i++){
        scanf("%lf", &weights[i]);
    }
    
    double cost=0;
    
    for (int i=0; i<ingredients; i++){
        cost += prices[i]*weights[i];
    }
    
    printf("%lf", cost);
    
    return 0;
}