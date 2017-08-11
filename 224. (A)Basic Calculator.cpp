/*

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
*/

class Solution {
public:
	int calculate(string s)
	{
		//
		int number = 0;
		int sigh = 1;
		int result = 0;
		stack<int> stack;
		for (auto i : s)
		{
			if (i >= '0'&&i <= '9')//Êý×Ö
			{
				number = number * 10 + i - '0';
			}
			else if (i == '+')
			{
				result += sigh*number;
				number = 0;
				sigh = 1;
			}
			else if (i == '-')
			{
				result += sigh*number;
				number = 0;
				sigh = -1;
			}
			else if (i == '(')
			{
				stack.push(result);
				stack.push(sigh);
				sigh = 1;
				result = 0;
			}
			else if (i == ')')
			{
				result += sigh*number;
				number = 0;
				result *= stack.top();
				stack.pop();
				result += stack.top();
				stack.pop();
			}
		}
		result += sigh*number;
		return result;
	}
};