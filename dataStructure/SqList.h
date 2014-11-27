#include "TypeDef.h"

class SqList{
private:
	int			length;
	int			listSize;
	ELEMTYPE *	elem;
public:
	SqList();
	~SqList();
	void Init();
	void Destroy();
};