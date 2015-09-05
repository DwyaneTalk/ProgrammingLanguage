/*   DwyaneTalk@gmail.com
*   by lutao
*   Leetcode94   : Binary Tree Inorder Traversal
*                : https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;   
};

typedef struct TreeNode TreeNode;

typedef struct {
    int *ans;
    int returnSize;
    int max_size;
}Result;

void initResult(Result* res) {
    res->ans = (int*)malloc(sizeof(int)* 100);
    res->max_size = 100;
    res->returnSize = 0;
}

void renewResult(Result* res) {
    res->ans = (int*)realloc(res->ans, sizeof(int)* (res->max_size + 50));
    res->max_size += 50;
}

void pushResult(Result* res, int data) {
    if (res->returnSize >= res->max_size)
        renewResult(res);
    res->ans[res->returnSize++] = data;
}

typedef struct {
    TreeNode* *data;
    int top;
    int max_size;
} Stack;

void initStack(Stack* stack) {
    stack->data = (TreeNode**)malloc(sizeof(TreeNode*)* 100);
    stack->top = 0;
    stack->max_size = 100;
}

void renewStack(Stack* stack) {
    stack->data = (TreeNode**)realloc(stack->data, sizeof(TreeNode*)* (stack->max_size + 50));
    stack->max_size += 50;
}

void pushStack(Stack* stack, TreeNode* node) {
    if (stack->top >= stack->max_size)
        renewStack(stack);
    stack->data[stack->top++] = node;
}

TreeNode* popStack(Stack* stack) {
    --(stack->top);
    return stack->data[stack->top];
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    Result result, *res = &result;
    Stack stack_s, *stack = &stack_s;
    initResult(res);
    initStack(stack);
    if (root && root->val != '#') {
        pushStack(stack, root);
        while (stack->top) {
            while (root->left && root->left->val != '#') {
                root = root->left;
                pushStack(stack, root);
            }
            while (stack->top) {
                root = popStack(stack);
                pushResult(res, root->val);
                if (root->right && root->right->val != '#') {
                    root = root->right;
                    pushStack(stack, root);
                    break;
                }
            }
        }
    }
    *returnSize = res->returnSize;
    return res->ans;
}
int main() {
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = 1;
    root->right = NULL;
    root->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->val = 2;
    root->left->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->left->val = 3;
    root->left->left->left = root->left->left->right = NULL;
    root->left->right = NULL;
    int returnSize;
    int* ans = inorderTraversal(root, &returnSize);
    for (int i = 0; i < returnSize; ++i)
        printf("%d ", ans[i]);
    system("pause");
    return 0;
}
