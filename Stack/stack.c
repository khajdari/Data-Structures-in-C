#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

// Implement a dynamic stack

struct Node *top = NULL;

void push(int value) {
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp != NULL) {
        temp->value = value;
        temp->link = top;
        top = temp;
        printf("Successfully added new node... \n");
    } else {
        printf("Failed to add new node... \n");
    }
}

int isEmpty() {
    return top == NULL;
}

void pop() {
    struct Node *temp;

    if (!isEmpty()) {
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    } else {
        printf("Stack is empty... \n");
    }
}

void displayAll() {
    struct Node *temp;

    if (!isEmpty()) {
        temp = top;
        while (temp != NULL) {
            printf("%d:\n", temp->value);
            temp = temp->link;
        }
    } else {
        printf("Stack is empty... \n");
    }
}
