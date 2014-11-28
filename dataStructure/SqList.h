#include "TypeDef.h"


class SqList{
private:
	int			length;//�б���
	int			listSize;//��ǰ����ǰ
	ElemType *	elem;
public:
	SqList();
	~SqList();
//	void Init();
//	void Destroy();
	void clear();
	bool isEmpty();
	int getLength();
	ElemType getElem(int i);//��ȡ��0��ʼ�ĵ�i��Ԫ��
	int insertElem(ElemType e, int i);//�ڴ�0��ʼ��iλ�ô�����Ԫ��e
	ElemType deleleElem(int i);
	void traverse(void (*visit)(ElemType& e));
	void show();
};