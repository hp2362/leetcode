/*
Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]


*/

class Solution {
public:
	vector<int> maxVector(vector<int> nums, int k) {
		while (nums.size() > k) {
			int i = 0, n = nums.size();
			for (; i < n - 1; ++i) {
				if (nums[i] < nums[i + 1]) {
					nums.erase(nums.begin() + i);
					break;
				}
			}
			if (i == n - 1) nums.erase(nums.begin() + i);
		}

		return nums;
	}

	bool compare(vector<int> &nums1, int i, vector<int> &nums2, int j) {
		while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
			++i;
			++j;
		}
		if (j == nums2.size()) return true;
		if (i < nums1.size() && nums1[i] > nums2[j]) return true;
		return false;
	}

	vector<int> merge(vector<int> &nums1, vector<int> &nums2, int k) {
		vector<int> res(k, 0);
		for (int i = 0, j = 0, r = 0; r < k; ++r) {
			res[r] = compare(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
		}

		return res;
	}

	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		int m = nums1.size(), n = nums2.size();
		vector<int> res(k, 0);

		for (int i = max(0, k - n); i <= min(k, m); ++i) {
			auto v1 = maxVector(nums1, i);
			auto v2 = maxVector(nums2, k - i);
			auto tmp = merge(v1, v2, k);
			if (compare(tmp, 0, res, 0)) res = tmp;
		}

		return res;
	}
};