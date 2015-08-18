#include "Util.h"
#include "BinaryTree.h"
#include<stack>

class DynamicSrhTable {
private:
    SearchType *data;
    UInt32      max_size;
    UInt32      size;
    BinaryTree *bin_sort_tree;
    UInt32 newData(SearchType key);
    Int32 bstSearch(SearchType key, BiNode *&node);
    BiNode* bstInsert(BiNode *node, UInt32 index);
    void bstDelete(BiNode *node, UInt32 index);
public:
    DynamicSrhTable();
    ~DynamicSrhTable();
    Int32 search(DynFindType f_type, SearchType key);
    void deleteData(DynFindType f_type, SearchType key);
    void traverse(void(*visit)(SearchType &e));
    void visit(SearchType &e);
};

