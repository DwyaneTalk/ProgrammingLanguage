#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::~BinaryTree() {
}

void BinaryTree::init() {
    if (root) {
        BinaryTree *leftTree = getLeftChildTree(), *rightTree = getRightChildTree();
        leftTree->init();
        rightTree->init();
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

}

int BinaryTree::getDepth() {

}

BiNode *getRoot() {

}

int BinaryTree::getAllNodeNums() {

}

int BinaryTree::getLeafNodeNums() {

}

BiNode* findNode(BiTreeElemType data) {

}

BiTreeElemType BinaryTree::getNodeData(BiNode *node) {

}

void BinaryTree::setNodeData(BiNode *node, BiTreeElemType data) {

}

BinaryTree* BinaryTree::getLeftChildTree() {

}

BinaryTree* BinaryTree::getRightChildTree() {

}

BiNode* BinaryTree::getNodeParent(BiNode *node) {

}

BiNode* BinaryTree::getNodeLChild(BiNode *node) {

}

BiNode* BinaryTree::getNodeRChild(BiNode *node) {

}

BiNode* BinaryTree::getNodeLSibling(BiNode *node) {

}

BiNode* BinaryTree::getNodeRSibling(BiNode *node) {

}

void BinaryTree::insertChildNode(BiNode *node, LR lr, BiTreeElemType data){

}

BiTreeElemType BinaryTree::deleteChildNode(BiNode *node, LR lr) {

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
