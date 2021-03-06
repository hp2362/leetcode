/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

*/

class Solution {
public:
	int calculate(string s)
	{
		istringstream in('+' + s + '+');
		long long total = 0, term = 0, n;
		char op;
		while (in >> op)
		{
			if (op == '+' || op == '-')
			{
				total += term;
				in >> term;
				if (op == '-') term = -term;
			}
			else
			{
				in >> n;
				if (op == '*') term *= n;
				else term /= n;
			}
		}
		return total;
	}
};