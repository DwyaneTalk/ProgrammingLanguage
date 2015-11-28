/*   DwyaneTalk@gmail.com
*   by lutao
*/
typedef struct {
    TreeNode* *data;
    int front;
    int rear;
    int end;
} Queue;

void initQueue(Queue* queue) {
    queue->data = (TreeNode**)malloc(sizeof(TreeNode*)* 100);
    queue->front = 0;
    queue->rear = 0;
    queue->end = 100;
}

void renewQueue(Queue* queue) {
    queue->data = (TreeNode**)realloc(queue->data, sizeof(TreeNode*)* (queue->end + 50));
    queue->end += 50;
}

void pushQueue(Queue* queue, TreeNode* node) {
    if (queue->rear >= queue->end)
        renewQueue(queue);
    queue->data[queue->rear++] = node;
}

TreeNode* popQueue(Queue* queue) {
    return queue->data[(queue->front)++];
}

void freeQueue(Queue* queue) {
    free(queue->data);
    queue->data = NULL;
    queue->front = queue->rear = queue->end = 0;
}

