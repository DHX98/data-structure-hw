/* CS261- HW1 - Program3.c*/
/* Name: Haoxiang Dai   
 * Date: 1/21/2020
 * Solution description: this program Allocate memory for an array of n integers using malloc. 
 * Fill this array with random numbers, sort the array of n integers in the ascending order.
 */
 
#include <stdio.h>
#include <time.h>//for time() seed
#include <stdlib.h>// for srand()
#include<assert.h>


void sort(int* number, int n){
     /*Sort the array of integeres of length n*/    
    assert(number != NULL);
    int i, j, temp;
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(number[j] > number[j+1]){
                temp = number[j];
                number[j] = number[j+1];
                number[j+1] = temp;
            } 
}

int main(){
    srand((unsigned)time(NULL));
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int *int_array1 = (int*)malloc(sizeof(int)*n);
    /*Fill this array with random numbers, using rand().*/
    for(int i=0;i<n;i++){
        int_array1[i] = rand();
    }
    /*Print the contents of the array.*/
    for(int i=0;i<n;i++){
        printf("%d\n", int_array1[i]);
    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(int_array1, n);
    /*Print the contents of the array.*/    
    printf("\tafter sort:\n");
    for(int i=0;i<n;i++){
        printf("%d\n", int_array1[i]);
    }
    return 0;
}
