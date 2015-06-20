#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Util.h"

typedef struct BiNode{
    BiTreeElemType data;
    struct BiNode *lchild;
    struct BiNode *rchild;
    struct BiNode *parent;
    BiNode(int data = 0){
        data = data;
        lchild = NULL;
        rchild = NULL;
        parent = NULL;
    }
} BiNode;

class BinaryTree
{
private:
    BiNode *root;
public:
    BinaryTree();
    ~BinaryTree();
    void init();
    void createBibaryTree();
    void preinCreateBinaryTree(BiTreeElemType *pre_data, BiTreeElemType *in_data, int nums);
    void postinCreateBinaryTree(BiTreeElemType *post_data, BiTreeElemType *in_data, int nums);
    bool isEmpty();
    void getNodeInfo(int& depth, int& allNodeNums, int& leafNodeNums);
    BiNode* getRoot();
    BiNode* findNode(BiTreeElemType data);
    BiTreeElemType getNodeData(BiNode *node);
    void setNodeData(BiNode *node, BiTreeElemType data);
    BinaryTree *getChildTree(LR lr);
    BiNode* getNodeParent(BiNode *node);
    BiNode* getNodeChild(BiNode *node, LR lr);
    BiNode* getNodeSibling(BiNode *node, LR &lr);
    void insertChildNode(BiNode *node, LR lr, BiTreeElemType data);
    BiTreeElemType deleteChildNode(BiNode *node, LR lr);
    void preOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType **data);
    void inOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType **data);
    void postOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType **data);
    void levelOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType **data);
    void show();
};

#endif