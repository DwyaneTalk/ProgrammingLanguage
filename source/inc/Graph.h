#ifndef GRAPH_H
#define GRAPH_H

#include "Util.h"

//附加信息可以用来扩展图的功能
typedef struct VexInfo {   //顶点的附加信息

} VexInfo;

typedef struct ArcInfo {    //弧的附加信息
    
} ArcInfo;

typedef struct Vex  vex;

class Graph{    //图的存储方式：邻接矩阵、邻接表、十字链表（有向图）和多重链表（无向图）
protected:
    GType   graph_type;
    UInt32  vex_nums;
    UInt32  arc_nums;

public:
    virtual void init() = 0;
    virtual void createGraph() = 0;
    virtual bool isEmpty() = 0;
    GType   getType()       { return graph_type; }
    UInt32  getVexNums()    { return vex_nums; }
    UInt32  getArcNums()    { return arc_nums; }
    virtual Vex*    locateVex(VexType data) = 0;
    virtual VexType getVexData(Vex* vex) = 0;
    virtual void    setVexData(Vex* vex, VexType data) = 0;
    virtual Vex*    firstVex(Vex* vex) = 0;
    virtual Vex*    nextVex(Vex* vex, Vex* cur_vex) = 0;
    virtual Vex*    insertVex(VexType data) = 0;
    virtual VexType deleteVex(Vex* vex) = 0;
    virtual void    insertArc(Vex* t_vex, Vex* h_vex, ArcType arc) = 0;
    virtual ArcType deleteArc(Vex* t_vex, Vex* h_vex) = 0;
    virtual void    DFSTraverse(void(*visit)(VexType &data), VexType* out_data) = 0;
    virtual void    BFSTraverse(void(*visit)(VexType &data), VexType* out_data) = 0;
    virtual void    show() = 0;
    virtual void    visit(VexType &data) = 0;
};

#endif // !GRAPH_H
