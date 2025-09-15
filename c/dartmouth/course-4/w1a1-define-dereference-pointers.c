#include <stdio.h>
 
int main(void) {
    int i;
    int *iAdr = &i;
 
    *iAdr = 10;
 
    printf(" i = %d\n", i); // 10
    printf(" *iAdr = %d\n", *iAdr); // 10
 
    *iAdr = *iAdr - 2;
    printf(" i = %d\n", i); // 8
    printf(" *iAdr = %d\n", *iAdr); // 8
 
    (*iAdr) += 1;
    printf(" i = %d\n", i); // 9
    printf(" *iAdr = %d\n", *iAdr); // 9    
 
    return 0;
}