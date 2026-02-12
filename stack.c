#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Define the maximum size of the stack

int stack[MAX_SIZE]; // Array to store the stack elements
int top = -1;        // Index of the top element, initialized to -1 for an empty stack

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Function to add an element to the top of the stack (push operation)
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot add more elements.\n");
    } else {
        stack[++top] = value; // Increment top first, then add the element
        printf("Pushed element: %d\n", value);
    }
}

// Function to remove and return the top element from the stack (pop operation)
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop elements.\n");
        return -1; // Return a sentinel value for error
    } else {
        int popped_value = stack[top];
        top--; // Decrement top after retrieving the element
        printf("Popped element: %d\n", popped_value);
        return popped_value;
    }
}

// Function to retrieve the top element without removing it (peek operation)
int peek() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return -1; // Return a sentinel value for error
    } else {
        return stack[top];
    }
}

// Function to display all elements in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is Empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Driver code to test the stack operations
int main() {
    push(10);
    push(20);
    push(30);
    display(); // Output: Stack elements: 30 20 10
    printf("Top element is: %d\n", peek()); // Output: Top element is: 30
    pop(); // Output: Popped element: 30
    display(); // Output: Stack elements: 20 10
    pop();
    pop();
    pop(); // Output: Stack Underflow! Cannot pop elements.

    return 0;
}
