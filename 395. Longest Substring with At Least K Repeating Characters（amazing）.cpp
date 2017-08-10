/*
Find the length of the longest substring T of a given string
(consists of lowercase letters only) such that every character in T appears no less than k times.

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

*/

class Solution {
public:
	int longestSubstring(string s, int k)
	{
		int max_len = 0;
		for (int first = 0; first + k <= s.size();)
		{
			int count[26] = { 0 };
			int mask = 0;
			int max_last = first;
			for (int last = first; last < s.size(); ++last)
			{
				int i = s[last] - 'a';
				count[i]++;
				if (count[i] < k) mask |= (1 << i);
				else   mask &= (~(1 << i));

				if (mask == 0) {
					max_len = max(max_len, last - first + 1);
					max_last = last;
				}
			}
			first = max_last + 1;
		}
		return max_len;
	}
};