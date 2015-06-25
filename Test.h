#ifndef TEST_H
#define TEST_H

#include "SqList.h"
#include "LinkList.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"

class Test{
private:
    SqList sqList;
    LinkList linkList;
    Stack stack;
    Queue queue;
    BinaryTree biTree;
public:
    void testSqList();
    void testLinkList();
    void testStack();
    void testQueue();
    void testBinaryTree();
};

#endif