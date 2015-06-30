#ifndef UDGRAPH_H
#define UDGRAPH_H

#include "Graph.h"

typedef struct Vex {
    VexType   data;
    VexInfo*       info;   //顶点的附加信息
    Vex(VexInfo* info = NULL) {
        this->info = info;
    }
} Vex;

typedef struct Arc {
    ArcType   value;
    ArcInfo*        info;   //弧的附加信息
    Arc(ArcType value = MAX_ARC, ArcInfo* info = NULL) {
        this->value = value;
        this->info = info;
    }
} Arc;

class UDGraph : public Graph {   //无向图
private:
    Vex*    vexs;   //顶点集
    Arc**   arcs;   //邻接矩阵

    UInt8   getDataIndex(VexType data);
    UInt8   getVexIndex(Vex* vex);
public:
    UDGraph();
    ~UDGraph();
    void    init();
    void    createGraph();
    bool    isEmpty();
    Vex*    locateVex(VexType data);
    VexType getVexData(Vex* vex);
    void    setVexData(Vex* vex, VexType data);
    Vex*    firstVex(Vex* vex);
    Vex*    nextVex(Vex* vex, Vex* cur_vex);
    Vex*    insertVex(VexType data);
    VexType deleteVex(Vex* vex);
    void    insertArc(Vex* t_vex, Vex* h_vex, ArcType arc);
    ArcType deleteArc(Vex* t_vex, Vex* h_vex);
    void    DFSTraverse(void(*visit)(VexType &data), VexType* out_data);
    void    BFSTraverse(void(*visit)(VexType &data), VexType* out_data);
    void    show();
    void    visit(VexType &data);
};

#endif // !UDGRAPH_H
