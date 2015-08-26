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
    cout << "����ͼ���Կ�ʼ��" << endl;
    d_graph.createGraph();
    d_graph.show();
    d_graph.init();
    d_graph.show();
    d_graph.createGraph();
    d_graph.show();
    GType   type = d_graph.getType();
    UInt32  vex_nums = d_graph.getVexNums();
    UInt32  arc_nums = d_graph.getArcNums();
    bool    is_empty = d_graph.isEmpty();
    cout << "����ͼ�Ļ�����Ϣ��type(" << type << ") vex_nums(" << vex_nums << ") arc_nums(" << arc_nums << ") empty(" << is_empty << ")" << endl;
    VexType ori_data = 'C', new_data = 'E';
    DVex* vex = d_graph.locateVex(ori_data);
    ori_data = d_graph.getVexData(vex);
    d_graph.setVexData(vex, new_data);
    new_data = d_graph.getVexData(vex);
    DVex *first_vex, *second_vex;
    VexType first_data, second_data;
    UInt32 in_degree, out_degree;
    first_vex = d_graph.adjVex(vex, NULL);
    second_vex = d_graph.adjVex(vex, first_vex);
    first_data = d_graph.getVexData(first_vex);
    second_data = d_graph.getVexData(second_vex);
    in_degree = d_graph.getVexInDegree(vex);
    out_degree = d_graph.getVexOutDegree(vex);
    cout << "���������" << ori_data << " " << new_data << " " << first_data << " " << second_data << " " << in_degree << " " << out_degree << endl;
    DVex* new_vex = d_graph.insertVex(ori_data);
    d_graph.show();
    d_graph.insertArc(new_vex, vex, 8);
    d_graph.insertArc(new_vex, first_vex, 9);
    d_graph.insertArc(second_vex, new_vex, 10);
    DArc* arc = d_graph.locateArc(second_vex, first_vex);
    d_graph.setArcValue(arc, 15);
    d_graph.show();
    d_graph.deleteArc(second_vex, first_vex);
    d_graph.show();
    DVex* delete_vex = d_graph.locateVex('B');
    d_graph.deleteVex(delete_vex);
    d_graph.show();
    type = d_graph.getType();
    vex_nums = d_graph.getVexNums();
    arc_nums = d_graph.getArcNums();
    is_empty = d_graph.isEmpty();
    cout << "����ͼ�Ļ�����Ϣ��type(" << type << ") vex_nums(" << vex_nums << ") arc_nums(" << arc_nums << ") empty(" << is_empty << ")" << endl;
    cout << "��ȱ��������";
    d_graph.DFSTraverse(DGraph::visit);
    cout << endl << "��ȱ��������";
    d_graph.BFSTraverse(DGraph::visit);
    cout << endl;
}

void Test::testUDGraph() {
    cout << "����ͼ���Կ�ʼ��" << endl;
    ud_graph.createGraph();
    ud_graph.show();
    ud_graph.init();
    ud_graph.show();
    ud_graph.createGraph();
    ud_graph.show();
    GType   type = ud_graph.getType();
    UInt32  vex_nums = ud_graph.getVexNums();
    UInt32  arc_nums = ud_graph.getArcNums();
    bool    is_empty = ud_graph.isEmpty();
    cout << "����ͼ�Ļ�����Ϣ��type(" << type << ") vex_nums(" << vex_nums << ") arc_nums(" << arc_nums << ") empty(" << is_empty << ")" << endl;
    VexType ori_data = 'C', new_data = 'E';
    UVex* vex = ud_graph.locateVex(ori_data);
    ori_data = ud_graph.getVexData(vex);
    ud_graph.setVexData(vex, new_data);
    new_data = ud_graph.getVexData(vex);
    UVex *first_vex, *second_vex;
    VexType first_data, second_data;
    first_vex = ud_graph.firstVex(vex);
    second_vex = ud_graph.nextVex(vex, first_vex);
    first_data = ud_graph.getVexData(first_vex);
    second_data = ud_graph.getVexData(second_vex);
    cout << "���������" << ori_data << " " << new_data << " " << first_data << " " << second_data << endl;
    UVex* new_vex = ud_graph.insertVex(ori_data);
    ud_graph.show();
    ud_graph.insertArc(new_vex, vex, 3);
    ud_graph.insertArc(new_vex, first_vex, 5);
    ud_graph.insertArc(new_vex, second_vex, 4);
    ud_graph.deleteArc(first_vex, second_vex);
    ud_graph.show();
    UVex* delete_vex = ud_graph.locateVex('B');
    ud_graph.deleteVex(delete_vex);
    ud_graph.show();
    cout << "��ȱ��������";
    ud_graph.DFSTraverse(UDGraph::visit);
    cout << endl << "��ȱ��������";
    ud_graph.BFSTraverse(UDGraph::visit);
    cout << endl;
}

