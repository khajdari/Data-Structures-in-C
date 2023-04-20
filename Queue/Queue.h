#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

struct QNode {
    int key;
    struct QNode *next;
};

struct Queue {
    struct QNode *head, *tail;
};

struct QNode *newQNode(int value);
struct Queue *createQueue();
void enQueue(struct Queue *queue, int value);
struct QNode *deQueue(struct Queue *queue);


#endif //QUEUE_QUEUE_H
