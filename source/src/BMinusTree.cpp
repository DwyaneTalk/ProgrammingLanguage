#include "../inc/BMinusTree.h"

BMinusTree::BMinusTree() {
    root = NULL;
    rank = m;
}

BMinusTree::~BMinusTree() {
    stack<BTreeNode*> node_stack;
    BTreeNode *node;
    if (root)   node_stack.push(root);
    while (!node_stack.empty()) {
        node = node_stack.top();
        node_stack.pop();
        for (Int32 i = 0; i <= node->key_num; ++i) {
            node_stack.push(node->child[i]);
        }
        for (Int32 i = 1; i <= node->key_num; ++i) {
            if (node->key[i]) {
                if (node->key[i]->info) {
                    delete node->key[i]->info;
                }
                delete node->key[i];
            }
        }
        delete node;
    }
    rank = 0;
    root = NULL;
}

Int32 BMinusTree::searchInNode(BTreeNode *node, BTreeType key_value) {
    int low = 0, high = node->key_num, mid;
    while (low < high) {
        mid = (low + high + 1) / 2;
        if (node->key[mid]->value == key_value) {
            return mid;
        } else if (node->key[mid]->value < key_value) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

Location* BMinusTree::searchKey(BTreeType key_value) {
    BTreeNode *parent_node = NULL, *node = root;
    Int32 idx;
    while (node) {
        idx = searchInNode(node, key_value);
        if (idx > 0 && idx <= node->key_num && node->key[idx]->value == key_value) {
            return new Location(node, idx, true);
        } else {
            parent_node = node;
            node = node->child[idx];
        }
    }
    return new Location(parent_node, idx, false);
}

void BMinusTree::insertInNode(Location* loc, Key* key, BTreeNode* child) {
    if (loc->tag || !loc->node || !(loc->idx >= 0 && loc->idx <= loc->node->key_num)) {
        BTreeNode *node = loc->node;
        Int32 key_num = node->key_num;
        Int32 idx = loc->idx;
        memcpy(node->key + idx + 2, node->key + 1, sizeof(Key)* (key_num - idx + 1));
        memcpy(node->child + idx + 2, node->child + 1, sizeof(Key)* (key_num - idx + 1));
        node->key[idx] = key;
        node->child[idx] = child;
        if (child)  child->parent = node;
        ++(node->key_num);
    }
}

Key* BMinusTree::splitNode(BTreeNode *node, Location* loc, BTreeNode* &new_node) {
    if (!node || node->key_num < m) {
        ferr << "非法的结点分裂" << endl;
        exit(ERROR);
    }
    int mid = (m + 1) / 2;
    BTreeNode *left_node = new BTreeNode, *right_node = new BTreeNode;
    Key* res_key;

    if (!node->parent)  node->parent = new BTreeNode;

    left_node->key_num = mid - 1;
    for (UInt32 i = 1; i <= left_node->key_num; ++i) {
        left_node->key[i] = node->key[i];
    }
    for (UInt32 i = 0; i <= left_node->key_num; ++i) {
        left_node->child[i] = node->child[i];
    }
    left_node->parent = node->parent;

    right_node->key_num = m - mid;
    for (UInt32 i = 1; i <= right_node->key_num; ++i) {
        right_node->key[i] = node->key[mid + i];
    }
    for (UInt32 i = 0; i <= right_node->key_num; ++i) {
        right_node->child[i] = node->child[mid + i];
    }
    right_node->parent = node->parent;

    new_node = right_node;
    res_key = node->key[mid];
    loc->node = node->parent;
    loc->idx = searchInNode(node->parent, res_key->value);
    loc->tag = false;
    delete node;
    return res_key;
}

void BMinusTree::insertKey(Location* loc, Key* key) {
    if (loc->tag || !loc->node || !(loc->idx >=0 && loc->idx <= loc->node->key_num)) {
        BTreeNode *cur_node = loc->node, *new_node;
        Key* res_key;
        Location *new_loc = new Location;
        // insert key
        insertInNode(loc, key, NULL);
        while (cur_node->key_num >= m) {
            // split
            res_key = splitNode(cur_node, new_loc, new_node);
            insertInNode(new_loc, res_key, new_node);
            cur_node = new_loc->node;
        }
    }
}

BTreeType BMinusTree::deleteKey(Location* loc) {

}