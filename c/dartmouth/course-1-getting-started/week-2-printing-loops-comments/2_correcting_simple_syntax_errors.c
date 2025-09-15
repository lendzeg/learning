/*
Nelson Rodriguez
2025-03-12
================

Activity: correct simple syntax errors
======================================

We already need you! Our full-time developer went on sick leave, 
leaving us with an erroneous C-program without telling us how to fix it. 
All we have are the compiler error messages produced by this code.
Please help us fix this code. Here is the program in question:

----------------------------------------------------------
#include <stdio.h>

int main(void) {
    printf ("This is code with errors: ")
    printf "Fix them!";
    return 0;
}
----------------------------------------------------------

And here are the compiler error messages:

----------------------------------------------------------
/user-input:4:43: error: expected ';' after expression
    printf ("This is code with errors : ")
                                          ^
                                          ;
/user-input:5:11: error: expected ';' after expression
    printf "Fix them!";
          ^
          ;
/user-input:5:5: warning: expression result unused
    printf "Fix them!";
    ^~~~~~
/user-input:5:12: warning: expression result unused
    printf "Fix them!";
          ^~~~~~~~~~~  
----------------------------------------------------------

Warning: We cannot allow additional errors. 
You are therefore not allowed to write new code or remove code. 
You only need to correct the errors in the given code.
*/

#include <stdio.h>

int main(void) {
    printf ("This is code with errors: ");
    printf ("Fix them!");
    return 0;
}

