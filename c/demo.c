#include <stdio.h>

void sum (int *array);

int main(){
    char array[] = "Hello, world!";
    for (int i=0; array[i] != '\0'; i++){
        printf("%c", array[i]);
    }
    return 0;
}

void sum (int *array){
    int total = 0;
    for (int i = 0; array[i] != '\0'; i++){
        total += array[i];
    }

    


