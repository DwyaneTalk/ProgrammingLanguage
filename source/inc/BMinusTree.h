#ifndef BMINUSTREE_H
#define BMINUSTREE_H

#include "Util.h"
#include<queue>

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
    UInt32 key_num;
    BTreeNode*   parent;
    Key*     key[m + 1]; //key[0]不用
    BTreeNode*   child[m + 1];  //多出来一个空间，是在分裂结点之前的暂存空间
    BTreeNode(BTreeNode *parent = NULL) {
        this->key_num = 0;
        this->parent = parent;
        for (UInt32 i = 1; i <= m; ++i) {
            this->key[i] = NULL;
        }
        for (UInt32 i = 0; i <= m; ++i) {
            this->child[i] = NULL;
        }
    }
} BTreeNode;

typedef struct Location {
    BTreeNode*   node;
    UInt32     idx;
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
    UInt32 rank;
    Int32 searchInNode(BTreeNode *node, BTreeType key_value);
    void  insertInNode(Location *loc, Key* key, BTreeNode* child);
    Key*  splitNode(BTreeNode* node, Location* loc, BTreeNode* &new_node);
public:
    BMinusTree();
    ~BMinusTree();
    bool searchKey(BTreeType key_value, BTreeNode* &res_node, UInt32 &res_idx);
    void insertKey(Location* loc, Key* key);
    void deleteKey(Location* res);
};

#endif  //DMINUSTREE_H