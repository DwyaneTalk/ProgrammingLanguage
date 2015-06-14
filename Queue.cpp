#include "Queue.h"

Queue::Queue(){
    head = tail = NULL;
    size = 0;
}

Queue::~Queue() {
    while (head) {
        tail = head->next;
        delete head;
        head = tail;
    }
    head = tail = NULL;
    size = 0;
}

void Queue::init(){
    while (head) {
        tail = head->next;
        delete head;
        head = tail;
    }
    head = tail = NULL;
    size = 0;
}

bool Queue::isEmpty(){
    return !size;
}

int Queue::getLength(){
    return size;
}

ElemType Queue::getHead(){
    if (size < 1) {
        cout << "队列为空，操作非法" << endl;
        exit(ERROR);
    }
    return head->data;
}

ElemType Queue::deQueue() {
    if (size < 1) {
        cout << "队列为空，操作非法" << endl;
        exit(ERROR);
    }
    ElemType ans;
    if (size == 1) {
        ans = head->data;
        delete head;
        head = tail = NULL;
    } else {
        QueueNode *node = head;
        head = head->next;
        ans = node->data;
        delete node;
    }
    size -= 1;
    return ans;
}

void Queue::enQueue(ElemType e) {
    QueueNode *node = new QueueNode;
    node->data = e;
    node->next = NULL;
    if (!size) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
    size += 1;
}

void Queue::traverse(void(*visit)(ElemType &e)) {
    QueueNode *node = head;
    while (node) {
        visit(node->data);
        node = node->next;
    }
}

void Queue::show() {
    cout << "队列中" << size << "个元素分别为：";
    QueueNode *node = head;
    while (node) {
        cout << " " << node->data;
        node = node->next;
    }
    cout << endl;
}