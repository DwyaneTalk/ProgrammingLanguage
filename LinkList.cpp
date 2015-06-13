#include "LinkList.h"

LinkList::LinkList() {
    head = tail = NULL;
    size = 0;
}

LinkList::~LinkList() {
    LinkNode *node;
    while (head) {
        node = head->next;
        delete head;
        head = node;
    }
    head = tail = NULL;
    size = 0;
}

void LinkList::init() {
    LinkNode *node;
    while (head) {
        node = head->next;
        delete head;
        head = node;
    }
    head = tail = NULL;
    size = 0;
}

bool LinkList::isEmpty() {
    return !size;
}

int LinkList::getLength() {
    return size;
}

/*返回从0开始的元素索引， -1表示不存在*/
int LinkList::getIndex(ElemType e) {
    int cnt = 0;
    LinkNode *node = head;
    while (node) {
        if (node->data == e) {
            break;
        } else {
            node = node->next;
            ++cnt;
        }
    }
    if (node)   return cnt;
    else        return -1;
}

/*获取从0开始的索引处的元素*/
ElemType LinkList::getElem(int i) {
    int cnt = 0;
    LinkNode *node = head;
    while (cnt < i && node) {
        ++cnt;
        node = node->next;
    }
    if (node && i >= 0)   return node->data;
    else {
        cout << "不合法的元素下标" << endl;
        exit(ERROR);
    }
}

void LinkList::insertHeadElem(ElemType e) {
    LinkNode *node = new LinkNode;
    if (node) {
        node->data = e;
        node->next = head;
        head = node;
        if (!size)  tail = node;
        size += 1;
    } else {
        exit(OVER);
    }
}

void LinkList::insertTailElem(ElemType e) {
    LinkNode *node = new LinkNode;
    if (node) {
        node->data = e;
        node->next = NULL;
        if (size)
            tail->next = node;
        else
            head  = node;
        tail = node;
        size += 1;
    } else {
        exit(OVER);
    }
}

void LinkList::insertElem(ElemType e, int i) {
    int cnt = 1;
    LinkNode *node = head;
    if (i == 0) insertHeadElem(e);
    while (cnt < i && node) {
        ++cnt;
        node = node->next;
    }
    if (i > 0 && node) {
        LinkNode *newNode = new LinkNode;
        newNode->data = e;
        newNode->next = node->next;
        node->next = newNode;
        if (node == tail)
            tail = newNode;
    } else {
        cout << "不合法的元素下标" << endl;
        exit(ERROR);
    }
}

void LinkList::insertPreElem(ElemType e, ElemType data){
    LinkNode *preNode = NULL, *curNode = head;
    while (curNode && curNode->data != data) {
        preNode = curNode;
        curNode = curNode->next;
    }
    if (!curNode) {
        cout << "无有效的插入元素位置" << endl;
        exit(ERROR);
    }
    if (preNode) {
        LinkNode *node = new LinkNode;
        node->data = e;
        node->next = curNode;
        preNode->next = node;
    } else {
        LinkNode *node = new LinkNode;
        node->data = e;
        node->next = curNode;
        head = node;
    }
}

void LinkList::insertNextElem(ElemType e, ElemType data) {
    LinkNode *node = head;
    while (node && node->data != data) {
        node = node->next;
    }
    if (node) {
        LinkNode *newNode = new LinkNode;
        newNode->data = e;
        newNode->next = node->next;
        node->next = newNode;
        if (node == tail)
            tail = newNode;
    } else {
        cout << "无有效的插入元素位置" << endl;
        exit(ERROR);
    }
}

ElemType LinkList::deleteHeadElem() {
    if (size < 1) {
        cout << "不合法的删除元素" << endl;
        exit(ERROR);
    }
    ElemType ans = head->data;
    LinkNode *node = head;
    head = head->next;
    if (size == 1)  tail = head;
    delete node;
    size -= 1;
    return ans;
}

ElemType LinkList::deleteTailElem() {
    if (size < 1) {
        cout << "不合法的删除元素" << endl;
        exit(ERROR);
    }
    if (size == 1) {
        delete head;
        head = tail = NULL;
    }
    LinkNode *node = head;
    ElemType ans = tail->data;
    while (node->next != tail) {
        node = node->next;
    }
    node->next = NULL;
    delete tail;
    tail = node;
    size -= 1;
    return ans;
}

ElemType LinkList::deleteElem(int i) {
    if (i < 0 || i >= size) {
        cout << "不合法的删除元素" << endl;
        exit(ERROR);
    }
    int cnt = 0;
}

ElemType LinkList::replaceElem(ElemType e, int i) {

}

ElemType LinkList::replaceDataElem(ElemType e, ElemType data) {

}

void LinkList::traverse(void(*visit)(ElemType& e)){

}

void LinkList::show() {

}
