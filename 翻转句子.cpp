/*
Input: "Let's take LeetCode contest"
	Output : "s'teL ekat edoCteeL tsetnoc"
*/

class Solution {
public:
	string reverseWords(string s)
	{
		istringstream is(s);
		string ret;
		string tmp;
		while (is >> tmp)
		{
			reverse(tmp.begin(), tmp.end());
			ret += (tmp);
			ret += " ";
		}
		ret.pop_back();
		return ret;
	}
};