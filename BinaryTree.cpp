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
    node->data = data;
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
    if (!node) {
        cout << "无效的二叉树插入节点" << endl;
        exit(ERROR);
    }
    if (lr == LEFT) {
        if (node->lchild) {
            node->lchild->data = data;
        } else {
            node->lchild = new BiNode(data);
            node->lchild->parent = node;
        }
    } else {
        if (node->rchild) {
            node->rchild->data = data;
        } else {
            node->rchild = new BiNode(data);
            node->rchild->parent = node;
        }
    }
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

void BinaryTree::preOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType **data) {
    if (root) {
        **data = root->data;
        visit(root->data);
        (*data)++;
        BinaryTree *lChildTree = getChildTree(LEFT), *rChildTree = getChildTree(RIGHT);
        lChildTree->preOrderTraverse(visit, data);
        rChildTree->preOrderTraverse(visit, data);
    }
}

void BinaryTree::inOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType **data) {
    if (root) {
        BinaryTree *lChildTree = getChildTree(LEFT), *rChildTree = getChildTree(RIGHT);
        lChildTree->inOrderTraverse(visit, data);
        **data = root->data;
        visit(root->data);
        (*data)++;
        rChildTree->inOrderTraverse(visit, data);
    }
}

void BinaryTree::postOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType **data) {
    if (root) {
        BinaryTree *lChildTree = getChildTree(LEFT), *rChildTree = getChildTree(RIGHT);
        lChildTree->postOrderTraverse(visit, data);
        rChildTree->postOrderTraverse(visit, data);
        **data = root->data;
        visit(root->data);
        (*data)++;
    }
}

void BinaryTree::levelOrderTraverse(void(*visit)(BiTreeElemType &e), BiTreeElemType **data) {

}

void BinaryTree::show() {

}
