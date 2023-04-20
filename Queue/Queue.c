#include "Queue.h"
#include <stdio.h>
#include <malloc.h>

struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
    queue->head = queue->tail = NULL;
}

struct QNode *newQNode(int value) {
    struct QNode *temp = (struct QNode *) malloc(sizeof(struct QNode));
    temp->key = value;
    temp->next = NULL;
    return temp;
}

void enQueue(struct Queue *queue, int value) {
    struct QNode *temp = newQNode(value);

    if (queue->tail == NULL) {
        queue->head = queue->tail = temp;
        return;
    }

    queue->head->next = temp;
    queue->tail = temp;
}

struct QNode *deQueue(struct Queue *queue) {
    if (queue->head == NULL) {
        return NULL;
    }

    struct QNode *temp = queue->head;
    queue->head = queue->head->next;

    if (queue->head == NULL){
        queue->tail = NULL;
    }

    return temp;
}
