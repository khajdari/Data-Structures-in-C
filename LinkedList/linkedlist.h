#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

struct Node
{
    int value;
    struct Node *next;
};

struct Node* initializeNewNode(int);
void addNewNodeAtTheBeginning();
void addNewNodeAtTheEnd();
void addNewNodeAtPosition();
void deleteNodePosition();
void searchValue();
void updateNodeValue();
void displayValues();


#endif //LINKEDLIST_LINKEDLIST_H
