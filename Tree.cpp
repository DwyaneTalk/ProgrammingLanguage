#include "Tree.h"

Tree::Tree() {
    if (base = new TreeNode[INIT_SIZE]) {
        root_idx = -1;
        node_nums = 0;
        max_nums = INIT_SIZE;
    } else {
        cout << "内存申请失败！" << endl;
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

void Tree::createTree() {
    queue<UInt8> queue;
    TreeElemType e;
    UInt8 idx;
    ChildNode **child_node;
    fin >> e;
    if (e) {
        if (node_nums >= max_nums) {
            base = (TreeNode *) renew(base, max_nums, INCREMENT, sizeof(TreeNode));
            max_nums += INCREMENT;
        }
        base[node_nums].e = e;
        base[node_nums].parent_idx = -1;
        base[node_nums].child_list = NULL;
        root_idx = node_nums;
        queue.push(node_nums);
        ++node_nums;
        while (!queue.empty()) {
            idx = queue.front();
            queue.pop();
            child_node = &(base[idx].child_list);
            fin >> e;
            while (e) {
                if (node_nums >= max_nums) {
                    base = (TreeNode*)renew(base, max_nums, INCREMENT, sizeof(TreeNode));
                    max_nums += INCREMENT;
                }
                base[node_nums].e = e;
                base[node_nums].parent_idx = idx;
                base[node_nums].child_list = NULL;
                *child_node = new ChildNode(node_nums);
                child_node = &((*child_node)->next);
                queue.push(node_nums);
                ++node_nums;
                fin >> e;
            }
        }
    }
}

bool Tree::isEmpty() {
    return !node_nums;
}

void Tree::getTreeInfo(UInt8 &depth, UInt8 &all_nums, UInt8 &leaf_nums) {

}

TreeNode* Tree::getRoot() {
    return base + root_idx;
}

TreeNode* Tree::getTreeNode(TreeElemType e) {
    for (UInt8 i = 0; i < node_nums; ++i) {
        if (base[i].e == e) {
            return base + i;
        }
    }
    return NULL;
}

TreeElemType Tree::getNodeData(TreeNode* node) {
    if(node)    return node->e;
    cout << "无效的操作结点" << endl;
    exit(ERROR);
}

void Tree::setNodeData(TreeNode* node, TreeElemType e) {
    if (node)   node->e = e;
    cout << "无效的操作结点" << endl;
    exit(ERROR);
}

TreeNode* Tree::getParent(TreeNode* node) {
    if (node)   return base + node->parent_idx;
    cout << "无效的操作结点" << endl;
    exit(ERROR);
}

TreeNode* Tree::getChild(TreeNode* node, UInt8 index) {
    if (node) {
        UInt8 i = 1;
        ChildNode *child_node = node->child_list;
        while (i < index && child_node) {
            child_node = child_node->next;
        }
        if (child_node)     return base + child_node->index;
        cout << "该结点孩子结点数少于：" << index << endl;
        exit(ERROR);
    }
    cout << "无效的操作结点" << endl;
    exit(ERROR);
}

TreeNode* Tree::getSbling(TreeNode* node, LR lr) {
    if (node) {
        TreeNode *parent_node = getParent(node);
        ChildNode *child_node = parent_node->child_list;
        if (lr == LEFT) {
            if (!child_node) {
                cout << "树结构出错！" << endl;
                exit(ERROR);
            }
            while (child_node->next && base[child_node->next->index].e != node->e) {
                child_node = child_node->next;
            }
            if (child_node->next)   return base + child_node->index;
        } else {
            while (child_node && base[child_node->index].e != node->e) {
                child_node = child_node->next;
            }
            if (child_node->next)   return base + child_node->next->index;
        }
        cout << "该结点没有相应的兄弟结点" << endl;
        exit(ERROR);
    }
    cout << "无效的操作结点" << endl;
    exit(ERROR);
}

UInt8 Tree::getChildIndex(TreeNode* node, TreeElemType e) {
    UInt8 index = 1;
    ChildNode* child_node = node->child_list;
    while (child_node && base[child_node->index].e != e) {
        child_node = child_node->next;
        ++index;
    }
    if (child_node)     return index;
    else                return -1;
}

void Tree::InsertChild(TreeNode* node, TreeElemType e) {
    if (node) {
        if (node_nums >= max_nums) {
            base = (TreeNode*)renew(base, max_nums, INCREMENT, sizeof(TreeNode));
            max_nums += INCREMENT;
        }
        base[node_nums].e = e;
        base[node_nums].parent_idx = node - base;
        base[node_nums].child_list = NULL;
        if (!node->child_list) {
            if (!(node->child_list = new ChildNode(node_nums))) {
                cout << "申请内存失败！" << endl;
                exit(OVER);
            }
        } else {
            ChildNode* child_node = node->child_list;
            while (child_node->next)    child_node = child_node->next;
            if (!(child_node->next = new ChildNode(node_nums))) {
                cout << "申请内存失败！" << endl;
                exit(OVER);
            }
        }
        ++node_nums;
    } else {
        cout << "无效的操作结点" << endl;
        exit(ERROR);
    }
}

TreeElemType Tree::deleteChild(TreeNode* node, UInt8 index) {
    if (node) {
        ChildNode* free_node;
        TreeElemType e;
        UInt8 free_idx;
        if (index == 1) {
            if (!node->child_list) {
                cout << "该结点孩子结点数少于：" << index << endl;
                exit(ERROR);
            }
            free_node = node->child_list;
            free_idx = free_node->index;
            node->child_list = free_node->next;
            delete free_node;
        } else {
            UInt8 idx = 2;
            ChildNode* child_node = node->child_list;
            while (idx < index && child_node->next) {
                child_node = child_node->next;
            }
            if (child_node) {
                free_node = child_node->next;
                free_idx = free_node->index;
                child_node->next = free_node->next;
                delete free_node;
            } else {
                cout << "该结点孩子结点数少于：" << index << endl;
                exit(ERROR);
            }
        }
        UInt8 start_idx = free_idx + 1;
        e = base[free_idx].e;
        while (start_idx < node_nums && start_idx > 0) {
            base[start_idx - 1] = base[start_idx];
        }
        --node_nums;
        return e;
    } else {
        cout << "无效的操作结点" << endl;
        exit(ERROR);
    }
}

TreeElemType Tree::deleteNode(TreeNode* node) {
    UInt8 index = getChildIndex(getParent(node), node->e);
    return deleteChild(getParent(node), index);
}

void Tree::DFSTraverse(void(*visit)(TreeElemType& e), TreeElemType *data) {

}
void Tree::BFSTraverse(void(*visit)(TreeElemType& e), TreeElemType *data) {

}
void Tree::show() {
    queue<UInt8> queue;
    UInt8   index;
    ChildNode* child_node;
    cout << "树的结点存储结构如下：" << endl;
    if (node_nums)  queue.push(root_idx);
    while (!queue.empty()) {
        index = queue.front();
        queue.pop();
        cout << "元素" << base[index].e << "; 孩子 ";
        child_node = base[index].child_list;
        while (child_node) {
            cout << "->" << base[child_node->index].e;
            queue.push(child_node->index);
            child_node = child_node->next;
        }
        cout << "->Null" << endl;
    }
}

void visit(TreeElemType& e) {
    // to something you want
}
