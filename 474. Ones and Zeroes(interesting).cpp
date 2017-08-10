/*
In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are ¡°10,¡±0001¡±,¡±1¡±,¡±0¡±

*/

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n)
	{
		//  int dp[m+1][n+1];
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		// for(int i = 0;i<=m;i++)
		//   dp[i][0] = 1;
		// for(int j = 0;j<=n;j++)
		// dp[0][j] = 1;
		for (auto mem : strs)
		{
			int a = 0, b = 0;
			for (auto c : mem)
			{
				if (c == '0') a++;
				if (c == '1') b++;
			}
			for (int i = m; i >= 0; i--)
			{
				for (int j = n; j >= 0; j--)
				{
					if (i - a >= 0 && j - b >= 0)
						dp[i][j] = max(dp[i][j], dp[i - a][j - b] + 1);
				}
			}
		}
		return dp[m][n];
	}
};