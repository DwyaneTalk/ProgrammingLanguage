#include "../inc/UDGraph.h"


UDGraph::UDGraph() {
    if ((vexs = new UVex[MAXELEMNUM]) && (arcs = new UArc*[MAXELEMNUM])) {
        for (UInt8 i = 0; i < MAXELEMNUM; ++i) {
            if (!(arcs[i] = new UArc[MAXELEMNUM])) {
                ferr << "申请内存失败！" << endl;
                exit(OVER);
            }
        }
        graph_type  = UDN;
        vex_nums    = 0;
        arc_nums    = 0;
    } else {
        ferr << "申请内存失败！" << endl;
        exit(OVER);
    }
}

UDGraph::~UDGraph() {
    vex_nums = 0;
    arc_nums = 0;
    delete vexs;
    for (UInt8 i = 0; i < MAXELEMNUM; ++i)
        delete arcs[i];
    delete arcs;
}

void    UDGraph::init() {
    vex_nums = 0;
    arc_nums = 0;
}

void    UDGraph::createGraph() {
    fin >> vex_nums >> arc_nums;
    if (vex_nums > MAXELEMNUM) {
        ferr << "图的顶点数超过最大限制！" << endl;
        exit(ERROR);
    }
    for (UInt8 i = 0; i < vex_nums; ++i)
        fin >> vexs[i].data;
    VexType t_vex, h_vex;
    UInt8 t_idx, h_idx;
    for (UInt8 i = 0; i < arc_nums; ++i) {
        fin >> t_vex >> h_vex;
        t_idx = getDataIndex(t_vex);
        h_idx = getDataIndex(h_vex);
        if (t_idx < 0 || h_idx < 0) {
            ferr << "构造图结构出错，不合法的弧存在" << endl;
            exit(ERROR);
        }
        fin >> arcs[t_idx][h_idx].value;
        arcs[h_idx][t_idx].value = arcs[t_idx][h_idx].value;
    }
}

UVex*    UDGraph::locateVex(VexType data) {
    UInt8 index = getDataIndex(data);
    if (index < 0)  return NULL;
    else            return vexs + index;
}

VexType UDGraph::getVexData(UVex* vex) {
    if (vex) {
        return vex->data;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

void    UDGraph::setVexData(UVex* vex, VexType data) {
    if (vex) {
        vex->data = data;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

UInt8   UDGraph::getVexDegree(UVex *vex) {
    UInt8 index = getVexIndex(vex);
    UInt8 degree = 0;
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (arcs[index][i].value != NULL_ARC)   ++degree;
    }
    return degree;
}

UVex*    UDGraph::firstVex(UVex* vex) {
    UInt8 idx = getVexIndex(vex);
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (arcs[idx][i].value != NULL_ARC)  return vexs + i;
    }
    return NULL;
}

UVex*    UDGraph::nextVex(UVex* vex, UVex* cur_vex) {
    if (!cur_vex)   return firstVex(vex);
    UInt8 t_idx = getVexIndex(vex);
    UInt8 h_idx = getVexIndex(cur_vex);
    for (UInt8 i = h_idx + 1; i < vex_nums; ++i) {
        if (arcs[t_idx][i].value != NULL_ARC)    return vexs + i;
    }
    return NULL;
}

UVex*    UDGraph::insertVex(VexType data) {
    if (vex_nums < MAXELEMNUM) {
        vexs[vex_nums++].data = data;
        return vexs + vex_nums - 1;
    } else {
        ferr << "顶点数达到最大，无法添加新的顶点！" << endl;
        exit(ERROR);
    }
}

VexType UDGraph::deleteVex(UVex* vex) {
    if (vex) {
        VexType data = vex->data;
        UArc *tmp_arc;
        UInt8 index = getVexIndex(vex);
        --vex_nums;
        vexs[index] = vexs[vex_nums];
        for (UInt8 i = 0; i <= vex_nums; ++i) {
            if (arcs[index][i].value != NULL_ARC)   --arc_nums;
        }
        tmp_arc = arcs[index];
        arcs[index] = arcs[vex_nums];
        arcs[vex_nums] = tmp_arc;
        for (UInt8 i = 0; i < vex_nums; ++i) {
            arcs[i][index] = arcs[i][vex_nums];
        }
        return data;
    } else {
        ferr << "对空顶点的非法操作！" << endl;
        exit(ERROR);
    }
}

void    UDGraph::insertArc(UVex* t_vex, UVex* h_vex, ArcType arc) {
    if (t_vex && h_vex) {
        UInt8 t_idx = getVexIndex(t_vex);
        UInt8 h_idx = getVexIndex(h_vex);
        if (t_idx >= 0 && h_idx >= 0) {
            arcs[t_idx][h_idx].value = arc;
            arcs[h_idx][t_idx].value = arc;
            ++arc_nums;
        } else {
            ferr << "对空顶点的非法操作！" << endl;
            exit(ERROR);
        }
    } else {
        ferr << "对空顶点的非法操作！" << endl;
        exit(ERROR);
    }
}

ArcType UDGraph::deleteArc(UVex* t_vex, UVex* h_vex) {
    if (t_vex && h_vex) {
        UInt8 t_idx = getVexIndex(t_vex);
        UInt8 h_idx = getVexIndex(h_vex);
        ArcType arc = arcs[t_idx][h_idx].value;
        if (t_idx >= 0 && h_idx >= 0) {
            arcs[t_idx][h_idx].value = NULL_ARC;
            arcs[h_idx][t_idx].value = NULL_ARC;
            --arc_nums;
            return arc;
        } else {
            ferr << "对空顶点的非法操作！" << endl;
            exit(ERROR);
        }
    } else {
        ferr << "对空顶点的非法操作！" << endl;
        exit(ERROR);
    }
}

void    UDGraph::DFSTraverse(void(*visit)(VexType &data)) {
    UInt32 vex_nums = getVexNums();
    bool *visited = new bool[vex_nums];
    UInt8 *order = new UInt8[vex_nums];
    stack<UVex*>stack;
    UVex *cur_vex, *ner_vex;
    memset(visited, 0, sizeof(bool)* vex_nums);
    memset(order, 0, sizeof(UInt8)* vex_nums);
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            cur_vex = getIndexVex(i);
            visit(cur_vex->data);
            visited[i] = true;
            stack.push(cur_vex);
            while (!stack.empty()) {
                cur_vex = stack.top();
                if (order[i] < vex_nums) {
                    UInt8 j;
                    for (j = order[i]; j < vex_nums; ++j) {
                        if (arcs[i][j].value != NULL_ARC) {
                            order[i] = j + 1;
                            break;
                        }
                    }
                    if (j < vex_nums && !visited[j]) {
                        ner_vex = getIndexVex(j);
                        visit(ner_vex->data);
                        visited[j] = true;
                        stack.push(ner_vex);
                    } else {
                        stack.pop();
                    }
                } else {
                    stack.pop();
                }
            }
        }
    }
    delete visited;
    delete order;
}

