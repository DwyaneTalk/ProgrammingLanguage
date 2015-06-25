#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Util.h"
#include <queue>


typedef struct BiNode{
    BiTreeElemType data;
    struct BiNode *lchild;
    struct BiNode *rchild;
    struct BiNode *parent;
    BiNode(int data = 0){
        this->data = data;
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
    void createBibaryTree(BiNode **root, BiNode *parent);
    void preinCreateBinaryTree(BiNode **root, BiNode *parent, BiTreeElemType *pre_data, BiTreeElemType *in_data, int nums);
    void postinCreateBinaryTree(BiNode **root, BiNode *parent, BiTreeElemType *post_data, BiTreeElemType *in_data, int nums);
    bool isEmpty();
    void getNodeInfo(int& depth, int& allNodeNums, int& leafNodeNums);
    BiNode* getRoot();
    BiNode** getRootPoint();
    BiNode* findNode(BiTreeElemType data);
    void setChildNode(BiNode *node, LR lr, BiNode *newNode);
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
    void levelOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType *data);
    void show(int n);
    void static visit(BiTreeElemType &data);
};

#endif