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

void delete_alternate_nodes(struct Node* start) {
    struct Node* ptr = start;

    while (ptr && ptr->next) {
        struct Node* temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        ptr = ptr->next;
    }
}

int main() {
    struct Node* start = NULL;

    insertAtEnd(&start, 10);
    insertAtEnd(&start, 20);
    insertAtEnd(&start, 30);
    insertAtEnd(&start, 40);
    insertAtEnd(&start, 50);
    insertAtEnd(&start, 60);

    printf("Original Linked List:\n");
    display(start);

    delete_alternate_nodes(start);

    printf("After Deleting Alternate Nodes:\n");
    display(start);

    return 0;
}

