#ifndef SORT_H
#define SORT_H

#include "Util.h"

typedef struct SortElem{
    SortKeyType key;
    Record*     info;
    SortElem(SortKeyType key = 0, Record* info = NULL) {
        this->key = key;
        this->info = info;
    }
} SortElem;

class Sort {
private:
    SortElem *data;
    UInt32  num;
    UInt32  selectMin(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    shellInsert(SortElem* data, UInt32 num, UInt32 inc, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    UInt32  partition(SortElem* data, UInt32 lo, UInt32 hi, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    mSort(SortElem* data, UInt32 num, SortElem* tmp_data, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    merge(SortElem* data, UInt32 num1, UInt32 num2, SortElem* tmp_data, Int32(*compare)(SortElem* data_a, SortElem* data_b));
public:
    Sort();
    ~Sort();
    void static copy(SortElem* dst, SortElem* src);
    void static exchange(SortElem* data_a, SortElem* data_b, SortElem* tmp_data);
    SortElem* createRandData(UInt32 num);
    void    insertSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    selectSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    bubbleSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    shellSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    quickSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    mergeSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
    void    heapSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b));
};

Int32 compare_asc(SortElem* data_a, SortElem* data_b);

Int32 compare_des(SortElem* data_a, SortElem* data_b);

#endif  //SORT_H