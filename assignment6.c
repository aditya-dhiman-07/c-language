#include<stdio.h>
#include<stdlib.h>
struct queue{
  int data;
  struct queue* next;
};
 
struct queue *front = NULL, *rear = NULL;
 
void Enqueue(int n){
  struct queue* newnode = (struct queue*)malloc(sizeof(struct queue));
  newnode->data = n;
  newnode->next = NULL;
  if(newnode == NULL) printf("queue overflow");
  else{
    if(front == NULL){ front = newnode; rear = front; }
    rear->next = newnode;
    rear = newnode;
  }
}
 
void Dequeue(){
  if (front == NULL || rear->next == front) printf("Queue underflow");
  else{
    printf("Dequeued element is: %d\n", front->data);
    front = front->next;
  }
}
 
void display(){
  if (front == NULL || rear->next == front){
    printf("Stack is Empty: ");
  } else {
    printf("Stack Element:\n");
    while (rear->next != front){
      printf("%d\n", front->data);
      front = front->next;
    }
  }
}
 
int main(){
  Enqueue(20);
  Enqueue(30);
  Enqueue(40);
  Enqueue(50);
  Dequeue();
  display();
  return 0;
}
