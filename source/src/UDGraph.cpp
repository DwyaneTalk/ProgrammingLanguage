#include "../inc/UDGraph.h"


UDGraph::UDGraph() {
    if ((vexs = new Vex[MAXELEMNUM]) && (arcs = new Arc*[MAXELEMNUM])) {
        for (UInt8 i = 0; i < MAXELEMNUM; ++i) {
            if (!(arcs[i] = new Arc[MAXELEMNUM])) {
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

bool    UDGraph::isEmpty() {
    return !vex_nums;
}

Vex*    UDGraph::locateVex(VexType data) {
    UInt8 index = getDataIndex(data);
    if (index < 0)  return NULL;
    else            return vexs + index;
}

VexType UDGraph::getVexData(Vex* vex) {
    if (vex) {
        return vex->data;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

void    UDGraph::setVexData(Vex* vex, VexType data) {
    if (vex) {
        vex->data = data;
    } else {
        ferr << "对空顶点非法操作！" << endl;
        exit(ERROR);
    }
}

Vex*    UDGraph::firstVex(Vex* vex) {
    UInt8 idx = getVexIndex(vex);
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (arcs[idx][i].value != MAX_ARC)  return vexs + i;
    }
    return NULL;
}

Vex*    UDGraph::nextVex(Vex* vex, Vex* cur_vex) {
    UInt8 t_idx = getVexIndex(vex);
    UInt8 h_idx = getVexIndex(cur_vex);
    for (UInt8 i = h_idx + 1; i < vex_nums; ++i) {
        if (arcs[t_idx][h_idx].value != MAX_ARC)    return vexs + i;
    }
    return NULL;
}

Vex*    UDGraph::insertVex(VexType data) {
    if (vex_nums < MAXELEMNUM) {
        vexs[vex_nums++].data = data;
    } else {
        ferr << "顶点数达到最大，无法添加新的顶点！" << endl;
        exit(ERROR);
    }
}

VexType UDGraph::deleteVex(Vex* vex) {
    if (vex) {
        VexType data = vex->data;
        //todo
        return data;
    } else {
        ferr << "对空顶点的非法操作！" << endl;
        exit(ERROR);
    }
}

void    UDGraph::insertArc(Vex* t_vex, Vex* h_vex, ArcType arc) {
    if (t_vex && h_vex) {
        UInt8 t_idx = getVexIndex(t_vex);
        UInt8 h_idx = getVexIndex(h_vex);
        if (t_idx >= 0 && h_idx >= 0) {
            arcs[t_idx][h_idx].value = arc;
            arcs[h_idx][t_idx].value = arc;
        } else {
            ferr << "对空顶点的非法操作！" << endl;
            exit(ERROR);
        }
    } else {
        ferr << "对空顶点的非法操作！" << endl;
        exit(ERROR);
    }
}

ArcType UDGraph::deleteArc(Vex* t_vex, Vex* h_vex) {
    if (t_vex && h_vex) {
        UInt8 t_idx = getVexIndex(t_vex);
        UInt8 h_idx = getVexIndex(h_vex);
        if (t_idx >= 0 && h_idx >= 0) {
            arcs[t_idx][h_idx].value = MAX_ARC;
            arcs[h_idx][t_idx].value = MAX_ARC;
        } else {
            ferr << "对空顶点的非法操作！" << endl;
            exit(ERROR);
        }
    } else {
        ferr << "对空顶点的非法操作！" << endl;
        exit(ERROR);
    }
}

void    UDGraph::DFSTraverse() {}
void    UDGraph::BFSTraverse() {}

UInt8   UDGraph::getDataIndex(VexType data) {
    for (UInt8 i = 0; i < vex_nums; ++i) {
        if (vexs[i].data == data)  return i;
    }
    return -1;
}

UInt8   UDGraph::getVexIndex(Vex* vex) {
    UInt8 index = vex - vexs;
    if (index < 0 || index >= vex_nums)     return -1;
    else    return index;
}