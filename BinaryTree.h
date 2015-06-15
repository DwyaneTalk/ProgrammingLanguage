#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Util.h"

typedef int ElemType;

typedef struct BiNode{
    ElemType data;
    struct BiNode *lchild;
    struct BiNode *rchild;
    struct BiNode *parent;
} BiNode;

class BinaryTree
{
private:
    BiNode *root;
    int leavesNodeNums;
    int allNodeNums;
public:
    BinaryTree();
    BinaryTree(ElemType *data, int nums);
    ~BinaryTree();
    void init();
    void createBibaryTree(ElemType *data, int nums);
    void preinCreateBinaryTree(ElemType *pre_data, ElemType *in_data, int nums);
    void postinCreateBinaryTree(ElemType *post_data, ElemType *in_data, int nums);
    bool isEmpty();
    int getDepth();
    BiNode* getRoot();
    int getAllNodeNums();
    int getLeafNodeNums();
    BiNode* findNode(ElemType data);
    ElemType getNodeData(BiNode *node);
    void setNodeData(BiNode *node, ElemType data);
    BiNode* getNodeParent(BiNode *node);
    BiNode* getNodeLChild(BiNode *node);
    BiNode* getNodeRChild(BiNode *node);
    BiNode* getNodeLSibling(BiNode *node);
    BiNode* getNodeRSibling(BiNode *node);
    void insertChildNode(BiNode *node, LR lr, ElemType data);
    ElemType deleteChildNode(BiNode *node, LR lr);
    void preOrderTraverse(void(*visit)(ElemType &e), ElemType *data);
    void inOrderTraverse(void(*visit)(ElemType &e), ElemType *data);
    void postOrderTraverse(void(*visit)(ElemType &e), ElemType *data);
    void levelOrderTraverse(void(*visit)(ElemType &e), ElemType *data);
    void shwo();
};

#endif