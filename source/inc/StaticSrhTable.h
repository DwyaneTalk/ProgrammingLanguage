#include "Util.h"
#include "BinaryTree.h"

typedef struct {
    SearchType  key;
    UInt32      idx;
} Index;

class StaticSrhTable {
private:
    SearchType *data;
    UInt32      size;
    SearchType *seq_data;
    BinaryTree *sta_srh_tree;
    Index      *idx_table;
public:
    StaticSrhTable();
    ~StaticSrhTable();
    void init();
    Int32 search(FindType f_type, SearchType key);
    void traverse(void(*visit) (SearchType &e));
    void static visit(SearchType &e);
};