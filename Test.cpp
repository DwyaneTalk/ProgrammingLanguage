#include "Test.h"



void Test::testSqList() {
    cout << "顺序表测试开始……" << endl;
    SqListElemType list[] = { 1, 2, 3, 4 };
    int size = sizeof(list) / sizeof(int);
    for (int i = 0; i < size; ++i)
        sqList.insertElem(list[i], i);
    sqList.show();
    sqList.insertElem(3, 2);
    sqList.show();
    sqList.deleleElem(2);
    sqList.show();
    sqList.replaceElem(3, 1);
    sqList.show();
    sqList.traverse(SqList::visit);
    sqList.show();
    cout << endl;
}

void Test::testLinkList() {
    cout << "链表测试开始……" << endl;
    LinkListElemType list[] = { 1, 2, 3 };
    int size = sizeof(list) / sizeof(LinkListElemType);
    for (int i = 0; i < size; ++i)
        linkList.insertTailElem(list[i]);
    linkList.show();
    for (int i = 0; i < size; ++i)
        linkList.insertHeadElem(list[i]);
    linkList.show();
    for (int i = 0; i < size; ++i)
        linkList.insertElem(list[i], i * 2);
    linkList.show();
    linkList.deleteHeadElem();
    linkList.deleteTailElem();
    linkList.show();
    //linkList.init();
    //linkList.show();
    //linkList.insertHeadElem(1);
    //linkList.show();
    //linkList.deleteHeadElem();
    //linkList.show();
    //linkList.insertTailElem(1);
    //linkList.show();
    //linkList.deleteTailElem();
    //linkList.show();
    linkList.deleteElem(0);
    linkList.deleteElem(linkList.getLength() - 1);
    linkList.show();
    linkList.deleteElem(2);
    linkList.show();
    linkList.replaceElem(9, 1);
    linkList.show();
    cout << "index :" << linkList.getIndex(9) << "   data: " << linkList.getElem(linkList.getIndex(9)) << endl;
    linkList.traverse(LinkList::visit);
    linkList.show();
    cout << endl;
}

void  Test::testStack() {
    cout << "栈测试开始……" << endl;
    StackElemType list[3] = { 1, 2, 3 };
    int size = sizeof(list) / sizeof(StackElemType);
    stack.push(1);
    stack.show();
    cout << "栈顶元素：" << stack.getTop() << endl;
    stack.pop();
    stack.show();
    for (int i = 0; i < size; ++i)
        stack.push(list[i]);
    stack.show();
    stack.pop();
    stack.traverse(Stack::visit);
    stack.show();
    cout << endl;
}

void Test::testQueue() {
    cout << "队列测试开始……" << endl;
    QueueElemType list[3] = { 1, 2, 3 };
    int size = sizeof(list) / sizeof(QueueElemType);
    queue.enQueue(1);
    queue.show();
    cout << "队首元素：" << queue.getHead() << endl;
    queue.deQueue();
    queue.show();
    for (int i = 0; i < size; ++i)
        queue.enQueue(list[i]);
    queue.show();
    queue.deQueue();
    stack.traverse(Queue::visit);
    queue.show();
}