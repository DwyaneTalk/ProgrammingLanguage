#ifndef HEAP_H
#define HEAP_H

#include "Util.h"
#include "Sort.h"

class Heap {
private:
    SortElem* data;
    UInt32    max_num;
    UInt32    num;
    SortElem* heapTop();
    void      heapDownAdjust(UInt32 top, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
public:
    Heap();
    ~Heap();
    SortElem* getData(UInt32 &num);
    void      initData(SortElem* data, UInt32 num);
    void      heapAdjust(Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void      heapInsert(SortElem* elem);
    void      heapSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
};



#endif  //HEAP_H