#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node createnode(int data);

 
int main(){

return 0;
}

struct node* createnode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL){
        printf("Memory allocation failed.");
        exit(1);
    }
    temp->prev = NULL;
    temp->data = data;
    temp ->next = NULL;
    return temp;
}