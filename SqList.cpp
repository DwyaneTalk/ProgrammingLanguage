
#include "SqList.h"


SqList::SqList(){
	elem = new ElemType[LIST_INIT_SIZE];
	if (!elem)	exit(OVER);
	listSize = LIST_INIT_SIZE;
	length = 0;
}

SqList::~SqList(){
	listSize = 0;
	length = 0;
	delete[] elem;
}

void SqList::Init() {
    delete[] elem;
    elem = new ElemType[LIST_INIT_SIZE];
    if (!elem)	exit(OVER);
    listSize = LIST_INIT_SIZE;
    length = 0;
}

void SqList::Destroy() {
    listSize = 0;
    length = 0;
    delete[] elem;
}

void SqList::clear(){
	length = 0;
}

bool SqList::isEmpty(){
	return !length;
}

int SqList::getLength(){
	return length;
}

ElemType SqList::getElem(int i){
	if (i < 0) {
		cout << "���Ϸ��Ļ�ȡԪ��λ��" << endl;
		exit(ERROR);
	}
	return elem[i];
}

int SqList::insertElem(ElemType e, int i){
	if (i < 0 || i > length){
		cout << "���Ϸ��Ĳ���Ԫ��λ��" << endl;
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
		cout << "���Ϸ���ɾ��Ԫ��λ��" << endl;
		exit(ERROR);
	}
	ElemType delElem = elem[i];
	for (int p = i; i < length - 1; i++){
		elem[i] = elem[i + 1];
	}
	--length;
	return delElem;
}

ElemType SqList::replaceElem(ElemType e, int i) {
    if (i < 0 || i >= length) {
        cout << "���Ϸ����滻Ԫ��λ��" << endl;
        exit(ERROR);
    }
    ElemType ans = elem[i];
    elem[i] = e;
    return ans;
}

void SqList::traverse(void(*visit)(ElemType& e)){
	for (int i = 0; i < length; i++){
		visit(elem[i]);
	}
}

void SqList::show() {
    printf("%d��˳���Ԫ�����£�", length);
    for (int i = 0; i < length; ++i) {
        printf("%d ", elem[i]);
    }
    printf("\n");
}