#include <iostream>
#include "stdlib.h"

#include "SqList.h"
using namespace std;


SqList::SqList(){
//	elem = new ElemType[LIST_INIT_SIZE];
	elem = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	if (!elem)	exit(OVERFLOW);
	listSize = LIST_INIT_SIZE;
	length = 0;
}

SqList::~SqList(){
	listSize = 0;
	length = 0;
//	delete[] elem;
	free(elem);
}

void SqList::clear(){
	length = 0;
}

bool SqList::isEmpty(){
	return !bool(length);
}

int SqList::getLength(){
	return length;
}

ElemType SqList::getElem(int i){
	if (i < 0) {
		cout << "不合法的获取元素位置" << endl;
		exit(ERROR);
	}
	return elem[i];
}

int SqList::insertElem(ElemType e, int i){
	if (i < 0 || i > length){
		cout << "不合法的插入元素位置" << endl;
		exit(ERROR);
	}
	if (length >= listSize){
		elem = (ElemType*)realloc(elem, sizeof(ElemType)* (listSize + LISTINCREMENT));
	}
	for (int p = length; p > i; p--){
		elem[p] = elem[p - 1];
	}
	elem[i] = e;
	return ++length;
}

ElemType SqList::deleleElem(int i){
	if (i < 0 || i >= length){
		cout << "不合法的删除元素位置" << endl;
		exit(ERROR);
	}
	ElemType delElem = elem[i];
	for (int p = i; i < length - 1; i++){
		elem[i] = elem[i + 1];
	}
	--length;
	return delElem;
}

void SqList::traverse(void(*visit)(ElemType& e)){
	for (int i = 0; i < length; i++){
		visit(elem[i]);
	}
}