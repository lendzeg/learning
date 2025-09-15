/*
Nelson Rodriguez
2025-04-06
================


Activity: Arrays and functions
==============================

Within this program, we will pass an array with 6 integers to a function, have the function swap 
the first and last integer, the second and the second to last integer, the third and the third to last integer.

The function is called reverseArray and doesn't return anything (void). 
It should take one parameter, representing the array of integers. 

The main function first reads 6 integers from the input, and assigns them to the array. 
The main function then calls reverseArray, passing the array as an argument.

The main function then prints the reversed array.
*/

#include <stdio.h>
void reverseArray(int *);
int main(void){
    int arr[6];
    for(int i=0; i<6; i++){
        scanf("%d", &arr[i]);
    }
    reverseArray(arr);
    for(int i=0; i<6; i++){
        printf("%d ", arr[i]);
    }
}
void reverseArray(int * ptr){
    int tmp;
    for(int j=0; j<3; j++){
        tmp = * (ptr + j); // 0, 1, 2
        * (ptr + j) = * (ptr + 5 - j); // 5, 4, 3
        * (ptr + 5 - j) = tmp;
    }
}