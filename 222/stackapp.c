/*	stackapp.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether any occurrence of (, {, or [ are balanced 
   with the corresponding ), }, or ] respecting the LIFO principle
	arguments: s pointer to an input string 	
	pre-condition: s is not null	
	post: return 1 for balanced s or 0 for unbalanced s
*/
int isBalanced(char* s)
{
 struct DynArr *array = newDynArr(10);
    char c;
    while((c = nextChar(s)) != '0'){
        switch(c){
            case '{' :
            case '[' :
            case '(' :
                pushDynArr(array, c);
                break;

            case '}' :
                if(topDynArr(array) == '{'){
                    popDynArr(array);
                    break;
                }
                return 0;

            case ']' :
                if(topDynArr(array) == '['){
                    popDynArr(array);
                    break;
                }
                return 0;

            case ')' :
                if(topDynArr(array) == '('){
                    popDynArr(array);
                    break;
                }
                return 0;

        }
    }
    if(array->size != 0){
        return 0;
    }
    deleteDynArr(array);
        return 1;
		
}

int main(int argc, char* argv[]){

	char* s=argv[1];	
	/*
	char s[]="()+x+r*{{{((--{{[()[]]}}))}}}";	
	*/

	int res;

	printf("Assignment 2\n");
	
	if(argc==2)
	{
		res = isBalanced(s);

		if (res)
			printf("The string %s is balanced\n",s);
		else 
			printf("The string %s is not balanced\n",s);
	}
	else
		printf("Please enter a string to be evaluated.\n");

	
	return 0;	
}

