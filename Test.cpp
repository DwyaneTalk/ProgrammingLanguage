#include "Test.h"

void visit(ElemType &e) {
    e = e + 1;
}

void Test::testSqList(SqList *sqList) {
    int list[] = { 1, 2, 3, 4 };
    int size = sizeof(list) / sizeof(int);
    for (int i = 0; i < size; ++i)
        sqList->insertElem(list[i], i);
    sqList->show();
    sqList->insertElem(3, 2);
    sqList->show();
    sqList->deleleElem(2);
    sqList->show();
    sqList->replaceElem(3, 1);
    sqList->show();
    sqList->traverse(visit);
    sqList->show();
}

void Test::testLinkList(LinkList *linkList) {

}
