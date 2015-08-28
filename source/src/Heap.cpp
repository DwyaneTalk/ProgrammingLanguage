#include "../inc/Heap.h"

Heap::Heap() {
    data = NULL;
    max_num = NULL;
    num = 0;
}

Heap::~Heap() {
    data = NULL;
    max_num = NULL;
    num = 0;
}

SortElem* Heap::heapTop() {
    if (data) {
        return data;
    } else {
        cout << "堆为空，请初始化堆数据" << endl;
    }
}

void Heap::heapDownAdjust(UInt32 top, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    SortElem tmp_data(data[top].key, data[top].info);
    UInt32 left = top * 2, max;
    while (left <= num) {
        if (compare(data + left, data + left + 1) > 0) {
            if (compare(&tmp_data, data + left) >= 0) {
                Sort::copy(data + top, &tmp_data);
                return;
            } else {
                Sort::copy(data + top, data + left);
                top = left;
                left = top * 2;
            }
        } else {
            if (compare(&tmp_data, data + left + 1) >= 0) {
                Sort::copy(data + top, &tmp_data);
                return;
            } else {
                Sort::copy(data + top, data + left + 1);
                top = left + 1;
                left = top * 2;
            }
        }
    }
}


SortElem* Heap::getData(UInt32 &num) {
    num = this->num;
    return data;
}

void Heap::initData(SortElem* data, UInt32 num) {
    this->num = num;
    this->data = data;
}

void Heap::heapAdjust(Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    if (data) {
        for (UInt32 i = num / 2; i >= 1; --i) {
            heapDownAdjust(i, num, compare);
        }
    } else {
        cout << "堆为空，请初始化堆数据" << endl;
    }
}

void Heap::heapSort(SortElem* data, UInt32 num, Int32(*compare)(SortElem* data_a, SortElem* data_b)) {
    initData(data, num);
    SortElem tmp_data, *tmp_ptr = &tmp_data;
    for (UInt32 j = num; j > 1;) {
        Sort::exchange(data + 1, data + j, tmp_ptr);
        heapDownAdjust(1, --j, compare);
    }
}

void Heap::heapInsert(SortElem* elem) {
    data[++num].key = elem->key;
    data[num].info = elem->info;
}