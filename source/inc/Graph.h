#ifndef GRAPH_H
#define GRAPH_H

#include "Util.h"

//附加信息可以用来扩展图的功能
typedef struct VexInfo {   //顶点的附加信息

} VexInfo;

typedef struct ArcInfo {    //弧的附加信息
    
} ArcInfo;

class Graph{    //图的存储方式：邻接矩阵、邻接表、十字链表（有向图）和多重链表（无向图）
protected:
    GType   graph_type;
    UInt32  vex_nums;
    UInt32  arc_nums;

public:
    virtual void init();
    virtual void createGraph();
    virtual bool isEmpty();
    GType   getType()       { return graph_type; }
    UInt32  getVexNums()    { return vex_nums; }
    UInt32  getArcNums()    { return arc_nums; }
    virtual Vex*    locateVex(VexType data);
    virtual VexType getVexData(Vex* vex);
    virtual void    setVexData(Vex* vex, VexType data);
    virtual Vex*    firstVex(Vex* vex);
    virtual Vex*    nextVex(Vex* vex, Vex* cur_vex);
    virtual Vex*    insertVex(VexType data);
    virtual VexType deleteVex(Vex* vex);
    virtual void    insertArc(Vex* t_vex, Vex* h_vex, ArcType arc);
    virtual ArcType deleteArc(Vex* t_vex, Vex* h_vex);
    virtual void    DFSTraverse();
    virtual void    BFSTraverse();
};

#endif // !GRAPH_H
