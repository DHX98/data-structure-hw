/* CS261- HW1 - Program4.c*/
/* Name:  Haoxiang Dai
 * Date: 1/21/2020
 * Solution description: This program allocates memory for n (default 20)students, 
 * and returns the pointer.that generates random initials and random scores for each 
 * of the 10 students,if two students have the same first initial, 
 * compare their second initial. As in Program2.c, initials and scores of students are 
 * to be generated randomly by rand(). 
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<assert.h>

struct student{
	char initials[2];
	int score;
};

void sort(struct student* students, int n){
    /*Sort n students based on their initials*/   
    assert(students != NULL);
    assert(n != 0);
    char temp; // using for swap
    int i = 0; 
    int j = 0;
    for(i = 0; i < n-1; i++) // swap sort
        for(j = 0; j < n-i-1; j++){
            if(students[j].initials[0] > students[j+1].initials[0]){
                temp = students[j].initials[0];
                students[j].initials[0] = students[j+1].initials[0];
                students[j+1].initials[0] = temp;
                temp = students[j].initials[1];
                students[j].initials[1] = students[j+1].initials[1];
                students[j+1].initials[1] = temp;
                temp = students[j].score;
                students[j].score = students[j+1].score;
                students[j+1].score = temp;
            }
            else if(students[j].initials[0] == students[j+1].initials[0]){//first initial same, so go compare the second
                if(students[j].initials[1] > students[j+1].initials[1]){
                    temp = students[j].initials[1];
                    students[j].initials[1] = students[j+1].initials[1];
                    students[j+1].initials[1] = temp;
                    temp = students[j].score;
                    students[j].score = students[j+1].score;
                    students[j+1].score = temp;
                }
            }
        }
    
}
int main(){
    
    /*Declare an integer n and assign it a value.*/
    int n = 20;
    /*Allocate memory for n students using malloc.*/
    struct student *students = (struct student*)malloc(sizeof(struct student)*n);
    /*Generate random IDs and scores for the n students, using rand().*/
    srand((unsigned)time(NULL));
    
    for(int i=0; i<n;i++){
        char c1 = rand()%26 + 'A';
        char c2 = rand()%26 + 'A';
        students[i].initials[0] = c1;
        students[i].initials[1] = c2;
        students[i].score = rand()%101;
    }
    /*Print the contents of the array of n students.*/
    for(int i =0;i<n;i++){
        printf("%s\t%d\n", (students+i)->initials, (students+i)->score);
    }
    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    /*Print the contents of the array of n students.*/
    printf("\t after sort\n");
    for(int i =0;i<n;i++){
        printf("%s\t%d\n", (students+i)->initials, (students+i)->score);
    }
    return 0;
}