void Test::testDGraphApp() {
    cout << "����ͼӦ�ò��Կ�ʼ��" << endl;
    d_graph.createGraph();
    d_graph.show();
    d_graph.weaklyConnectedCompnent();
    d_graph.strongConnectedCompnent();
    UInt32 vex_nums = d_graph.getVexNums();
    VexType* topo_order = d_graph.topoLogicalSort();
    if (!topo_order)    cout << "����ͼ���ڻ����޷�������������" << endl;
    else {
        cout << "����һ����������";
         for (UInt32 i = 0; i < vex_nums; ++i)   cout << " " << topo_order[i];
        cout << endl;
        delete topo_order;
    }
    DArc *path = d_graph.criticalPath();
    cout << "�ؼ�·�����£�" << endl;
    while (path) {
        cout << (UInt32)path->tidx << " " << (UInt32)path->hidx << " " << path->value << endl;
        path = path->tlink;
    }
    VexType data = 'A';
    UInt32 **path_len = d_graph.dijkstraShortestPath(data);
    cout << "��Դ("<< data <<")���·����" << endl;
    for (UInt32 i = 0; i < vex_nums; ++i) {
        if (path_len[0][i] == NULL_ARC)
            cout << path_len[1][i] << " x" << endl;
        else
            cout << path_len[1][i] << " " << path_len[0][i] << endl;
    }
    delete path_len;
    UInt32 ***path_mat = d_graph.floydShortestPath();
    cout << "������������·����" << endl;
    for (UInt32 i = 0; i < vex_nums; ++i) {
        for (UInt32 j = 0; j < vex_nums; ++j) {
            if (path_mat[0][i][j] == NULL_ARC)
                cout << "x(" << path_mat[1][i][j] << ") ";
            else
                cout << path_mat[0][i][j] << "(" << path_mat[1][i][j] << ") ";
        }
        delete path_mat[0][i];
        delete path_mat[1][i];
        cout << endl;
    }
    delete path_mat[0];
    delete path_mat[1];
    delete path;
}

void Test::testUDGraphApp() {
    cout << "����ͼӦ�ò��Կ�ʼ��" << endl;
    ud_graph.createGraph();
    ud_graph.show();
    cout << "��ȱ��������";
    ud_graph.DFSTraverse(UDGraph::visit);
    cout << endl;
    cout << "��ȱ��������";
    ud_graph.BFSTraverse(UDGraph::visit);
    cout << endl;
    ud_graph.connectedCompnent();
    cout << "������������ɭ�ֲ�������" << endl;
    Tree* tree = ud_graph.SpanTree();
    tree->show();
    delete tree;
    cout << "prim��С��������������" << endl;
    tree = ud_graph.primMinSpanTree();
    tree->show();
    delete tree;
    cout << "kruskal��С��������������" << endl;
    tree = ud_graph.KruskalMinSpanTree();
    tree->show();
    delete tree;
    ud_graph.articulationPoint();
}

