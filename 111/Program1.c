/* CS261- HW1 - Program1.c*/
/* Name:Haoxiang Dai
 * Date:1/16/2020
 * Solution description:
 * a foo function can increment a and b and assign a-b to c
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int foo(int* a, int* b, int c){
    /* Increment a */
    (*a)++;
    /* Decrement  b */
    (*b)--;
    /* Assign a-b to c */
    c = *a - *b;
    /* Return c */
    return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    srand((unsigned)time(NULL));
    int *x = NULL;
    int temp1 = rand()%10;
    x = &temp1;
    int *y = NULL;
    int temp2 = rand()%10;
    y = &temp2;
   
    int z = rand()%10;

    /* Print the values of x, y and z */
    printf("the values of x, y and z:   %d, %d, %d\n",*x, *y, z);

    /* Call foo() appropriately, passing x,y,z as parameters */
    printf("foo: %d\n",foo(x,y,z));

    /* Print the values of x, y and z */
    printf("the values of x, y and z:   %d, %d, %d\n", *x,  *y ,z);

    /* Print the value returned by foo */
    printf("foo: %d\n", foo(x,y,z));
    /* Is the return value different than the value of z?  Why? */
    printf("yes, because the value of z were assigned by (*x)++ - (*y)-- in foo(), but that value of c doesn't trans to the original variable z\n");
    return 0;
}
    
    
