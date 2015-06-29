#ifndef GRAPH_H
#define GRAPH_H

#include "Util.h"

//������Ϣ����������չͼ�Ĺ���
typedef struct VexInfo {   //����ĸ�����Ϣ

} VexInfo;

typedef struct ArcInfo {    //���ĸ�����Ϣ
    
} ArcInfo;

class Graph{    //ͼ�Ĵ洢��ʽ���ڽӾ����ڽӱ�ʮ����������ͼ���Ͷ�����������ͼ��
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
