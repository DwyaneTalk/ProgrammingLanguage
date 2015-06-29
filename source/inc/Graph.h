#ifndef GRAPH_H
#define GRAPH_H

#include "Util.h"

//附加信息可以用来扩展图的功能
typedef struct VexInfo {   //顶点的附加信息

} VexInfo;

typedef struct ArcInfo {    //弧的附加信息
    
} ArcInfo;

class Graph{
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
    virtual Vex*    locateVex(VexType u);
    virtual VexType getNode(Vex* v);
    virtual void    setVex(Vex* v, VexType u);
    virtual Vex*    firstVex(Vex* v);
    virtual Vex*    nextVex(Vex* v, Vex* cur);
    virtual Vex*    insertVex(VexType u);
    virtual VexType deleteVex(Vex* v);
    virtual void    insertArc(Vex* t, Vex* h, ArcType arc);
    virtual ArcType deleteArc(Vex* t, Vex* h);
    virtual void    DFSTraverse();
    virtual void    BFSTraverse();
};

#endif // !GRAPH_H
