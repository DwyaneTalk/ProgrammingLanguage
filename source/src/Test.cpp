#include "../inc/Test.h"



void Test::testSqList() {
    cout << "˳�����Կ�ʼ����" << endl;
    SqListElemType list[] = { 1, 2, 3, 4 };
    int size = sizeof(list) / sizeof(int);
    for (int i = 0; i < size; ++i)
        sqList.insertElem(list[i], i);
    sqList.show();
    sqList.insertElem(3, 2);
    sqList.show();
    sqList.deleleElem(2);
    sqList.show();
    sqList.replaceElem(3, 1);
    sqList.show();
    sqList.traverse(SqList::visit);
    sqList.show();
    cout << endl;
}

void Test::testLinkList() {
    cout << "������Կ�ʼ����" << endl;
    LinkListElemType list[] = { 1, 2, 3 };
    int size = sizeof(list) / sizeof(LinkListElemType);
    for (int i = 0; i < size; ++i)
        linkList.insertTailElem(list[i]);
    linkList.show();
    for (int i = 0; i < size; ++i)
        linkList.insertHeadElem(list[i]);
    linkList.show();
    for (int i = 0; i < size; ++i)
        linkList.insertElem(list[i], i * 2);
    linkList.show();
    linkList.deleteHeadElem();
    linkList.deleteTailElem();
    linkList.show();
    //linkList.init();
    //linkList.show();
    //linkList.insertHeadElem(1);
    //linkList.show();
    //linkList.deleteHeadElem();
    //linkList.show();
    //linkList.insertTailElem(1);
    //linkList.show();
    //linkList.deleteTailElem();
    //linkList.show();
    linkList.deleteElem(0);
    linkList.deleteElem(linkList.getLength() - 1);
    linkList.show();
    linkList.deleteElem(2);
    linkList.show();
    linkList.replaceElem(9, 1);
    linkList.show();
    cout << "index :" << linkList.getIndex(9) << "   data: " << linkList.getElem(linkList.getIndex(9)) << endl;
    linkList.traverse(LinkList::visit);
    linkList.show();
    cout << endl;
}

void  Test::testStack() {
    cout << "ջ���Կ�ʼ����" << endl;
    StackElemType list[3] = { 1, 2, 3 };
    int size = sizeof(list) / sizeof(StackElemType);
    stack.push(1);
    stack.show();
    cout << "ջ��Ԫ�أ�" << stack.getTop() << endl;
    stack.pop();
    stack.show();
    for (int i = 0; i < size; ++i)
        stack.push(list[i]);
    stack.show();
    stack.pop();
    stack.traverse(Stack::visit);
    stack.show();
    cout << endl;
}

void Test::testQueue() {
    cout << "���в��Կ�ʼ����" << endl;
    QueueElemType list[3] = { 1, 2, 3 };
    int size = sizeof(list) / sizeof(QueueElemType);
    queue.enQueue(1);
    queue.show();
    cout << "����Ԫ�أ�" << queue.getHead() << endl;
    queue.deQueue();
    queue.show();
    for (int i = 0; i < size; ++i)
        queue.enQueue(list[i]);
    queue.show();
    queue.deQueue();
    stack.traverse(Queue::visit);
    queue.show();
}

