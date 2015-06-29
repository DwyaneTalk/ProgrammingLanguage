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


class DGraph : public Graph {
private:
    Vex*    vexs;
public:
};
#endif // !DGRAPH_H
