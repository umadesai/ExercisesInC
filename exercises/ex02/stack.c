/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

Stack allocated data

1. What is stack.c intended to do? What would the output be if the program worked as expected?
foo() is intended to create an array of size 5, filled with 42s. It seems like bar() is then intended to modify the arry and fill it with integers 0 -> 4. The output would print each of the values of the size 5 array and return 0.

2. Compile it. Do you get a warning? What does it mean?
I got the warning: function returns address of local variable. It is talking about how foo() tries to return the address of a local array variable. This does not work because a fucntion's local variables get created on the stack and get taken off the stack when you leave the function. So, a local variable can only be used in the function
where it is declared and is not known to outside functions.

3. Run it. What happens? You might get a segmentation fault, or you might get some strange output. Can you explain it? You might find it helpful to draw a stack diagram.
I got the following output:
0x7ffc69c760a0
0x7ffc69c760a0
0
1
2
3
4
It seems like the program printed the address of the array created by foo() and updated by bar(). It then also printed each of the values (0-4) from the modified array, which is what it was supposed to do.


4. Comment out the print statements in foo() and bar() and run it again. What happens now?
With the print statements commented out, I got the following output:
0
0
-1058410880
32748
-1058323152
It seems like removing the print statements fundamentally changed how the program run. The code printed two zeros and then three seemingly random values. I think what happened was that when print statements were around, they contained references to the array that kept the array's allocated space in memory alive. when
those print statements were removed, the references were no longer present and the array must have been cleared from the stack after exiting the local functions. The random outputted values may be what is now found at the old address of the array.


Moral: Don't return pointers to stack allocated data!

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
