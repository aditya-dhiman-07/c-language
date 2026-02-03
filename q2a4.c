#include <stdio.h>
#include <stdlib.h>
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

int lengthRecursive(struct Node* start) {
    if (start == NULL)
        return 0;
    return 1 + lengthRecursive(start->next);
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
void display(struct Node* start) {
    struct Node* ptr = start;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* start = NULL;

    insertAtEnd(&start, 10);
    insertAtEnd(&start, 20);
    insertAtEnd(&start, 30);
    insertAtEnd(&start, 40);

    display(start);

    printf("Length of Linked List = %d\n", lengthRecursive(start));

    return 0;
}
