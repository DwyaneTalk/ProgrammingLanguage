#include "Stack.h"

Stack::Stack() {
    base = new ElemType[INIT_SIZE];
    if (base) {
        top = 0;
        max_size = INIT_SIZE;
    } else {
        cout << "申请内存失败" << endl;
        exit(OVER);
    }
}

Stack::~Stack() {
    delete base;
    top = 0;
    max_size = 0;
}

void Stack::init() {
    top = 0;
}

bool Stack::isEmpty() {
    return !top;
}

int Stack::getLength() {
    return top;
}

ElemType Stack::getTop() {
    if (top <= 0) {
        cout << "栈空，无法获取栈顶元素" << endl;
        exit(ERROR);
    }
    return base[top - 1];
}

ElemType Stack::pop() {
    if (top <= 0) {
        cout << "栈空，无法出栈" << endl;
        exit(ERROR);
    }
    return base[--top];
}

void Stack::push(ElemType e) {
    base[top++] = e;
}

void Stack::traverse(void(*visit)(ElemType &e)) {
    for (int i = 0; i < top; ++i) {
        visit(base[i]);
    }
}

void Stack::show(){
    cout << "栈中" << top << "个元素分别为：";
    for (int i = 0; i < top; ++i) {
        cout << " " << base[i];
    }
    cout << endl;
}