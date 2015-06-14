#include "Test.h"

void visit(ElemType &e) {
    e = e + 1;
}

void Test::testSqList() {
    cout << "˳�����Կ�ʼ����" << endl;
    ElemType list[] = { 1, 2, 3, 4 };
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
    sqList.traverse(visit);
    sqList.show();
    cout << endl;
}

void Test::testLinkList() {
    cout << "������Կ�ʼ����" << endl;
    ElemType list[] = { 1, 2, 3 };
    int size = sizeof(list) / sizeof(ElemType);
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
    linkList.traverse(visit);
    linkList.show();
    cout << endl;
}

void  Test::testStack() {
    cout << "ջ���Կ�ʼ����" << endl;
    ElemType list[3] = { 1, 2, 3 };
    int size = sizeof(list) / sizeof(ElemType);
    stack.push(1);
    stack.show();
    cout << "ջ��Ԫ�أ�" << stack.getTop() << endl;
    stack.pop();
    stack.show();
    for (int i = 0; i < size; ++i)
        stack.push(list[i]);
    stack.show();
    stack.pop();
    stack.traverse(visit);
    stack.show();
    cout << endl;
}

void Test::testQueue() {
    cout << "���в��Կ�ʼ����" << endl;
    ElemType list[3] = { 1, 2, 3 };
    int size = sizeof(list) / sizeof(ElemType);
    queue.enQueue(1);
    queue.show();
    cout << "����Ԫ�أ�" << queue.getHead() << endl;
    queue.deQueue();
    queue.show();
    for (int i = 0; i < size; ++i)
        queue.enQueue(list[i]);
    queue.show();
    queue.deQueue();
    stack.traverse(visit);
    queue.show();
}