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
    Int32 seqSearch(SearchType key);
    Int32 binSearch(SearchType key);
    Int32 fibSearch(SearchType key);
    Int32 intSearch(SearchType key);
    Int32 strSearch(SearchType key);
    Int32 idxSearch(SearchType key);
    void  sortData();
public:
    StaticSrhTable();
    ~StaticSrhTable();
    Int32 search(FindType f_type, SearchType key);
    void traverse(void(*visit) (SearchType &e));
    void static visit(SearchType &e);
};