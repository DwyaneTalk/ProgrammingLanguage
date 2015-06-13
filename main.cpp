#include "Test.h"

int main() {
    Test test;

    SqList sqList;
    test.testSqList(&sqList);

    LinkList linkList;
    test.testLinkList(&linkList);

    system("pause");
    return 0;
}