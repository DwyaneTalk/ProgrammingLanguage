#ifndef UDGRAPH_H
#define UDGRAPH_H

#include "Graph.h"

typedef struct Vex {
    VexType   data;
    VexInfo*       info;   //顶点的附加信息
} Vex;

typedef struct Arc {
    ArcType   value;
    ArcInfo*        info;   //弧的附加信息
} Arc;

class UDGraph : public Graph {   //无向图
private:
    Vex*    vexs;   //顶点集
    Arc*    arcs;   //邻接矩阵（一维数组表示下三角矩阵）

public:
    UDGraph();
    ~UDGraph();
    void    init();
    void    createGraph();
    bool    isEmpty();
    Vex*    locateVex(VexType u);
    VexType getNode(Vex* v);
    void    setVex(Vex* v, VexType u);
    Vex*    firstVex(Vex* v);
    Vex*    nextVex(Vex* v, Vex* cur);
    Vex*    insertVex(VexType u);
    VexType deleteVex(Vex* v);
    void    insertArc(Vex* t, Vex* h, ArcType arc);
    ArcType deleteArc(Vex* t, Vex* h);
    void    DFSTraverse();
    void    BFSTraverse();
};

#endif // !UDGRAPH_H
