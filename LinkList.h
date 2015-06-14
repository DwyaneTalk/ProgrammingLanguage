#ifndef LINKLIST_H
#define LINKLIST_H

#include "Util.h"

typedef int ElemType;


typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode;

class LinkList {
private:
    LinkNode *head;
    LinkNode *tail;
    int size;
public:
    LinkList();
    ~LinkList();
    void init();
    bool isEmpty();
    int getLength();
    int getIndex(ElemType e);
    ElemType getElem(int i);
    void insertHeadElem(ElemType e);
    void insertTailElem(ElemType e);
    void insertElem(ElemType e, int i);
    ElemType deleteHeadElem();
    ElemType deleteTailElem();
    ElemType deleteElem(int i);
    ElemType replaceElem(ElemType e, int i);
    void traverse(void(*visit) (ElemType &e));
    void show();
};

#endif