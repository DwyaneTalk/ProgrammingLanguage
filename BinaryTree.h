#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Util.h"

typedef struct BiNode{
    BiTreeElemType data;
    struct BiNode *lchild;
    struct BiNode *rchild;
    struct BiNode *parent;
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
    int getDepth();
    BiNode* getRoot();
    int getAllNodeNums();
    int getLeafNodeNums();
    BiNode* findNode(BiTreeElemType data);
    BiTreeElemType getNodeData(BiNode *node);
    void setNodeData(BiNode *node, BiTreeElemType data);
    BinaryTree *getLeftChildTree();
    BinaryTree *getRightChildTree();
    BiNode* getNodeParent(BiNode *node);
    BiNode* getNodeLChild(BiNode *node);
    BiNode* getNodeRChild(BiNode *node);
    BiNode* getNodeLSibling(BiNode *node);
    BiNode* getNodeRSibling(BiNode *node);
    void insertChildNode(BiNode *node, LR lr, BiTreeElemType data);
    BiTreeElemType deleteChildNode(BiNode *node, LR lr);
    void preOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType *data);
    void inOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType *data);
    void postOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType *data);
    void levelOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType *data);
    void shwo();
};

#endif