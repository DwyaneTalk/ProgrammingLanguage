#include "../inc/Hash.h"


Hash::Hash(HashFun hash_type, CollFun coll_type) {
    if (elem = new HashElem[HASHSIZE]) {
        size = HASHSIZE;
        count = 0;
        this->hash_type = hash_type;
        this->coll_type = coll_type;

        switch (hash_type) {
        case LMOD:  hash_fun = lmodHashFun;
            break;
        case SQRT:  hash_fun = sqrtHashFun;
            break;
        case FOLD:  hash_fun = foldHashFun;
            break;
        }

        switch (coll_type) {
        case LINE:  coll_fun = lineCollFun; 
            break;
        case DOUB:  coll_fun = doubCollFun;
            break;
        case LINK:  coll_fun = NULL;
            break;
        }
    } else {
        ferr << "��ϣ���ݱ�����ռ�ʧ��" << endl;
        exit(OVER);
    }
}

Hash::~Hash() {
    for (UInt32 i = 0; i < size; ++i) {
        if (elem[i].info) {
            delete elem[i].info;
        }
        if (coll_type == LINK && elem[i].key_list) {
            delete elem[i].key_list;
        }
    }
    delete elem;
}

Bool Hash::searchKey(HashKeyType key, UInt32 &index, UInt32 &count) {
    UInt32 value = index = hash_fun(key);
    count = 0;
    if (coll_type == LINK) {
        if (elem[index].key_list->getIndex(key) >= 0)    return true;
        else    return false;
    } else {
        while (elem[index].status == USD && elem[index].key != key) {
            if (count >= size) {
                index = -1;
                return false;
            } else {
                index = coll_fun(value, ++count);
            }
        }
        if (elem[index].status == EMP)  return true;
        else    return false;
    }
}

Bool Hash::insertKey(HashKeyType key, Record* info) {
    UInt32 count, index;
    if (searchKey(key, index, count)) {
        cout << "�ùؼ����Ѵ��ڹ�ϣ����" << endl;
        return true;
    } else {
        if (index < 0) {
            cout << "��ϣ��ռ����޷�����ùؼ���" << endl;
            return false;
        } else {
            if (coll_type == LINK) {
                if (!elem[index].key_list)
                    elem[index].key_list = new LinkList;
                elem[index].key_list->insertHeadElem(key);
            } else {
                elem[index].status = USD;
                elem[index].key = key;
                elem[index].info = info;
            }
            return true;
        }
    }
}

Bool Hash::deleteKey(HashKeyType key) {
    UInt32 count, index;
    if (searchKey(key, index, count)) {
        if (coll_type == LINK) {
            UInt32 loc;
            if (!elem[index].key_list || (loc = elem[index].key_list->getIndex(key))) {
                ferr << "��ϣ���ڲ��ṹ����" << endl;
                exit(ERROR);
            }
            elem[index].key_list->deleteElem(loc);
        } else {
            elem[index].status = USD;
        }
    } else {
        cout << "�ùؼ��ֲ��ڹ�ϣ����" << endl;
        return false;
    }
}

UInt32 lmodHashFun(HashKeyType key) {
    return (key * HASHA + HASHB) % HASHSIZE;
}

UInt32 sqrtHashFun(HashKeyType key) {
    UInt32 sqrt = key * key;
    return ((sqrt >> 1) % HASHSIZE + (sqrt >> 5) % HASHSIZE) % HASHSIZE;
}

UInt32 foldHashFun(HashKeyType key) {
    return ((key >> 2) + 10 * (key % 10) + (key >> 1) % 10) % HASHSIZE;
}

UInt32 lineCollFun(UInt32 index, UInt32 count) {
    return (index + count) % HASHSIZE;
}

UInt32 doubCollFun(UInt32 index, UInt32 count) {
    return (index + ((count + 1) / 2 * (count + 1) / 2) * ((-1) ^ (count - 1))) % HASHSIZE;
}

