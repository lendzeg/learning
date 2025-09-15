int main(){

    int numbers[] = {4, -1, 8, 3, 0, -11}; 
    *(numbers+4); // 0

    int numbers[] = {4, -1, 8, 3, 0, -11};
    *numbers+4; // 8

    int numbers[] = {4, -1, 8, 3, 0, -11};
    numbers[10]; // Random and depends on what was stored in memory here before.

    int numbers[] = {4, -1, 8, 3, 0, -11};
    int *ptr;
    ptr = numbers + 2;
    ptr++;
    *ptr; // 3

}