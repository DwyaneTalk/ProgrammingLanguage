#ifndef UDGRAPH_H
#define UDGRAPH_H

#include "Graph.h"

typedef struct Vex {
    VexType   data;
    VexInfo*       info;   //����ĸ�����Ϣ
} Vex;

typedef struct Arc {
    ArcType   value;
    ArcInfo*        info;   //���ĸ�����Ϣ
} Arc;

class UDGraph : public Graph {   //����ͼ
private:
    Vex*    vexs;   //���㼯
    Arc*    arcs;   //�ڽӾ���һά�����ʾ�����Ǿ���

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
