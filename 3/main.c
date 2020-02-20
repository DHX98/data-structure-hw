/*
Haoxiang Dai
2.19/2020
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.h"
#define HASHFUNC stringHash1

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers separated by periods, spaces, or newlines.

 when there are no more words in the input file this function will return NULL.

 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file); /* prototype */

/****************************************/

int main (int argc, const char * argv[]) {
    /*Write this function*/
    const char* fileName;
    struct hashMap* hashTable = (hashMap*)malloc(sizeof(hashMap));
    FILE* fileptr;
    char* word;
    int i;

	    if(argc == 2)
        fileName = argv[1];
    else
        fileName = "input.txt";

    fileptr = fopen(fileName, "r");
    assert(fileptr != NULL);
    initMap(hashTable, 10000);

	i=0;
	word = getWord(fileptr);

	while(!feof(fileptr)){
		if(!containsKey(hashTable,word)){
			insertMap(hashTable, word, 1);
		}
		else if(containsKey(hashTable,word)){
			hashTable->table[(int)(labs(HASHFUNC(word)) % hashTable->tableSize)]->value++;
		}
		word = getWord(fileptr);
	}
    fclose(fileptr);
        for (i = 0; i < 5000; i++) {
            if (hashTable->table[i] != NULL)
            printf("%s\ttimes:%d\t\n", hashTable->table[i]->key,hashTable->table[i]->value);
        }

    freeMap(hashTable);
    free(hashTable);
    return 0;
}




char* getWord(FILE *file)
{

	int length = 0;
	int maxLength = 16;
	char character;

	char* word = (char*)malloc(sizeof(char) * maxLength);
	assert(word != NULL);

	while( (character = fgetc(file)) != EOF)
	{
		if((length+1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || /*is a number*/
		   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
		   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
		   character == 39) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if(length > 0)
			break;
	}

	if(length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}
