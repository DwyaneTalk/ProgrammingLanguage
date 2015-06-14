#ifndef TEST_H
#define TEST_H

#include "SqList.h"
#include "LinkList.h"
#include "Stack.h"
#include "Queue.h"

class Test{
private:
    SqList sqList;
    LinkList linkList;
    Stack stack;
    Queue queue;
public:
    void testSqList();
    void testLinkList();
    void testStack();
    void testQueue();
};

#endif