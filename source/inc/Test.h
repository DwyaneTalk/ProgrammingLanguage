#ifndef TEST_H
#define TEST_H

#include "SqList.h"
#include "LinkList.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "Tree.h"
#include "DGraph.h"
#include "UDGraph.h"
#include "StaticSrhTable.h"
#include "DynamicSrhTable.h"

class Test{
private:
    SqList      sqList;
    LinkList    linkList;
    Stack       stack;
    Queue       queue;
    BinaryTree  biTree;
    Tree        tree;
    DGraph      d_graph;
    UDGraph     ud_graph;
    StaticSrhTable sta_srh_table;
    DynamicSrhTable dyn_srh_table;
public:
    void testSqList();
    void testLinkList();
    void testStack();
    void testQueue();
    void testBinaryTree();
    void testTree();
    void testDGraph();
    void testUDGraph();
    void testDGraphApp();
    void testUDGraphApp();
    void testStaSrhTable();
    void testDynSrhTable();
};

#endif