#ifndef STACK_H
#define STACK_H

#include "Util.h"

typedef int ElemType;

class Stack
{
private:
    ElemType *base;
    int top;
    int max_size;
public:
    Stack();
    ~Stack();
    void init();
    bool isEmpty();
    int getLength();
    ElemType getTop();
    ElemType pop();
    void push(ElemType e);
    void traverse(void(*visit)(ElemType &e));
    void show();
};
#endif