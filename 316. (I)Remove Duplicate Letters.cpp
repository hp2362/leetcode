/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"


*/

class Solution
{
public:
	string removeDuplicateLetters(string s)
	{
		vector<int> cnt(26);
		for (auto i : s)
			cnt[i - 'a']++;
		int pos = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] < s[pos]) pos = i;
			if (--cnt[s[i] - 'a'] == 0) break;
		}
		string str;
		for (int i = pos + 1; i < s.size(); i++)
		{
			if (s[i] != s[pos]) str += s[i];
		}
		return s.size() == 0 ? "" : s[pos] + removeDuplicateLetters(str);
	}
};