#ifndef DGRAPH_H
#define DGRAPH_H

#include "Graph.h"

typedef struct Arc {
    ArcType   value;
    UInt8           tvex;     //指向尾顶点在顶点集的索引
    UInt8           hvex;     //指向头顶点在顶点集的索引
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
