#include "../inc/DynamicSrhTable.h"

DynamicSrhTable::DynamicSrhTable() {
    size = 0;
    if (data = new SearchType[INIT_SIZE]) {
        max_size = INIT_SIZE;
        bin_sort_tree = NULL;
    } else {
        ferr << "申请初始内存失败！" << endl;
        exit(OVER);
    }
}

DynamicSrhTable::~DynamicSrhTable() {
    size = 0;
    max_size = 0;
    delete data;
    delete bin_sort_tree;
}

UInt32 DynamicSrhTable::newData(SearchType key) {
    if (size < max_size) {
        data[size] = key;
    } else {
        data = (SearchType*) renew(data, size, INCREMENT, sizeof(SearchType));
        max_size += INCREMENT;
        data[size] = key;
    }
    return size++;
}

Int32 DynamicSrhTable::search(DynFindType f_type, SearchType key) {
    BiNode *node;
    Int32 index;
    switch (f_type) {
    case BST:
        index = bstSearch(key, node);
        if (index < 0) {
            bstInsert(node, newData(key));
        }
        return index;
    }
}

void DynamicSrhTable::deleteData(DynFindType f_type, SearchType key) {
    BiNode *node;
    UInt32 index;
    switch (f_type) {
    case BST:
        index = bstSearch(key, node);
        if (index >= 0) {
            bstDelete(node, index);
        } else {
            cout << "要删除的结点没有找到！" << endl;
        }
        break;
    }
}

Int32 DynamicSrhTable::bstSearch(SearchType key, BiNode *&node) {
    BiNode *cur_node = bin_sort_tree->getRoot();
    node = NULL;
    while (cur_node) {
        if (data[cur_node->data] == key) {
            node = NULL;
            return cur_node->data;
        } else if (data[cur_node->data] < key) {
            node = cur_node;
            cur_node = cur_node->rchild;
        } else {
            node = cur_node;
            cur_node = cur_node->lchild;
        }
    }
    return -1;
}

BiNode* DynamicSrhTable::bstInsert(BiNode *node, UInt32 index) {
    if (!node) {
        ferr << "无效的插入位置" << endl;
        exit(ERROR);
    } else {
        BiNode *new_node = new BiNode(index);
        if (data[node->data] < data[index]) {
            node->rchild = new_node;
        } else {
            node->lchild = new_node;
        }
        return new_node;
    }
}

void DynamicSrhTable::bstDelete(BiNode *node, UInt32 index) {
    if (!node) {
        ferr << "无效的删除结点" << endl;
        exit(ERROR);
    } else {
        if (!node->lchild) {

        } else if(!node->rchild) {

        } else {

        }
    }
}

void DynamicSrhTable::traverse(void(*visit)(SearchType &e)) {

}

void DynamicSrhTable::visit(SearchType &e) {

}