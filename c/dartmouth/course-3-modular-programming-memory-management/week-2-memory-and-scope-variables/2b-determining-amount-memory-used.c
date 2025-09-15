/*
Nelson Rodriguez
2025-04-03
================


Activity: Programming a toaster (memory usage nicely displayed)
===============================================================

You are programming a toaster! The toaster does not have a lot of memory, 
so you need to be careful about the data types you use (remember that 
different data types use different amounts of memory). To make this easier, 
you'd like an easy way to track how much memory your variables are going to use.

Your job is to write a program that shows, in human-readable form 
(see below for specifics), how much memory a set of variables of a certain 
type will use. Your program should read a character that identifies 
the data type ('i' for int, 's' for short, 'c' for char, 'd' for double). 
Next it should read an integer that indicates how many variables of the 
given type you wish to store.

Your program should then calculate the amount of memory required to store 
the given variables. Your program needs to be written in such a way that 
it would also perform correctly on other computers. In other words, 
rather than hard-coding specific sizes for the different variable types, 
your program needs to use the "sizeof()" function to determine how much 
memory an individual variable of a given type needs.

Finally, you need to output the amount of space required by your variables 
to the screen. You need to make sure you provide this output in a form that 
is easy to read for humans.
*/


#include <stdio.h>

int main(void){
    
    int n=0, size=0;
    char type;
    scanf("%c%d", &type, &n);
    
    if (type == 'i') size = sizeof(int);
    else if (type == 's') size = sizeof(short);
    else if (type == 'c') size = sizeof(char);
    else if (type == 'd') size = sizeof(double);
    
    int r=0, unit=0;
    int B=0, KB=0, MB=0, GB=0;
    n = n * size;
    
    while(n != 0){
        r = n % 1000;
        n = n / 1000;
        unit += 1;
        if (unit == 1) B = r;
        else if (unit == 2) KB = r;
        else if (unit == 3) MB = r;
        else if (unit == 4) GB = r;
    }
    
    if (unit == 1) printf("%d B", B);
    else if (unit == 2) printf("%d KB and %d B", KB, B);
    else if (unit == 3) printf("%d MB and %d KB and %d B", MB, KB, B);
    else if (unit == 4) printf("%d GB and %d MB and %d KB and %d B", GB, MB, KB, B);
    
}