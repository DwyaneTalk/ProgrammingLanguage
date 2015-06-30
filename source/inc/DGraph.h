#ifndef DGRAPH_H
#define DGRAPH_H

#include "Graph.h"

typedef struct Arc {
    ArcType   value;
    UInt8           tvex;     //ָ��β�����ڶ��㼯������
    UInt8           hvex;     //ָ��ͷ�����ڶ��㼯������
    struct Arc     *tlink;
    struct Arc     *hlink;
} Arc;

typedef struct Vex {
    VexType   data;
    Arc*            in_list;
    Arc*            out_list;
} Vex;


class DGraph{
private:
    Vex*    vexs;    //ʮ������洢
public:
    DGraph();
    ~DGraph();
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
#endif // !DGRAPH_H
