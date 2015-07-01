#include "../inc/DGraph.h"

DGraph::DGraph() {
    if (vexs = new DVex[MAXELEMNUM]) {
        graph_type = DN;
        arc_nums = 0;
        vex_nums = 0;
    } else {
        ferr << "�����ڴ�ʧ�ܣ�" << endl;
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
        ferr << "����ʱ����������ƣ�" << endl;
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
        ferr << "�Կն���Ƿ�������" << endl;
        exit(ERROR);
    }
}

void DGraph::setVexData(DVex *vex, VexType data) {
    if (vex) {
        vex->data = data;
    } else {
        ferr << "�Կն���Ƿ�������" << endl;
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
        ferr << "�Կն���Ƿ�������" << endl;
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
        ferr << "�Կն���Ƿ�������" << endl;
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
        ferr << "����ﵽ�����Ŀ���޷����ӣ�" << endl;
        exit(ERROR);
    }
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
        ferr << "��Ч�Ĳ������㣡" << endl;
        exit(ERROR);
    }
}

DVex* DGraph::getIndexVex(UInt8 index) {
    if (index < 0 || index >= vex_nums) {
        ferr << "���Ϸ��������±꣡" << endl;
        exit(ERROR);
    }
    return vexs + index;
}