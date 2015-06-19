#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::~BinaryTree() {
}

void BinaryTree::init() {
    if (root) {
        BinaryTree *leftTree = getChildTree(LEFT), *rightTree = getChildTree(RIGHT);
        leftTree->init();
        rightTree->init();
        delete leftTree;
        delete rightTree;
        delete root;
    }
}

void BinaryTree::createBibaryTree() {

}

void BinaryTree::preinCreateBinaryTree(BiTreeElemType *pre_data, BiTreeElemType *in_data, int nums) {

}

void BinaryTree::postinCreateBinaryTree(BiTreeElemType *post_data, BiTreeElemType *in_data, int nums) {

}

bool BinaryTree::isEmpty() {
    return !root;
}

void BinaryTree::getNodeInfo(int& depth, int& allNodeNums, int& leafNodeNums) {

}

BiNode* BinaryTree::getRoot() {
    return root;
}

BiNode* BinaryTree::findNode(BiTreeElemType data) {
    if (root) {
        if (root->data == data) {
            return root;
        }
        BiNode *ansNode;
        BinaryTree *leftree = getChildTree(LEFT);
        ansNode = leftree->findNode(data);
        delete leftree;
        if (!ansNode) {
            BinaryTree *rightTree = getChildTree(RIGHT);
            ansNode = rightTree->findNode(data);
            delete rightTree;
        }
        return ansNode;
    }
   return NULL;
}

BiTreeElemType BinaryTree::getNodeData(BiNode *node) {
    return node->data;
}

void BinaryTree::setNodeData(BiNode *node, BiTreeElemType data) {

}

BinaryTree* BinaryTree::getChildTree( LR lr) {
    if (root) {
        BinaryTree *childTree = new BinaryTree;
        if (lr == LEFT)     childTree->root = root->lchild;
        else                childTree->root = root->rchild;
        return childTree;
    }
    return NULL;
}


BiNode* BinaryTree::getNodeParent(BiNode *node) {
    if (node)   return node->parent;
    else        return NULL;
}

BiNode* BinaryTree::getNodeChild(BiNode *node, LR lr) {
    if (node) {
       if(lr == LEFT)   return node->lchild;
       else             return node->rchild;
    }
    else        return NULL;
}


BiNode* BinaryTree::getNodeSibling(BiNode *node, LR &lr) {
    if (node && node->parent) {
        if (node->parent->lchild == node) {
            lr = LEFT;
            return node->parent->rchild;
        } else {
            lr = RIGHT;
            return node->parent->lchild;
        }
    }
    return NULL;
}


void BinaryTree::insertChildNode(BiNode *node, LR lr, BiTreeElemType data){

}

BiTreeElemType BinaryTree::deleteChildNode(BiNode *node, LR lr) {
    BiTreeElemType ans = 0;
    if (node) {
        BinaryTree *nodeTree = new BinaryTree;
        nodeTree->root = node;
        BinaryTree *childTree = nodeTree->getChildTree(lr);
        ans = getNodeData(getNodeChild(node, lr));
        if (childTree)  childTree->init();
    }
    return ans;
}

void BinaryTree::preOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType *data) {

}

void BinaryTree::inOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType *data) {

}

void BinaryTree::postOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType *data) {

}

void BinaryTree::levelOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType *data) {

}

void BinaryTree::shwo() {

}
