/*   DwyaneTalk@gmail.com
*   by lutao
*/
typedef struct{
    int **ans;
    int *columnSizes;
    int returnSize;
    int max_size;
} Result;

void initResult(Result* res) {
    res->ans = (int**)malloc(sizeof(int*)* 10);
    res->columnSizes = (int*)malloc(sizeof(int)* 10);
    res->max_size = 10;
    res->returnSize = 0;
}

void newColumn(Result* res, int size) {
    if (res->returnSize >= res->max_size) {
        res->ans = (int**)realloc(res->ans, sizeof(int*)* (res->returnSize + 5));
        res->columnSizes = (int*)realloc(res->columnSizes, sizeof(int)* (res->returnSize + 5));
        res->max_size += 5;
    }
    res->columnSizes[res->returnSize] = size;
    res->ans[res->returnSize] = (int*)malloc(sizeof(int)* size);
    ++(res->returnSize);
}