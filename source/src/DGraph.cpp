#include "../inc/DGraph.h"

DGraph::DGraph() {
    if (vexs = new DVex[MAXELEMNUM]) {
        graph_type = DN;
        arc_nums = 0;
        vex_nums = 0;
    } else {
        ferr << "申请内存失败！" << endl;
        exit(OVER);
    }
}

DGraph::~DGraph() {
    for (UInt8 i = 0; i < vex_nums; ++i) {
        DArc* list_arc = vexs->h_list, *free_arc;
        while (list_arc) {
            free_arc = list_arc;
            list_arc = list_arc->hlink;
            delete free_arc;
        }
    }
    delete vexs;
}

void DGraph::init() {
    for (UInt8 i = 0; i < vex_nums; ++i) {
        DArc* list_arc = vexs->h_list, *free_arc;
        while (list_arc) {
            free_arc = list_arc;
            list_arc = list_arc->hlink;
            delete free_arc;
        }
    }
    vex_nums = 0;
    arc_nums = 0;
}

void DGraph::createGraph() {
    fin >> vex_nums >> arc_nums;
    if (vex_nums > MAXELEMNUM) {
        ferr << "顶点时超过最大限制！" << endl;
        exit(ERROR);
    }
    for (UInt8 i = 0; i < vex_nums; ++i) {
        fin >> vexs[i].data;
    }
    VexType t_data, h_data;
    UInt8 t_index, h_index;
    UInt32 arc_value;
    DArc* new_arc;
    DArc *t_list, *h_list;
    DVex *t_vex, *h_vex;
    for (UInt8 i = 0; i < arc_nums; ++i) {
        fin >> t_data >> h_data >> arc_value;
        t_index = getDataIndex(t_data);
        h_index = getDataIndex(h_data);
        new_arc = new DArc(arc_value, t_index, h_index);
        t_vex = getIndexVex(t_index);
        h_vex = getIndexVex(h_index);
        if (!t_vex->t_list) t_vex->t_list = new_arc;
        else {
            t_list = t_vex->t_list;
            while (t_list->tlink) {
                t_list = t_list->tlink;
            }
            t_list->tlink = new_arc;
        }
        if (!h_vex->h_list) h_vex->h_list = new_arc;
        else {
            h_list = h_vex->h_list;
            while (h_list->hlink) {
                h_list = h_list->hlink;
            }
            h_list->hlink = new_arc;
        }
    }
}

DVex* DGraph::locateVex(VexType data) {
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (vexs[i].data == data) {
            return vexs + i;
        }
    }
    return NULL;
}

VexType DGraph::getVexData(DVex *vex) {
    if (vex) {
        return vex->data;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

void DGraph::setVexData(DVex *vex, VexType data) {
    if (vex) {
        vex->data = data;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

UInt8 DGraph::getVexInDegree(DVex *vex) {
    if (vex) {
        UInt8 degree = 0;
        DArc* arc_list = vex->h_list;
        while (arc_list) {
            ++degree;
            arc_list = arc_list->hlink;
        }
        return degree;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

UInt8 DGraph::getVexOutDegree(DVex *vex) {
    if (vex) {
        UInt8 degree = 0;
        DArc* arc_list = vex->t_list;
        while (arc_list) {
            ++degree;
            arc_list = arc_list->tlink;
        }
        return degree;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }

}

DVex* DGraph::adjVex(DVex *vex, DVex *cur_vex) {
    if (!cur_vex) {
        return vexs + vex->t_list->tidx;
    } else {
        UInt8 index = getVexIndex(cur_vex);
        DArc* arc_list = vex->t_list;
        while (arc_list->tidx != index) {
            arc_list = arc_list->tlink;
        }
        if (arc_list->tlink) {
            return vexs + arc_list->tlink->tidx;
        } else {
            return NULL;
        }
    }
}

DVex* DGraph::insertVex(VexType data) {
    if (vex_nums < MAXELEMNUM) {
        vexs[vex_nums].data = data;
        return vexs + vex_nums++;
    } else {
        ferr << "顶点达到最大数目，无法增加！" << endl;
        exit(ERROR);
    }
}

void DGraph::DFSTraverse(void(*visit)(VexType &data)) {
    stack<DVex*>stack;
    DVex *cur_vex, *ner_vex;
    UInt8 index;
    bool *visited = new bool[vex_nums];
    memset(visited, 0, sizeof(bool)* vex_nums);
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            cur_vex = getIndexVex(i);
            visit(cur_vex->data);
            visited[i] = true;
            stack.push(cur_vex);
            while (!stack.empty()) {
                cur_vex = stack.top();
                ner_vex = NULL;
                while (ner_vex = adjVex(cur_vex, ner_vex)) {
                    index = getVexIndex(ner_vex);
                    if (!visited[index]) {
                        visit(ner_vex->data);
                        visited[index] = true;
                        stack.push(ner_vex);
                        break;
                    }
                }
                if (!ner_vex) {
                    stack.pop();
                }
            }
        }
    }
    delete visited;
}

void DGraph::BFSTraverse(void(*visit)(VexType &data)) {
    queue<DVex*>queue;
    bool *visited = new bool[vex_nums];
    DVex *cur_vex, *ner_vex;
    UInt8 index;
    memset(visited, 0, sizeof(bool)* vex_nums);
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (!visited[i]) {
            cur_vex = getIndexVex(i);
            visit(cur_vex->data);
            visited[i] = true;
            queue.push(cur_vex);
            while (!queue.empty()) {
                cur_vex = queue.front();
                queue.pop();
                ner_vex = NULL;
                while (ner_vex = adjVex(cur_vex, ner_vex)) {
                    index = getVexIndex(ner_vex);
                    if (visited[index]) {
                        visit(ner_vex->data);
                        visited[index] = true;
                        queue.push(ner_vex);
                    }
                }
            }
        }
    }
    delete visited;
}

void DGraph::show() {

}

void DGraph::visit(VexType &data) {
    //do some operation
    cout << " " << data;
}

UInt8 DGraph::getDataIndex(VexType data) {
    UInt8 index;
    for (index = 0; index < vex_nums; ++index) {
        if (vexs[index].data == data)   break;
    }
    if (index >= vex_nums)  return -1;
    else    return index;
}

UInt8 DGraph::getVexIndex(DVex* vex) {
    if (vex) {
        UInt8 index = vex - vexs;
        if (index >= 0 && index < vex_nums) return index;
        else return -1;
    } else {
        ferr << "无效的操作顶点！" << endl;
        exit(ERROR);
    }
}

DVex* DGraph::getIndexVex(UInt8 index) {
    if (index < 0 || index >= vex_nums) {
        ferr << "不合法的索引下标！" << endl;
        exit(ERROR);
    }
    return vexs + index;
}