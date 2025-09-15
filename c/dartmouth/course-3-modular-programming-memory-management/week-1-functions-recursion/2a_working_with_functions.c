/*
Nelson Rodriguez
2025-03-27
================


Activity: Program a smart unit converter
========================================

Write a C-program that converts metric measurements to imperial system values. 
Measurements are provided to your program in meters, grams or degrees Celsius and 
must be converted to feet, pounds and degrees Fahrenheit, respectively. 
Here are the conversion rules to use:

1 meter = 3.2808 feet;
1 gram = 0.002205 pounds;
temperature in degrees Fahrenheit = 32 + 1.8 × temperature in degrees Celsius.

On the first input line you are given the number of conversions to be made. 
Each of the following lines contains a value to be converted as well as its unit: 
m, g or c (for meters, grams or degrees Celsius). There will be a space between 
the number and the unit. You should print your output value for each input line 
immediately after calculating it (ie, you do not have to wait until you have read all inputs).

Display the converted values with 6 decimal places, followed by a space and 
their unit: ft, lbs or f (for feet, pounds or degrees Fahrenheit). 
Each conversion result should be printed on its own line, and you should store and 
display all decimal values as doubles.
*/

#include <stdio.h>

double meter_feet(double);
double gram_pounds(double);
double celsius_fahrenheit(double);

int main(void){
    
    int n=0;
    scanf("%d", &n);
    
    double quantity;
    char unit;
    
    for(int i=0; i<n; i++){
        scanf("%lf %c", &quantity, &unit);
        
        if(unit == 'm') {
            quantity = meter_feet(quantity);
            printf("%lf ft\n", quantity);
        }
        else if(unit == 'g') {
            quantity = gram_pounds(quantity);
            printf("%lf lbs\n", quantity);
        }
        else if(unit == 'c'){
            quantity = celsius_fahrenheit(quantity);
            printf("%lf f\n", quantity);
        }
        
    }
    return 0;
}

double meter_feet(double m){
    return m * 3.2808;
}

double gram_pounds(double g){
    return g * 0.002205;
}

double celsius_fahrenheit(double c){
    return 32 + 1.8 * c;
}