/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* tmp;
	bool isPalindrome(ListNode* head)
	{
		tmp = head;
		return check(head);
	}

	bool check(ListNode* p)
	{
		if (p == NULL) return true;
		bool flag = check(p->next)&(p->val == tmp->val);
		tmp = tmp->next;
		return flag;
	}
};