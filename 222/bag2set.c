/* bag2set.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynArray.h"


/* Converts the input bag into a set using dynamic arrays 
	param: 	da -- pointer to a bag 	
	return value: void
        result: after exiting the function da points to a set 		
*/
void bag2set(struct DynArr *da)
{       
         /* FIX ME */
        int i;
        DynArr *tempSet;
        tempSet = newDynArr(da->size);
        /* copy elements to new location if they're not in new dynarray*/
        double temp;
        int size_of_tempSet = 0;
        for(i = 0; i < da->size; i++){
                temp = da->data[i];
                if(containsDynArr(tempSet, temp) == -1){
                        size_of_tempSet += 1;
                        pushDynArr(tempSet, temp);
                }
        }

        da->size = size_of_tempSet;
        for(i = 0; i < da->size; i++)
                da->data[i] = tempSet->data[i];
        /* free*/
        deleteDynArr(tempSet);
}



/* An example how to test your bag2set() */
int main(int argc, char* argv[]){

	int i;
        struct DynArr da;  /* bag */
        
        initDynArr(&da, 100);
        da.size = 11;
        da.data[0] = 1.3;
	for (i=1;i<da.size-1;i++){
	    da.data[i] = 1.2;
	 }
        da.data[da.size-1] = 1.4;

        printf("Bag:\n\n");
	for (i=0;i<da.size;i++){
          printf("%g  \n", da.data[i]);
        }
        
        printf("\n\n\n");
        printf("Set:\n\n");
        bag2set(&da);
	for (i=0;i<da.size;i++){
          printf("%g ", da.data[i]);
        }
        printf("\n");
        
	return 0;	
}