void Test::testBinaryTree() {
    cout << "���������Կ�ʼ����" << endl;
    BiTreeElemType pre_data[MAXELEMNUM], in_data[MAXELEMNUM], post_data[MAXELEMNUM], elem_data[MAXELEMNUM];
    cout << "��������������ʾ����" << endl;
    biTree.createBibaryTree(biTree.getRootPoint(), NULL);
    biTree.show(0);
    int i, nums;
    for (i = 0;; ++i) {
        fin >> pre_data[i];
        if (!pre_data[i]) {
            nums = i;
            break;
        }
    }
    for (i = 0; i <= nums; ++i)
        fin >> in_data[i];
    for (i = 0; i <= nums; ++i)
        fin >> post_data[i];
    biTree.init();
    cout << "�������򴴽�����������ʾ����" << endl;
    biTree.show(0);
    biTree.preinCreateBinaryTree(biTree.getRootPoint(), NULL, pre_data, in_data, nums);
    biTree.show(0);
    cout << "�������򴴽�����������ʾ����" << endl;
    BinaryTree *ptrBiTree = new BinaryTree();
    ptrBiTree->postinCreateBinaryTree(ptrBiTree->getRootPoint(), NULL, post_data, in_data, nums);
    ptrBiTree->show(0);
    delete ptrBiTree;
    int depth, allNodeNums, leafNodeNums;
    biTree.getNodeInfo(depth, allNodeNums, leafNodeNums);
    cout << "��������Ϣ��depth(" << depth << ") allNums(" << allNodeNums << ") leafNums(" << leafNodeNums << ")����" << endl;
    BiTreeElemType data = 4;
    BiNode *node = biTree.findNode(data);
    cout << "��ȡֵΪ4�Ľ�㣬Ԫ��Ϊ��" << biTree.getNodeData(node);
    biTree.setNodeData(node, 8);
    cout << ", ����Ϊ��ֵ��Ϊ��" << biTree.getNodeData(node) << endl;
    biTree.show(0);
    LR lr;
    BiNode *newNode = biTree.getNodeSibling(node, lr);
    cout << "Ԫ�أ�" << biTree.getNodeData(node) << "�Ľ��Ϊ��" << lr << "��㣬�ֵܽ��Ԫ��Ϊ��" << biTree.getNodeData(newNode) << endl;
    biTree.insertChildNode(biTree.getRoot(), LEFT, 4);
    biTree.insertChildNode(biTree.getRoot(), RIGHT, 9);
    biTree.show(0);
    biTree.getNodeInfo(depth, allNodeNums, leafNodeNums);
    cout << "��������Ϣ��depth(" << depth << ") allNums(" << allNodeNums << ") leafNums(" << leafNodeNums << ")����" << endl;
    biTree.deleteChildNode(node, LEFT);
    biTree.show(0);
    biTree.getNodeInfo(depth, allNodeNums, leafNodeNums);
    cout << "��������Ϣ��depth(" << depth << ") allNums(" << allNodeNums << ") leafNums(" << leafNodeNums << ")����" << endl;
    BiTreeElemType *base = elem_data;
    biTree.preOrderTraverse(BinaryTree::visit, &base);
    cout << "������������";
    for (i = 0; i < allNodeNums; ++i)
        cout << elem_data[i] << " ";
    cout << endl;
    base = elem_data;
    biTree.inOrderTraverse(BinaryTree::visit, &base);
    cout << "������������";
    for (i = 0; i < allNodeNums; ++i)
        cout << elem_data[i] << " ";
    cout << endl;
    base = elem_data;
    biTree.postOrderTraverse(BinaryTree::visit, &base);
    cout << "������������";
    for (i = 0; i < allNodeNums; ++i)
        cout << elem_data[i] << " ";
    cout << endl;
    biTree.levelOrderTraverse(BinaryTree::visit, elem_data);
    cout << "������������";
    for (i = 0; i < allNodeNums; ++i)
        cout << elem_data[i] << " ";
    cout << endl;
}

void Test::testTree() {
    cout << "���Ĳ��Կ�ʼ����" << endl;
    tree.createTree();
    tree.show();
    //tree.init();
    //tree.show();
    UInt8 depth, all_nums, leaf_nums;
    tree.getTreeInfo(depth, all_nums, leaf_nums);
    cout << "���Ľ����Ϣ��depth(" << (UInt32)depth << ") all_nums(" << (UInt32)all_nums << ") leaf_nums(" << (UInt32)leaf_nums << ")" << endl;
    TreeNode* tree_node = tree.getRoot();
    TreeElemType node_data = tree.getNodeData(tree_node);
    tree.setNodeData(tree_node, node_data + 1);
    TreeNode* child_node = tree.getChild(tree_node, 2);
    TreeNode* sbling_node = tree.getSbling(child_node, LEFT);
    TreeNode* parent_node = tree.getParent(sbling_node);
    UInt8 child_index = tree.getChildIndex(parent_node, 4);
    cout << "�����ز�����Ϣ��" << node_data << " " << tree.getNodeData(child_node) << " " << tree.getNodeData(sbling_node) << " " << tree.getNodeData(parent_node) << " " << (UInt32)child_index << endl;
    tree.setNodeData(parent_node, 1);
    tree.show();
    tree.InsertChild(child_node, 8);
    tree.InsertChild(sbling_node, 9);
    //tree.show();
    tree.deleteChild(sbling_node, 1);
    //tree.show();
    tree.deleteNode(tree.getSbling(child_node, RIGHT));
    tree.show();
    TreeElemType data[MAXELEMNUM];
    tree.BFSTraverse(Tree::visit, data);
    all_nums = tree.getNodeNums();
    cout << "BFS�����Ľ��Ϊ��";
    for (UInt8 i = 0; i < all_nums; ++i) {
        cout << data[i] << " ";                    
    }
    cout << endl;
    tree.DFSTraverse(Tree::visit, data);
    cout << "DFS�����Ľ��Ϊ��";
    for (UInt8 i = 0; i < all_nums; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void Test::testDGraph() {

}

void Test::testUDGraph() {

}