void    UDGraph::BFSTraverse(void(*visit)(VexType &data)) {
    queue<UVex*>queue;
    UVex *cur_vex, *first_vex, *next_vex;
    bool *visited = new bool[vex_nums];
    memset(visited, 0, sizeof(bool)* vex_nums);
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            cur_vex = getIndexVex(i);
            queue.push(cur_vex);
            while (!queue.empty()) {
                cur_vex = queue.front();
                queue.pop();
                visit(cur_vex->data);
                visited[getVexIndex(cur_vex)] = true;
                first_vex = firstVex(cur_vex);
                if (first_vex && !visited[getVexIndex(first_vex)]) {
                    queue.push(first_vex);
                    next_vex = nextVex(cur_vex, first_vex);
                    while (next_vex) {
                        if (!visited[getVexIndex(next_vex)])
                            queue.push(next_vex);
                        next_vex = nextVex(cur_vex, next_vex);
                    }
                }
            }
        }
    }
    delete visited;
}

void    UDGraph::show() {
    cout << "图的存储结构显示如下：" << endl;
    cout << "顶点集：";
    for (UInt8 j = 0; j < vex_nums; ++j)
        cout << " " << vexs[j].data;
    cout << endl;
    for (UInt8 i = 0; i < vex_nums; ++i) {
        cout << "顶点：" << vexs[i].data << " ";
        for (UInt8 j = 0; j < vex_nums; ++j) {
            cout << " " << arcs[i][j].value;
        }
        cout << endl;
    }
}

void    UDGraph::visit(VexType& data) {
    //do some visit operation
    cout << " " << data;
}

UInt8   UDGraph::getDataIndex(VexType data) {
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (vexs[i].data == data)  return i;
    }
    return -1;
}

UInt8   UDGraph::getVexIndex(UVex* vex) {
    UInt8 index = vex - vexs;
    if (index < 0 || index >= vex_nums)     return -1;
    else    return index;
}

UVex*   UDGraph::getIndexVex(UInt8 index) {
    return vexs + index;
}

UInt32  UDGraph::connectedCompnent() {
    UInt32 connected_count = 0;
    stack<UVex*> stack;
    UInt32  vex_nums = getVexNums();
    UVex *cur_vex, *ner_vex;
    bool*   visited = new bool[vex_nums];
    memset(visited, 0, sizeof(bool)* vex_nums);
    UInt32* order = new UInt32[vex_nums];
    memset(order, 0, sizeof(UInt32)* vex_nums);
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            ++connected_count;

        }
    }
}