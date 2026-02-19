#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertAtStart(struct Node** start, int data) {
    struct Node* temp = createNode(data);
    temp->next = *start;  
    *start = temp;
}

void insertAtEnd(struct Node** start, int data) {
    struct Node* temp = createNode(data);

    if (*start == NULL) {
        *start = temp;
        return;
    }

    struct Node* ptr = *start;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;
}

void insertBefore(struct Node** start, int x, int data) {
    if (*start == NULL) return;

    if ((*start)->data == x) {
        insertAtStart(start, data);
        return;
    }

    struct Node* ptr = *start;
    while (ptr->next && ptr->next->data != x)
        ptr = ptr->next;

    if (ptr->next) {
        struct Node* temp = createNode(data);
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void insertAfter(struct Node** start, int x, int data) {
    if (*start == NULL) return;

    struct Node* ptr = *start;
    while (ptr && ptr->data != x)
        ptr = ptr->next;

    if (ptr) {
        struct Node* temp = createNode(data);
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void deleteFirst(struct Node** start) {
    if (*start == NULL) return;

    struct Node* temp = *start;
    *start = temp->next;
    free(temp);
}

void deleteLast(struct Node** start) {
    if (*start == NULL) return;

    if ((*start)->next == NULL) {
        free(*start);
        *start = NULL;
        return;
    }

    struct Node* ptr = *start;
    while (ptr->next->next != NULL)
        ptr = ptr->next;

    free(ptr->next);
    ptr->next = NULL;
}

void deleteValue(struct Node** start, int x) {
    if (*start == NULL) return;

    if ((*start)->data == x) {
        deleteFirst(start);
        return;
    }
    struct Node* ptr = *start;
    while (ptr->next && ptr->next->data != x)
        ptr = ptr->next;
    if (ptr->next) {
        struct Node* temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
}

void display(struct Node* start) {
    struct Node* ptr = start;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct Node* reverselist(struct Node** start) {
    struct Node*prev = NULL,*ptr=*start,*next=NULL;
    while(ptr){
        next = ptr->next;
        ptr->next=prev;
        prev = ptr;
        ptr = next;
    }
    *start = prev;
    return *start; 
}

int main() {
    struct Node* start = NULL;

    printf("Insert at Start: 10\n");
    insertAtStart(&start, 10);

    printf("Insert at End: 20\n");
    insertAtEnd(&start, 20);

    printf("Insert at End: 30\n");
    insertAtEnd(&start, 30);

    printf("Insert Before 20: 15\n");
    insertBefore(&start, 20, 15);

    printf("Insert After 20: 25\n");
    insertAfter(&start, 20, 25);

    printf("\nLinked List:\n");
    display(start);

    printf("\nDelete First Node\n");
    deleteFirst(&start);
    display(start);

    printf("\nDelete Last Node\n");
    deleteLast(&start);
    display(start);

    printf("\nDelete Node with value 20\n");
    deleteValue(&start, 20);
    display(start);


    return 0;
}
