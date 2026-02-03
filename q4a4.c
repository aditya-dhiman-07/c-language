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

struct Node* concatenate_lists(struct Node* start1, struct Node* start2) {
    if (start1 == NULL)
        return start2;

    struct Node* ptr = start1;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = start2;
    return start1;
}

int main() {
    struct Node* start1 = NULL;
    struct Node* start2 = NULL;

    insertAtEnd(&start1, 1);
    insertAtEnd(&start1, 2);
    insertAtEnd(&start1, 3);

    insertAtEnd(&start2, 4);
    insertAtEnd(&start2, 5);
    insertAtEnd(&start2, 6);

    printf("First Linked List:\n");
    display(start1);

    printf("Second Linked List:\n");
    display(start2);

    start1 = concatenate_lists(start1, start2);

    printf("After Concatenation:\n");
    display(start1);

    return 0;
}


