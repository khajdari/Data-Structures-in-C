#ifndef STACK_STACK_H
#define STACK_STACK_H

struct Node {
    int value;
    struct Node *link;
};

void push(int value);
int isEmpty();
void pop();
void displayAll();

#endif //STACK_STACK_H
