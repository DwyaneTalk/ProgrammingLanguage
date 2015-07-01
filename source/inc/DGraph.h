#ifndef DGRAPH_H
#define DGRAPH_H

#include "Util.h"


typedef struct DArc {
    ArcType   value;
    UInt8           tvex;     //指向尾顶点在顶点集的索引
    UInt8           hvex;     //指向头顶点在顶点集的索引
    struct DArc     *tlink;
    struct DArc     *hlink;
} DArc;

typedef struct DVex {
    VexType   data;
    DArc*            in_list;
    DArc*            out_list;
} DVex;


class DGraph{
private:
    GType   graph_type;
    UInt32  vex_nums;
    UInt32  arc_nums;
    DVex*    vexs;    //十字链表存储
public:
    DGraph();
    ~DGraph();
    void    init();
    void    createGraph();
    bool    isEmpty();
    GType   getType()       { return graph_type; }
    UInt32  getVexNums()    { return vex_nums; }
    UInt32  getArcNums()    { return arc_nums; }
    DVex*   locateVex(VexType data);
    VexType getVexData(DVex* vex);
    void    setVexData(DVex* vex, VexType data);
    DVex*   firstVex(DVex* vex);
    DVex*   nextVex(DVex* vex, DVex* cur_vex);
    DVex*   insertVex(VexType data);
    VexType deleteVex(DVex* vex);
    void    insertArc(DVex* t_vex, DVex* h_vex, ArcType arc);
    ArcType deleteArc(DVex* t_vex, DVex* h_vex);
    void    DFSTraverse(void(*visit)(VexType &data), VexType* out_data);
    void    BFSTraverse(void(*visit)(VexType &data), VexType* out_data);
    void    show();
    void    visit(VexType &data);
};
#endif // !DGRAPH_H
