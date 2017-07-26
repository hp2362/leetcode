/*
Given a complete binary tree, count the number of nodes.
*/
#include <iostream>


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int countNodes(TreeNode* root)
	{
		if (root == NULL) return 0;
		int hl = 0, hr = 0;
		TreeNode* l = root, *r = root;
		while (l != NULL) { l = l->left; hl++; }
		while (r != NULL) { r = r->right; hr++; }
		if (hl == hr) return pow(2, hr) - 1;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};

