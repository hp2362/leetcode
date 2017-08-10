/*
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0


*/

class Solution
{
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
	{
		map<int, int> mapB;
		for (auto i : B)
		{
			for (auto j : A)
			{
				mapB[i + j]++;
			}
		}
		map<int, int> mapC;

		for (auto i : C)
		{
			for (auto j : D)
			{
				mapC[i + j]++;
			}
		}
		int sum = 0;
		for (auto begin = mapB.begin(); begin != mapB.end(); begin++)
		{
			if (mapC.find(-begin->first) != mapC.end())
				sum += (begin->second*mapC[-begin->first]);
		}
		return sum;

	}
};