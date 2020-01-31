#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("%i",y);
    return 0;
}

/* Optimization question 1:
subq	$16, %rsp
movl	$5, -4(%rbp)
*/

/*Optimization question 2:
The output script is shorter, and storing fewer values as the unused
variables are being discarded.*/

/*Optimization question 3:
Under LC0, there is a line added saying "string "%i"". Again,
the optimized version stores fewer variables, discarding variables
that are not in use */

/*Optimization question 4:
The optimized version of the program only stores the y values, not
the x value as y is the only one used in the execusion of the code.

We can conclude that optimized code does not store values that are
not in use. */
