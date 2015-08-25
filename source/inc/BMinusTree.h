#ifndef BMINUSTREE_H
#define BMINUSTREE_H

#include "Util.h"
#include<stack>

#define m   3

typedef struct KeyInfo{
    // other information

} KeyInfo;

typedef struct Key {
    BTreeType value;
    KeyInfo*  info;
    Key(BTreeType value = 0, KeyInfo *info = NULL) {
        this->value = value;
        this->info = info;
    }
} Key; 

typedef struct BTreeNode {
    int key_num;
    BTreeNode*   parent;
    Key*     key[m + 1]; //key[0]����
    BTreeNode*   child[m + 1];  //�����һ���ռ䣬���ڷ��ѽ��֮ǰ���ݴ�ռ�
    BTreeNode(BTreeNode *parent = NULL) {
        this->key_num = 0;
        this->parent = parent;
        for (UInt32 i = 1; i <= m; ++i) {
            this->key[i] = new Key;
        }
        for (UInt32 i = 0; i <= m; ++i) {
            this->child[i] = NULL;
        }
    }
} BTreeNode;

typedef struct Location {
    BTreeNode*   node;
    int     idx;
    bool    tag;
    Location(BTreeNode *node = NULL, int idx = 0, bool tag = false) {
        this->node = node;
        this->idx  = idx;
        this->tag  = tag;
    }
}Location;

class BMinusTree {
private:
    BTreeNode* root;
    int rank;
    Int32 searchInNode(BTreeNode *node, BTreeType key_value);
    void  insertInNode(Location *loc, Key* key, BTreeNode* child);
    Key*  splitNode(BTreeNode* node, Location* loc, BTreeNode* &new_node);
public:
    BMinusTree();
    ~BMinusTree();
    Location* searchKey(BTreeType key_value);
    void insertKey(Location* loc, Key* key);
    BTreeType deleteKey(Location* res);
};

#endif  //DMINUSTREE_H