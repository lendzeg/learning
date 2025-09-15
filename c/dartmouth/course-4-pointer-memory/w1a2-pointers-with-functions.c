// Exercise 1:

#include <stdio.h>
 
void swap (char *x, char *y); 
int main(void) {
    char c = 'P';
    char d = 'T';
    printf("%c%c ", c, d); // PT
    swap(&c, &d);
    printf("%c%c", c, d); // TP
    return 0;
}

void swap (char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Exercise 2:

#include <stdio.h>
void myFunction(int *p, int *q);

int main(void) {
    int i = 1;
    int j = 2;
    myFunction(&i, &j);
    printf("%d %d \n", i, j); // 2 3
    myFunction(&i, &j);
    printf("%d %d \n", i, j); // 3 5
    myFunction(&i, &j);
    printf("%d %d \n", i, j); // 5 8
    return 0;
}

void myFunction(int *p, int *q) {
    int tmp;
    tmp = *p; 
    *p = *q; 
    *q = tmp + *q;
}