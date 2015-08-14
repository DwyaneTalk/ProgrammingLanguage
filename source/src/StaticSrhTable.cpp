#include "../inc/StaticSrhTable.h"
#include<algorithm>

StaticSrhTable::StaticSrhTable() {
    fin >> size;
    if (data = new SearchType[size]) {
        for (UInt32 i = 0; i < size; ++i) {
            fin >> data[i];
        }
        seq_data = NULL;
        sta_srh_tree = NULL;
        idx_table = NULL;
    } else {
        ferr << "¾²Ì¬²éÕÒ±íÄÚ´æÉêÇëÊ§°Ü" << endl;
        exit(OVER);
    }
}

StaticSrhTable::~StaticSrhTable() {
    delete data;
    delete seq_data;
    delete sta_srh_tree;
    delete idx_table;
    size = 0;
}

Int32 StaticSrhTable::search(FindType f_type, SearchType key) {
    switch (f_type) {
    case SEQ:   
        return seqSearch(key);
        break;
    case BIN:   
        sortData();
        return binSearch(key);
        break;
    case FIB:   
        sortData();
        return fibSearch(key);
        break;
    case INT:   
        sortData();
        return intSearch(key);
        break;
    case STR:   break;
    case IDX:   break;
    default:
        break;
    }
}

Int32 StaticSrhTable::seqSearch(SearchType key) {
    UInt32 i = 0;
    for (; i < size; ++i) {
        if (data[i] == key) {
            return i;
        }
    }
    return -1;
}

Int32 StaticSrhTable::binSearch(SearchType key) {
    UInt32 low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (seq_data[mid] == key)   return mid;
        else if (seq_data[mid] < key)   low = mid + 1;
        else    high = mid - 1;
    }
    return -1;
}

Int32 StaticSrhTable::fibSearch(SearchType key) {

}

Int32 StaticSrhTable::intSearch(SearchType key) {

}

Int32 StaticSrhTable::strSearch(SearchType key) {

}

Int32 StaticSrhTable::idxSearch(SearchType key) {

}

void  StaticSrhTable::sortData() {
    if (!seq_data) {
        seq_data = new SearchType[size];
        if (!seq_data) {
            ferr << "ÉêÇëÄÚ´æÊ§°Ü£¡" << endl;
            exit(OVER);
        }
        memcpy(seq_data, data, sizeof(SearchType)* size);
        sort(seq_data, seq_data + size);
    }
}

void StaticSrhTable::traverse(void(*visit)(SearchType &e)) {

}

void StaticSrhTable::visit(SearchType &e) {

}
