#include "TypeDef.h"


class SqList{
private:
	int			length;//列表长度
	int			listSize;//当前最大空前
	ElemType *	elem;
public:
	SqList();
	~SqList();
//	void Init();
//	void Destroy();
	void clear();
	bool isEmpty();
	int getLength();
	ElemType getElem(int i);//获取从0开始的第i个元素
	int insertElem(ElemType e, int i);//在从0开始的i位置处插入元素e
	ElemType deleleElem(int i);
	void traverse(void (*visit)(ElemType& e));
	void show();
};