#include <iostream>
#include <stack>
using namespace std;

struct ParseStack
{
	stack<int> stNum;
	stack<char> stOpt;
};

void Parse(ParseStack& ps, char* equation, int len)
{
	int sum = 0;
	for (int i = 0; i < len; ++i)
	{
		if (equation[i] == '+' || equation[i] == '-')
		{
			ps.stOpt.push(equation[i]);
			ps.stNum.push(sum);
			sum = 0;
		}
		else
		{
			sum *= 10;
			sum += equation[i] - '0';
		}
	}
	ps.stNum.push(sum);
	return;
}

int Calculation(ParseStack& ps)
{
	int result = 0;
	int sum = 0;
	while (ps.stOpt.empty() == false)
	{
		int num = ps.stNum.top();
		ps.stNum.pop();

		char opt = ps.stOpt.top();
		ps.stOpt.pop();
		if (opt == '-')
		{
			sum = ~(sum + num) + 1;
			result += sum;
			sum = 0;
		}
		else
		{
			sum += num;
		}
	}
	return result + sum + ps.stNum.top();
}
int problem_1541()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char equation[51] = { 0, };
	ParseStack ps;
	int result = 0;
	cin >> equation;

	int len = 0;
	while (equation[len] != '\0') { ++len; }

	Parse(ps, equation, len);
	result = Calculation(ps);
	cout << result << '\n';

	return 0;
}