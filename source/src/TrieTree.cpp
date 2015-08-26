#include "../inc/TrieTree.h"


TrieTree::TrieTree() {
    root = new TrieNode;
    root->kind = BRANCH;
    root->level = 1;
    root->parent = NULL;
    root->bh.num = 0;
    for (UInt32 i = 0; i < 27; ++i)
        root->bh.ptr[i] = NULL;
}

TrieTree::~TrieTree() {
    queue<TrieNode*> tr_queue;
    TrieNode* node;
    if (root)   tr_queue.push(root);
    while (!tr_queue.empty()) {
        node = tr_queue.front();
        tr_queue.pop();
        if (node->kind == BRANCH) {
            for (UInt32 i = 0; i < 27; ++i) {
                if (node->bh.ptr[i]) {
                    tr_queue.push(node->bh.ptr[i]);
                }
            }
        } else {
            if(node->lf.key)  delete node->lf.key;
            if(node->lf.info) delete node->lf.info;
        }
        delete node;
    }
}

UInt32 TrieTree::charToInt(TrieType symbol) {
    if (symbol == '\0')  return 0;
    else if (symbol >= 'A' && symbol <= 'Z')    return symbol - 'A' + 1;
    else {
        ferr << "�Ƿ��ַ���ֻ����A~Z" << endl;
        exit(ERROR);
    }
}

TrieType TrieTree::intToChar(UInt32 index) {
    if (index == 0) return '\0';
    else if (index >= 1 && index <= 26) return TrieType('A' + index - 1);
    else {
        ferr << "�Ƿ��ַ�������ֻ����0~26" << endl;
        exit(ERROR);
    }
}

TrieNode* TrieTree::searchTrie(TrieType* key) {
    TrieNode *node = root, *parent = NULL;
    UInt32 index;
    TrieType *tmp_key = key;
    while (node && node->kind == BRANCH) {
        index = charToInt(*tmp_key++);
        parent = node;
        node = node->bh.ptr[index];
    }
    if (node) {
        if (!strcmp(node->lf.key + node->level - 1, tmp_key)) {
            return node;
        } else {
            insertTrie(parent, tmp_key - 1, key);
            return parent;
        }
    } else {
        insertTrie(parent, tmp_key - 1, key);
        return parent;
    }
}

void TrieTree::insertTrie(TrieNode* node, TrieType* tmp_key, TrieType* key) {
    UInt32 index = charToInt(*tmp_key);
    TrieNode* new_node = new TrieNode;
    if (!node->bh.ptr[index]) {
        new_node->kind = LEAF;
        new_node->level = node->level + 1;
        new_node->parent = node;
        new_node->lf.size = strlen(key);
        new_node->lf.key = new TrieType[new_node->lf.size + 1];
        memcpy(new_node->lf.key, key, sizeof(TrieType)* new_node->lf.size);
        new_node->lf.key[new_node->lf.size] = '\0';
        new_node->lf.info = NULL;
        node->bh.ptr[index] = new_node;
        ++(node->bh.num);
    } else {
        tmp_key += 1;
        TrieType *old_key = node->bh.ptr[index]->lf.key;
        TrieType *tmp_old_key = old_key + +(tmp_key - key);
        delete node->bh.ptr[index];
        while (*tmp_old_key == *tmp_key) {
            node->bh.ptr[index] = new_node;
            new_node->kind = BRANCH;
            new_node->level = node->level + 1;
            new_node->parent = node;
            new_node->bh.num = 1;
            memset(new_node->bh.ptr, 0, sizeof(TrieNode*)* 27);
            index = charToInt(*tmp_key);
            ++tmp_key;
            ++tmp_old_key;
            node = new_node;
            new_node = new TrieNode;
        }
        node->bh.ptr[index] = new_node;
        new_node->kind = BRANCH;
        new_node->level = node->level + 1;
        new_node->parent = node;
        new_node->bh.num = 2;
        memset(new_node->bh.ptr, 0, sizeof(TrieNode*)* 27);
        node = new_node;
        node->bh.ptr[charToInt(*tmp_old_key)] = new_node = new TrieNode;
        new_node->kind = LEAF;
        new_node->level = node->level + 1;
        new_node->parent = node;
        new_node->lf.size = strlen(old_key);
        new_node->lf.key = old_key;
        new_node->lf.info = NULL;
        node->bh.ptr[charToInt(*tmp_key)] = new_node = new TrieNode;
        new_node->kind = LEAF;
        new_node->level = node->level + 1;
        new_node->parent = node;
        new_node->lf.size = strlen(key);
        new_node->lf.key = new TrieType[new_node->lf.size + 1];
        memcpy(new_node->lf.key, key, sizeof(TrieType)* new_node->lf.size);
        new_node->lf.key[new_node->lf.size] = '\0';
        new_node->lf.info = NULL;
    }
}
