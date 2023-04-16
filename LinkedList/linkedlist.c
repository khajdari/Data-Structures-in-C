#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

struct Node *newNode, *ptr, *prev, *temp;
struct Node *head = NULL, *tail = NULL;

struct Node *initializeNewNode(int inputValue) {
    newNode = (struct Node *) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nMemory was not allocated");
        return 0;
    } else {
        newNode->value = inputValue;
        newNode->next = NULL;
        return newNode;
    }
}

void addNewNodeAtTheBeginning() {
    int inputValue = 0;

    printf("\nEnter the value for the new Node: ");
    scanf("%d", &inputValue);

    newNode = initializeNewNode(inputValue);
    if (head == tail && head == NULL) {
        head = tail = newNode;
        head->next = NULL;
        tail->next = NULL;
    } else {
        temp = head;
        head = newNode;
        head->next = temp;
    }

    printf("\n----Added----");
}

void addNewNodeAtTheEnd() {
    int inputValue = 0;

    printf("\nEnter the value for the Node: ");
    scanf("%d", &inputValue);

    newNode = initializeNewNode(inputValue);
    if (head == tail && tail == NULL) {
        head = tail = newNode;
        head->next = NULL;
        tail->next = NULL;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = NULL;
    }

    printf("\n----Added----");
}

void addNewNodeAtPosition() {
    int inputPosition, inputValue, cnt = 0, i;

    printf("\nEnter the value for the new Node: ");
    scanf("%d", &inputValue);
    newNode = initializeNewNode(inputValue);
    printf("\nEnter the position ");
    scanf("%d", &inputPosition);

    ptr = head;
    while (ptr != NULL) {
        ptr = ptr->next;
        cnt++;
    }
    if (inputPosition == 1) {
        if (head == tail && head == NULL) {
            head = tail = newNode;
            head->next = NULL;
            tail->next = NULL;
        } else {
            temp = head;
            head = newNode;
            head->next = temp;
        }
        printf("\nAdded");
    } else if (inputPosition > 1 && inputPosition <= cnt) {
        ptr = head;
        for (i = 1; i < inputPosition; i++) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = newNode;
        newNode->next = ptr;
        printf("\n----Added----");
    } else {
        printf("Position is out of range");
    }
}

void deleteNodePosition() {
    int inputPosition, cnt = 0, i;

    if (head == NULL) {
        printf("List is empy\n");
        printf(":No Node to delete\n");
    } else {
        printf("\nEnter the position of value to be deleted: ");
        scanf(" %d", &inputPosition);
        ptr = head;
        if (inputPosition == 1) {
            head = ptr->next;
            printf("\nElement deleted");
        } else {
            while (ptr != NULL) {
                ptr = ptr->next;
                cnt = cnt + 1;
            }
            if (inputPosition > 0 && inputPosition <= cnt) {
                ptr = head;
                for (i = 1; i < inputPosition; i++) {
                    prev = ptr;
                    ptr = ptr->next;
                }
                prev->next = ptr->next;
            } else {
                printf("Position is out of range ");
            }
            free(ptr);
            printf("\nElement deleted");
        }
    }
}

void updateNodeValue() {
    int oldInputValue, newInputValue, flag = 0;

    if (head == NULL) {
        printf("List is empty\n");
        printf(":No nodes in the list to update\n");
    } else {
        printf("\nEnter the value to be updated: ");
        scanf("%d", &oldInputValue);
        printf("\nEnter the new value:");
        scanf("%d", &newInputValue);
        for (ptr = head; ptr != NULL; ptr = ptr->next) {
            if (ptr->value == oldInputValue) {
                ptr->value = newInputValue;
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            printf("\nUpdated Successfully");
        } else {
            printf("\nValue not found in List");
        }
    }
}

void searchValue() {
    int flag = 0, key, pos = 0;

    if (head == NULL) {
        printf("List is empty\n");
        printf(":No nodes in the list\n");
    } else {
        printf("\nEnter the value to searchValue ");
        scanf("%d", &key);
        for (ptr = head; ptr != NULL; ptr = ptr->next) {
            pos = pos + 1;
            if (ptr->value == key) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            printf("\nElement %d found at %d position\n", key, pos);
        } else {
            printf("\nElement %d not found in list\n", key);
        }
    }
}

void displayValues() {
    if (head == NULL) {
        printf("List is empty\n");
        printf(":No nodes in the list to displayValues\n");
    } else {
        for (ptr = head; ptr != NULL; ptr = ptr->next) {
            printf("%d\t", ptr->value);
        }
    }
}
