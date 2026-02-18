#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* createnode(int data);
void insertatstart(struct node** start, int data);
void insertatend(struct node** start, int data);
void insertbefore(struct node**start,int x,int data);
void insertafter(struct node**start,int x , int data);
void deletefirst(struct node** start);
void deletelast(struct node** start);
void deletevalue(struct node** start,int x);
void display(struct node** start);

 
int main(){
    struct node*start = NULL;
    insertatend(&start,16);
    insertatstart(&start,56);
    insertatend(&start,25);
    insertatend(&start,46);
    insertbefore(&start,16,69);
    insertafter(&start,25,104);
    display(&start);
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

void insertatstart(struct node** start, int data) {
    struct node* temp = createnode(data);
    temp->next = *start;
    if (*start != NULL) {
        (*start)->prev = temp;
    }
    *start = temp;
}

void insertatend(struct node** start, int data){
    struct node*temp = createnode(data);
    if (*start == NULL){
        *start = temp;
        return;
    }
    struct node*ptr = *start;
    while (ptr->next){
        ptr = ptr->next;
    }
    temp->prev = ptr;
    ptr->next = temp;
    temp->next = NULL;
}

void insertbefore(struct node**start,int x,int data){
    struct node*temp = createnode(data);
    if(!(*start)){
        printf("There is no element with value %d.",x);
        return;
    }
    else if((*start)->data == x){
        temp->next = (*start);
        (*start)->prev = temp;
        *start = temp;
        return;
    }
    struct node*ptr = *start;
    while(ptr->next && ptr->next->data != x){
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    temp->next->prev = temp;
    ptr->next = temp;
    temp->prev = ptr;
}

void insertafter(struct node** start, int x, int data) {
    if (!(*start)) {
        printf("List is empty.");
        return;
    }
    struct node* ptr = *start;
    while (ptr && ptr->data != x) {
        ptr = ptr->next;
    }
    if (!ptr) {
        printf("There is no element with value %d.", x);
        return;
    }
    struct node* temp = createnode(data);
    temp->prev = ptr;
    temp->next = ptr->next;
    if (ptr->next) {
        ptr->next->prev = temp;
    }
    ptr->next = temp;
}

void deletefirst(struct node**start){

    struct node* temp = *start;
    if (!(*start)) {
        printf("List is empty.");
        return;
    }
    if(!(temp->next)){
    temp->next->prev = NULL;
    *start = temp->next;
    }
    free(temp);

}

void display(struct node** start){
    if(!(*start)) {
        printf("List is empty.");
        return;
    }
    struct node*ptr = *start;
    while(ptr){
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}