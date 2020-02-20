/*
Haoxiang Dai
2.19/2020
*/

#include <stdlib.h>
#include <stdio.h>
#include "hashMap.h"
#include "structs.h"
#include <string.h>
#include <assert.h>

#define HASHFUNC stringHash1

int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
	return r;
}

void initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

void freeMap (struct hashMap * ht)
{  /*write this*/
	struct hashLink* current;
	struct hashLink* next;
	int i;
	for (i = 0; i < ht->tableSize; i++)
	{
		current = ht->table[i];
		while(current != NULL){
			next = current->next;
			free(current->key);
			free(current);
			current = next;
		}
	}
	free(ht->table);
	ht->count = 0;
	ht->tableSize = 0;
	ht->table = 0;
}


void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  /*write this*/
	int hash, hashIndex;
	struct hashLink *newLink;

	assert(ht != NULL);

	hash = HASHFUNC(k);

	hashIndex = (int) (labs(hash) % ht->tableSize);
	newLink = (struct hashLink *) malloc(sizeof(struct hashLink));
	assert(newLink);

	newLink->value = v;
	newLink->key = k;
	newLink->next = ht->table[hashIndex];

	ht->table[hashIndex] = newLink;
	ht->count++;
}

ValueType* atMap (struct hashMap * ht, KeyType k)
{ /*write this*/
	int index;
	hashLink* current;

	assert(ht != 0);
	if(HASHING_FUNCTION == 1)
		index = (ValueType)(labs(stringHash1(k)) % ht->tableSize);/*labs is absolute value*/
	else
		index = (ValueType)(labs(stringHash2(k)) % ht->tableSize);

	current = ht->table[index];
	while(current != 0){
		if(*(current->key) == *k) 
			return (&(current->value)); /* return key's address */
		
		current = current->next;
	}
	return NULL;
}

int containsKey (struct hashMap * ht, KeyType k)
{  /*write this*/
	if(atMap(ht, k) == 0) 
		return 0;
	else 
		return 1;
}

void removeKey (struct hashMap * ht, KeyType k)
{  /*write this*/
	struct hashLink* current;
	struct hashLink* previous;
	int index;

	if(HASHING_FUNCTION == 1)
		index = (ValueType)(labs(stringHash1(k)) % ht->tableSize);
	else
		index = (ValueType)(labs(stringHash2(k)) % ht->tableSize);

	assert(ht->table[index]!=0);
	current = ht->table[index];
	previous = ht->table[index];

	while(current != 0){
		if(*(current->next->key) == *k){ 
			if(current == ht->table[index]){
				ht->table[index] = current->next;
			}
			else
				previous->next = current->next;

			free(current);
			ht->count--;
			return;
		}
		else{ 
			previous = current;
			current = current->next;
		}
	}
}

int sizeMap (struct hashMap *ht)
{  /*write this*/
	return ht->count;
}

int capacityMap(struct hashMap *ht)
{  /*write this*/
	return ht->tableSize;
}

int emptyBuckets(struct hashMap *ht)
{  /*write this*/
	int bucket = 0;
	int i;

	for (i = 0; i < ht->tableSize; i++)
		if(ht->table[i] == 0)
			bucket++;
	return bucket;
}

float tableLoad(struct hashMap *ht)
{  /*write this*/
	float ratio;
	ratio = (ht->count)/(ht->tableSize);
	return ratio;
}

