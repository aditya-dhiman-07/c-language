#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/*
 * Reverses k nodes starting from *head.
 * Returns the new head of the reversed segment,
 * and sets *tail to the old head (new tail).
 * *head is updated to the node after the reversed segment.
 */
Node* reverseK(Node** head, int k) {
    Node* prev = NULL;
    Node* curr = *head;
    Node* next = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    /* *head (old head) is now the tail of the reversed segment */
    (*head)->next = curr;  /* temporarily point to remainder */
    *head = curr;          /* advance head past the reversed segment */
    return prev;           /* new head of reversed segment */
}

/*
 * Skips k nodes (the group to keep as-is).
 * Returns the node just before the next group to reverse,
 * so we can stitch segments together.
 */
Node* skipK(Node** head, int k) {
    Node* tail = *head;
    int count = 0;

    while (*head != NULL && count < k) {
        tail = *head;
        *head = (*head)->next;
        count++;
    }
    return tail;  /* last node of the skipped group */
}

Node* Reverse_K(Node* head, int k) {
    if (head == NULL || k <= 1) return head;

    Node* curr      = head;
    Node* newHead   = NULL;
    Node* prevTail  = NULL;   /* tail of the last processed segment */

    while (curr != NULL) {
        /* --- Step 1: REVERSE a group of k nodes --- */
        Node* segStart = curr;           /* will become tail after reversal */
        Node* segHead  = reverseK(&curr, k);
        /* curr now points to the node after the reversed segment */

        if (newHead == NULL)
            newHead = segHead;           /* first segment sets the new head */
        else
            prevTail->next = segHead;    /* link previous tail to this segment */

        prevTail = segStart;             /* segStart is the tail of reversed group */

        if (curr == NULL) break;

        /* --- Step 2: SKIP a group of k nodes (keep as-is) --- */
        Node* skipHead = curr;
        prevTail->next = skipHead;       /* link reversed tail to skip group */
        prevTail = skipK(&curr, k);      /* prevTail = last node of skipped group */
        prevTail->next = curr;           /* ensure tail points forward correctly */
    }

    return newHead;
}

/* ---------- Utility functions ---------- */

Node* newNode(int data) {
    Node* n = malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void printList(Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

Node* buildList(int* arr, int n) {
    if (n == 0) return NULL;
    Node* head = newNode(arr[0]);
    Node* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = newNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    /* Test 1: n=9, k=3 → 3->2->1->6->5->4->9->8->7 */
    int a1[] = {1,2,3,4,5,6,7,8,9};
    Node* l1 = buildList(a1, 9);
    printf("Original: "); printList(l1);
    l1 = Reverse_K(l1, 3);
    printf("Result:   "); printList(l1);

    printf("\n");

    /* Test 2: n=8, k=3 → 3->2->1->6->5->4->7->8 */
    int a2[] = {1,2,3,4,5,6,7,8};
    Node* l2 = buildList(a2, 8);
    printf("Original: "); printList(l2);
    l2 = Reverse_K(l2, 3);
    printf("Result:   "); printList(l2);

    return 0;
}