/* CS261- HW1 - Program2.c*/
/* Name: Haoxiang Dai
 * Date: 1/21/2020
 * Solution description:
 * allocates memory for 10 students, and returns the pointer.
 * that generates random initials and random scores for each of the 10 students, 
 * and stores them in the array students. prints the minimum score, maximum score 
 * and average score of the 10 students.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *s_array = (struct student*)malloc(sizeof(struct student)*10);/* (type)malloc(size) */
     /*return the pointer*/
     return s_array;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z. 
	The scores must be between 0 and 100*/
    int i=0;
    for (i=0;i<10;i++){
        char c1 = rand()%26 + 'A'; 
        char c2 = rand()%26 + 'A';
        students[i].initials[0] = c1;
        students[i].initials[1] = c2;
        students[i].score = rand()%100;
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
    int i =0;
    for(i=0;i<10;i++){
        printf("%d. %s  %d\n", i+1, students[i].initials, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int sum = 0;
    int i = 0;
    for(i=0; i<10; i++){
        sum += students[i].score;
    }
    int max = 0;
    for(i=0; i<10; i++){
        if (students[i].score > max){
            max = students[i].score;
        }
    }
    int min = 100;
    for(i=0; i<10; i++){
        if (students[i].score < min){
            min = students[i].score;
        }
    }
    printf("max:    %d min:    %d ave:    %d\n", max, min, sum/10);
    
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     if(stud != NULL){
        free(stud);
     }
     
}

int main(){
    struct student* stud = NULL;
    srand((unsigned)time(NULL));
    
    /*call allocate*/
    struct student* s_arr_10 = allocate();
    /*call generate*/
    generate(s_arr_10);
   
    /*call output*/
    output(s_arr_10);
    /*call summary*/
    summary(s_arr_10);
    /*call deallocate*/

    return 0;
}
