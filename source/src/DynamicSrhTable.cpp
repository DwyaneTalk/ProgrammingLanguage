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

UInt32 DynamicSrhTable::newElem(SearchType key) {
    if (size < max_size) {
        data[size] = key;
    } else {
        data = (SearchType*) renew(data, size, INCREMENT, sizeof(SearchType));
        max_size += INCREMENT;
        data[size] = key;
    }
    return size++;
}

void DynamicSrhTable::delElem(UInt32 index) {
    data[index] = NULL_DATA;
    --size;
}

Int32 DynamicSrhTable::search(DynFindType f_type, SearchType key) {
    BiNode *node;
    Int32 index;
    switch (f_type) {
    case BST:
        index = bstSearch(key, node);
        if (index < 0) {
            bstInsert(node, newElem(key));
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
            delElem(index);
            bstDelete(node, index);
        } else {
            cout << "要删除的结点没有找到！" << endl;
        }
        break;
    }
}

Int32 DynamicSrhTable::bstSearch(SearchType key, BiNode *&node) {
    if (!bin_sort_tree) {
        bin_sort_tree = new BinaryTree;
    }
    BiNode *cur_node = bin_sort_tree->getRoot();
    node = NULL;
    while (cur_node) {
        if (data[cur_node->data] == key) {
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
        if (bin_sort_tree->getRoot()) {
            ferr << "无效的插入位置" << endl;
            exit(ERROR);
        } else {
            BiNode *new_node = new BiNode(index);
            *(bin_sort_tree->getRootPoint()) = new_node;
            return new_node;
        }
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
    if (!node && !bin_sort_tree->getRoot()) {
        ferr << "无效的删除结点" << endl;
        exit(ERROR);
    } else {
        BiNode *del_node, **cld_node;
        if (!node) {
            cld_node = bin_sort_tree->getRootPoint();
            del_node = *cld_node;
        } else {
            if (node->lchild && node->lchild->data == index) {
                cld_node = &node->lchild;
                del_node = node->lchild;
            } else if (node->rchild && node->rchild->data == index) {
                cld_node = &node->rchild;
                del_node = node->rchild;
            } else {
                ferr << "非法的删除结点操作" << endl;
                exit(ERROR);
            }
        }
        if (!del_node->lchild) {
            *cld_node = del_node->rchild;
            delete del_node;
        } else if (!del_node->rchild) {
            *cld_node = del_node->lchild;
            delete del_node;
        } else {
            BiNode *t_node = del_node->lchild;
            node = del_node;
            while (t_node->rchild) {
                node = t_node;
                t_node = t_node->rchild;
            }
            del_node->data = t_node->data;
            bstDelete(node, t_node->data);
        }
    }
}

void DynamicSrhTable::traverse(void(*visit)(SearchType &e)) {
    UInt32 length = size;
    for (UInt32 i = 0; i < length; ++i) {
        if (data[i] != NULL_DATA)
            visit(data[i]);
        else
            ++length;
    }
    cout << endl;
    bin_sort_tree->show(0);
}

void DynamicSrhTable::visit(SearchType &e) {
    cout << e << " ";
}