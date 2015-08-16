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
    UInt32 low = 0, high = size - 1, mid, fib_num = MAX(5, size);
    UInt32 *fib = new UInt32[fib_num];
    fib[0] = 0;
    fib[1] = 1;
    UInt32 i = 2, u = 0;
    while (i < fib_num) {
        fib[i] = fib[i - 1] + fib[i - 2];
        ++i;
    }
    while (size >= fib[u]) {
        ++u;
    }
    SearchType *data_ext = new SearchType[fib[u] - 1];
    memcpy(data_ext, data, sizeof(SearchType)* size);
    for (i = size; i < fib[u] - 2; ++i)
        data_ext[i] = data[size - 1];
    while (low <= high) {
        mid =low + fib[u - 1] - 1;
        if (data_ext[mid] == key) {
            delete fib;
            delete data_ext;
            return MIN(mid, size);
        } else if (data_ext[mid] < key) {
            low = mid + 1;
            u = u - 2;
        } else {
            high = mid - 1;
            u = u - 1;
        }
    }
    delete fib;
    delete data_ext;
    return -1;
}

Int32 StaticSrhTable::intSearch(SearchType key) {
    SearchType min = seq_data[0], max = seq_data[size - 1];
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
