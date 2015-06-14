#ifndef QUEUE_H
#define QUEUE_H

#include "Util.h"

typedef int ElemType;

typedef struct QueueNode{
    ElemType data;
    struct QueueNode* next;
} QueueNode;

class Queue {
private:
    QueueNode *head;
    QueueNode *tail;
    int size;
public:
    Queue();
    ~Queue();
    void init();
    bool isEmpty();
    int getLength();
    ElemType getHead();
    ElemType deQueue();
    void enQueue(ElemType e);
    void traverse(void(*visit)(ElemType &e));
    void show();
};

#endif