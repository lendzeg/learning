/*
Nelson Rodriguez
2025-03-12
================

Activity: use a for-loop to print a line multiple times
=======================================================

You would like to display the same line of text several times, 
but you do not wish to have to type it multiple times in your program.

Please print the following text to the screen:

C is fun!
C is fun!
C is fun!

To make this a bit more challenging, you are only allowed to use one single "printf" statement, 
and you are not allowed to repeat text inside your printf statement.

Warning: Your output needs to look exactly like the above output.

Note:

You may submit as many solutions as you wish. Only your highest score will be kept.

Remember to declare the variable used in the loop outside the loop in this quiz. 
So if using variable i, declare that it is an integer before starting the loop. 
This is only so that the grader grades you correctly for this quiz. 
As you move on with the quizzes in this course you will be able to compress the code
by declaring int within the loop itself.
*/

#include <stdio.h>
int main(void){
    int i = 0;
    for(i=0; i<3; i++){
        printf("C is fun!\n");
    }
    return 0;
}