/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".


*/

class Solution {
public:
	int maxProduct(vector<string>& words)
	{
		//居然使用int来标记
		int sz = words.size();
		vector<int> vec(sz);
		for (int i = 0; i < sz; i++)
		{
			for (auto j : words[i])
				vec[i] |= 1 << (j - 'a');
		}
		int ret = 0;
		for (int i = 0; i < sz; i++)
		{
			for (int j = i + 1; j<sz; j++)
			{
				if ((vec[i] & vec[j]) == 0 && words[i].size()*words[j].size()>ret)
					ret = words[i].size()*words[j].size();
			}
		}
		return ret;
	}
};