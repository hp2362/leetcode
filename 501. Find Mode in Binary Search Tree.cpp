/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
1
 \
  2
 /
 2
return [2]
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<int> findMode(TreeNode* root)
	{
		vector<int> vec;
		int mxfre = 0, pre = INT_MAX, cnt = 1;
		dfs(root, vec, mxfre, pre, cnt);
		return vec;
	}

	void dfs(TreeNode* root, vector<int>& vec, int& mxfre, int& pre, int& cnt)//ÖÕÐë±éÀú
	{
		if (root == NULL) return;
		dfs(root->left, vec, mxfre, pre, cnt);
		if (pre != INT_MAX)
		{
			cnt = ((pre == root->val) ? cnt + 1 : 1);
		}
		if (cnt >= mxfre)
		{
			if (cnt>mxfre) vec.clear();
			vec.push_back(root->val);
			mxfre = cnt;
		}
		pre = root->val;
		dfs(root->right, vec, mxfre, pre, cnt);
	}
};