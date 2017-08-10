/*
Consider the string s to be the infinite wraparound string of 
"abcdefghijklmnopqrstuvwxyz", so s will look like this: 
"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of 
string "zab" in the string s.
*/

class Solution {
public:
	int findSubstringInWraproundString(string p)
	{
		//看看每一个子串有没有按序列
		vector<int> dp(26, 0);
		int count = 1;
		for (int i = 0; i < p.size(); i++)
		{
			if (i > 0)
			{
				if (p[i] - 'a' == (p[i - 1] - 'a' + 1) % 26)
					count++;
				else


					count = 1;
			}
			dp[p[i] - 'a'] = max(dp[p[i] - 'a'], count);
		}
		int sum = accumulate(dp.begin(), dp.end(), 0);

		return sum;
	}
};