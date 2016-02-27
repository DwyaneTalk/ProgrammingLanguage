/*   DwyaneTalk@gmail.com
*   by lutao
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

void treeShow(TreeNode* root, int n) {
    if (root) {
        treeShow(root->right, n + 1);
        for (int i = 0; i < n; ++i)
            printf("   ");
        printf("%d\n", root->val);
        treeShow(root->left, n + 1);
    }
}

TreeNode* treeCreate(int **data) {
    if (!(*(*data))) {
        *data += 1;
        return NULL;
    } else {
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        root->val = *(*data);
        *data += 1;
        root->left = treeCreate(data);
        root->right = treeCreate(data);
        return root;
    }
}
