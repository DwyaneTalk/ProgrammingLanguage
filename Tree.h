#ifndef TREE_H
#define TREE_H

#include "Util.h"
#include<queue>
#include<stack>

typedef struct ChildNode {
    UInt32              index;
    struct ChildNode*   next;
}ChildNode;

typedef struct TreeNode {
    TreeElemType    e;
    UInt32          parent_idx;
    ChildNode*      child_list;
}TreeNode;

class Tree{
private:
    TreeNode*   base;
    UInt8       root_idx;
    UInt8       node_nums;
    UInt8       max_nums;

public:
    Tree();
    ~Tree();
    void init();
    void Tree::renewSpace();
    void createTree();
    bool isEmpty();
    void getTreeInfo(UInt8 &depth, UInt8 &all_nums, UInt8 &leaf_nums);
    TreeNode* getRoot();
    TreeNode* getTreeNode(TreeElemType e);
    TreeElemType getNodeData(TreeNode* node);
    void setNodeData(TreeNode* node, TreeElemType e);
    TreeNode* getParent();
    TreeNode* getChild(TreeNode* node, UInt8 index);
    TreeNode* getSbling(TreeNode* node, LR lr);
    void InsertChild(TreeNode* node, TreeElemType e);
    TreeElemType deleteChild(TreeNode* node, UInt8 index);
    TreeElemType deleteNode(TreeNode* node);
    void DFSTraverse(void(*visit)(TreeElemType& e), TreeElemType *data);
    void BFSTraverse(void(*visit)(TreeElemType& e), TreeElemType *data);
    void show(UInt8 depth);
    void visit(TreeElemType& e);
};

#endif