/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].


*/

class Solution
{
public:
	struct Node
	{
		int _val;
		int _dup;
		int _sum;
		Node* left, *right;
		Node(int val, int sum) : _val(val), _sum(sum), _dup(1), left(NULL), right(NULL) {}
	};
	vector<int> countSmaller(vector<int>& nums)
	{
		vector<int> ret(nums.size());
		Node* root = NULL;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			root = insert(ret, nums, root, i, 0);
		}
		return ret;
	}

	Node* insert(vector<int>& ret, vector<int>& nums, Node* node, int i, int presum)
	{
		if (node == NULL)
		{
			Node* tmp = new Node(nums[i], 0);
			ret[i] = presum;
			return tmp;
		}
		else if (node->_val == nums[i])
		{
			node->_dup++;
			ret[i] = node->_sum + presum;
		}
		else if (node->_val > nums[i])//Íù×óÒÆ¶¯
		{
			node->_sum++;
			node->left = insert(ret, nums, node->left, i, presum);
		}
		else
		{
			node->right = insert(ret, nums, node->right, i, presum + node->_sum + node->_dup);
		}
		return node;
	}


};