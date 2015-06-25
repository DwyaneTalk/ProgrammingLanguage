#include "Tree.h"

Tree::Tree() {
    if (base = new TreeNode[INIT_SIZE]) {
        root_idx = -1;
        node_nums = 0;
        max_nums = INIT_SIZE;
    } else {
        cout << "ÄÚ´æÉêÇëÊ§°Ü£¡" << endl;
        exit(OVER);
    }
}

Tree::~Tree(){
    ChildNode* child_node = NULL;
    ChildNode* free_node = NULL;
    for (UInt8 i = 0; i < node_nums; ++i) {
        child_node = base[i].child_list;
        while (child_node) {
            free_node = child_node;
            child_node = child_node->next;
            delete free_node;
        }
    }
    delete base;
    root_idx = -1;
    node_nums = 0;
    max_nums = 0;
}

void Tree::init() {
    ChildNode* child_node = NULL;
    ChildNode* free_node = NULL;
    for (UInt8 i = 0; i < node_nums; ++i) {
        child_node = base[i].child_list;
        while (child_node) {
            free_node = child_node;
            child_node = child_node->next;
            delete free_node;
        }
    }
    root_idx = -1;
    node_nums = 0;
}

void Tree::renewSpace() {
    TreeNode *renew_base;
    if (renew_base = new TreeNode[max_nums + INCREMENT]) {
        memcpy(renew_base, base, max_nums * sizeof(TreeNode));
        base = renew_base;
    } else {
        cout << "ÉêÇëÄÚ´æÊ§°Ü£¡" << endl;
        exit(OVER);
    }
}

void Tree::createTree() {
    queue<UInt8> queue;
    TreeElemType e;
    TreeNode* node;
    fin >> e;
    if (e) {
        if (node_nums >= max_nums) {
            renewSpace();
        }
        base[node_nums].e = e;
        base[node_nums].parent_idx = -1;
        root_idx = node_nums;
        ++node_nums;
        queue.push(node_nums - 1);
        while (true) {

        }
    }
}

bool Tree::isEmpty() {

}
void Tree::getTreeInfo(UInt8 &depth, UInt8 &all_nums, UInt8 &leaf_nums) {

}
TreeNode* Tree::getRoot() {

}
TreeNode* Tree::getTreeNode(TreeElemType e) {

}
TreeElemType Tree::getNodeData(TreeNode* node) {

}
void Tree::setNodeData(TreeNode* node, TreeElemType e) {
}
TreeNode* Tree::getParent() {

}
TreeNode* Tree::getChild(TreeNode* node, UInt8 index) {

}
TreeNode* Tree::getSbling(TreeNode* node, LR lr) {

}
void Tree::InsertChild(TreeNode* node, TreeElemType e) {

}
TreeElemType Tree::deleteChild(TreeNode* node, UInt8 index) {

}
TreeElemType Tree::deleteNode(TreeNode* node) {

}
void Tree::DFSTraverse(void(*visit)(TreeElemType& e), TreeElemType *data) {

}
void Tree::BFSTraverse(void(*visit)(TreeElemType& e), TreeElemType *data) {

}
void Tree::show(UInt8 depth) {

}

void visit(TreeElemType& e) {
    // to something you want
}