void Test::testStaSrhTable() {
    sta_srh_table.traverse(StaticSrhTable::visit);
    SearchType key = 13;
    Int32 key_idx;
    StaFindType f_type = SEQ;
    key_idx = sta_srh_table.search(f_type, key);
    cout << "˳����ң�" << endl;
    if (key_idx >= 0)
        cout << key << "���ҳɹ�,�±�Ϊ" << key_idx << endl;
    else
        cout << key << "����ʧ�ܣ�" << endl;
    key = 29;
    key_idx = sta_srh_table.search(f_type, key);
    if (key_idx >= 0)
        cout << key << "���ҳɹ�,�±�Ϊ" << key_idx << endl;
    else
        cout << key << "����ʧ�ܣ�" << endl;
    f_type = IDX;
    key = 13;
    key_idx = sta_srh_table.search(f_type, key);
    cout << endl << "�ֿ���ң�" << endl;
    if (key_idx >= 0)
        cout << key << "���ҳɹ�,�±�Ϊ" << key_idx << endl;
    else
        cout << key << "����ʧ�ܣ�" << endl;
    key = 29;
    key_idx = sta_srh_table.search(f_type, key);
    if (key_idx >= 0)
        cout << key << "���ҳɹ�,�±�Ϊ" << key_idx << endl;
    else
        cout << key << "����ʧ�ܣ�" << endl;

    f_type = BIN;
    key = 38;
    key_idx = sta_srh_table.search(f_type, key);
    cout << endl << "�۰���ң�" << endl;
    if (key_idx >= 0)
        cout << key << "���ҳɹ�,�±�Ϊ" << key_idx << endl;
    else
        cout << key << "����ʧ�ܣ�" << endl;
    key = 39;
    key_idx = sta_srh_table.search(f_type, key);
    if (key_idx >= 0)
        cout << key << "���ҳɹ�,�±�Ϊ" << key_idx << endl;
    else
        cout << key << "����ʧ�ܣ�" << endl;
    f_type = FIB;
    key = 38;
    key_idx = sta_srh_table.search(f_type, key);
    cout << endl << "쳲��������ң�" << endl;
    if (key_idx >= 0)
        cout << key << "���ҳɹ�,�±�Ϊ" << key_idx << endl;
    else
        cout << key << "����ʧ�ܣ�" << endl;
    key = 39;
    key_idx = sta_srh_table.search(f_type, key);
    if (key_idx >= 0)
        cout << key << "���ҳɹ�,�±�Ϊ" << key_idx << endl;
    else
        cout << key << "����ʧ�ܣ�" << endl;
    f_type = INT;
    key = 38;
    key_idx = sta_srh_table.search(f_type, key);
    cout << endl << "��ֵ���ң�" << endl;
    if (key_idx >= 0)
        cout << key << "���ҳɹ�,�±�Ϊ" << key_idx << endl;
    else
        cout << key << "����ʧ�ܣ�" << endl;
    key = 39;
    key_idx = sta_srh_table.search(f_type, key);
    if (key_idx >= 0)
        cout << key << "���ҳɹ�,�±�Ϊ" << key_idx << endl;
    else
        cout << key << "����ʧ�ܣ�" << endl;
    f_type = STR;
    key = 38;
    key_idx = sta_srh_table.search(f_type, key);
    cout << endl << "���Ų��������ң�" << endl;
    if (key_idx >= 0)
        cout << key << "���ҳɹ�,�±�Ϊ" << key_idx << endl;
    else
        cout << key << "����ʧ�ܣ�" << endl;
    key = 39;
    key_idx = sta_srh_table.search(f_type, key);
    if (key_idx >= 0)
        cout << key << "���ҳɹ�,�±�Ϊ" << key_idx << endl;
    else
        cout << key << "����ʧ�ܣ�" << endl;
}

void Test::testDynSrhTable() {
    SearchType data[70] = { 13, 24, 37, 90, 53, 12, 12, 11, 10, 9 };
    UInt32 size = sizeof(data) / sizeof(SearchType);
    cout << "��ʼ���Զ���������:" << endl;
    DynFindType f_type = BST;
    for (UInt32 i = 0; i < size; ++i) {
        dyn_srh_table.search(f_type, data[i]);
    }
    dyn_srh_table.traverse(f_type, DynamicSrhTable::visit);
    dyn_srh_table.deleteData(f_type, 45);
    dyn_srh_table.traverse(f_type, DynamicSrhTable::visit);
    cout << "��ʼ����ƽ�������������" << endl;
    f_type = BBT;
    dyn_srh_table.init();
    for (UInt32 i = 0; i < 10; ++i) {
        dyn_srh_table.search(f_type, data[i]);
    }
    dyn_srh_table.traverse(f_type, DynamicSrhTable::visit);
}

void Test::testBMinusTree() {
    BTreeType data[] = {45, 24, 53, 90, 3, 12, 37, 50, 61, 70, 100, 30, 26, 85, 7};
    UInt32 size = sizeof(data) / sizeof(BTreeType);
    UInt32 idx;
    BTreeNode *node;
    bool res;
    for (UInt32 i = 0; i < 10; ++i) {
        res = bminus_tree.searchKey(data[i], node, idx);
    }
    BTreeType del_value = 90;
    res = bminus_tree.searchKey(del_value, node, idx);
    Location* loc = new Location(node, idx, res);
    bminus_tree.deleteKey(loc);
}