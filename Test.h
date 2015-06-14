#ifndef TEST_H
#define TEST_H

#include "SqList.h"
#include "LinkList.h"
#include "Stack.h"

class Test{
private:
    SqList sqList;
    LinkList linkList;
    Stack stack;
public:
    void testSqList();
    void testLinkList();
    void testStack();
};

#endif