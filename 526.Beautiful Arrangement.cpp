/*
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ? i ? N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

*/

class Solution {
public:
	int countArrangement(int N)
	{
		vector<int> vec;
		for (int i = 0; i < N; i++)
			vec.push_back(i + 1);
		return dfs(vec, N);

	}
	int dfs(vector<int>& vec, int n)
	{
		if (n <= 0) return 1;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (vec[i] % n == 0 || n%vec[i] == 0)
			{
				swap(vec[i], vec[n - 1]);
				ans += dfs(vec, n - 1);
				swap(vec[i], vec[n - 1]);
			}
		}
		return ans;
	}
};