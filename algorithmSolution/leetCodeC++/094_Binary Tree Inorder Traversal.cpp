/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCodeC++	: Binary Tree Inorder Traversal
 *					: https://leetcode.com/problems/binary-tree-inorder-traversal/
*/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <hash_set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void inorderTraversal(TreeNode* root, vector<int>& nodeElem) {
		if(root->left)		inorderTraversal(root->left, nodeElem);
		nodeElem.push_back(root->val);
		if(root->right)		inorderTraversal(root->right,nodeElem);
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		if(root)	inorderTraversal(root, ans);
		return ans;
	}
};