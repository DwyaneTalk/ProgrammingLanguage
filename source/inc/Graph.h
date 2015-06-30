#ifndef GRAPH_H
#define GRAPH_H

#include "Util.h"

//������Ϣ����������չͼ�Ĺ���
typedef struct VexInfo {   //����ĸ�����Ϣ

} VexInfo;

typedef struct ArcInfo {    //���ĸ�����Ϣ
    
} ArcInfo;

typedef struct Vex  vex;

class Graph{    //ͼ�Ĵ洢��ʽ���ڽӾ����ڽӱ�ʮ����������ͼ���Ͷ�����������ͼ��
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
