/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void test(int test) {
  printf("Address of test variable is %p\n", &test);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *q = malloc(32);
    char *s = "Hello, World";

    void *a = malloc(15);
    void *b = malloc(15);

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
    printf ("q points to %p\n", q);
    test(var2);
    printf ("a points to %p\n", a);
    printf ("b points to %p\n", b);

    return 0;
}



//Part 1: The Address Space
/*  Queston 3.
----
Stack

var2
0x2269010 (p points to 128bytes starting at this address)


----
Heap


----
Globals

Var1

----
Constants

0x400714 (s points to this address)


----
Code

main

*/

/* Question 4.
Like p, the new pointer, named q, is also stored in the stack. However, it
resides in a larger address, namely at 0x18220a0. */

/* Question 5.
The new variable is also in the stack at a smaller address, namely at this
address: 0x7ffc265a9b1c.
*/

/* Question 6.
The address for a is 0x20a60d0.
The address for b is 0x20a60f0.
The addresses begin 32 bytes apart.
*/
