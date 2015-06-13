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
    if (i == 0) {
        insertHeadElem(e);
        return;
    }
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
        size += 1;
    } else {
        cout << "不合法的元素下标" << endl;
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
    ElemType ans;
    if (size == 1) {
        ans = head->data;
        delete head;
        head = tail = NULL;
    } else {
        LinkNode *node = head;
        ans = tail->data;
        while (node->next != tail) {
            node = node->next;
        }
        node->next = NULL;
        delete tail;
        tail = node;
    }
    size -= 1;
    return ans;
}

ElemType LinkList::deleteElem(int i) {
    if (i < 0 || i >= size) {
        cout << "不合法的删除元素" << endl;
        exit(ERROR);
    }
    ElemType ans;
    if (size == 1) {
        ans = head->data;
        delete head;
        head = tail = NULL;
        size -= 1;
    } else {
        if (i == 0) return deleteHeadElem();
        else if (i == size - 1) return deleteTailElem();
        else {
            int cnt = 1;
            LinkNode *preNode = head, *curNode = head->next;
            while (cnt < i && curNode) {
                preNode = curNode;
                curNode = curNode->next;
                ++cnt;
            }
            ans = curNode->data;
            preNode->next = curNode->next;
            size -= 1;
            delete curNode;
        }
    }
    return ans;
}

ElemType LinkList::replaceElem(ElemType e, int i) {
    if (i < 0 || i >= size) {
        cout << "不合法的删除元素" << endl;
        exit(ERROR);
    }
    ElemType ans;
    int cnt = 0;
    LinkNode *node = head;
    while (cnt++ < i) {
        node = node->next;
    }
    ans = node->data;
    node->data = e;
    return ans;
}

void LinkList::traverse(void(*visit)(ElemType& e)){
    LinkNode *node = head;
    while (node) {
        visit(node->data);
        node = node->next;
    }
}

void LinkList::show() {
    LinkNode *node = head;
    cout << size << "个顺序表元素为：";
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
