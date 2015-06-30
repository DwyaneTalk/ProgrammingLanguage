#ifndef UDGRAPH_H
#define UDGRAPH_H

#include "Graph.h"

typedef struct Vex {
    VexType   data;
    VexInfo*       info;   //����ĸ�����Ϣ
    Vex(VexInfo* info = NULL) {
        this->info = info;
    }
} Vex;

typedef struct Arc {
    ArcType   value;
    ArcInfo*        info;   //���ĸ�����Ϣ
    Arc(ArcType value = MAX_ARC, ArcInfo* info = NULL) {
        this->value = value;
        this->info = info;
    }
} Arc;

class UDGraph : public Graph {   //����ͼ
private:
    Vex*    vexs;   //���㼯
    Arc**   arcs;   //�ڽӾ���

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
