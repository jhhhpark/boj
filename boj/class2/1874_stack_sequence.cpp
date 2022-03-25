#include <iostream>
#include <stack>
#include <list>
using namespace std;

bool isMakeNumOfASC(list<char>* outputList, stack<int>* stack, int seq)
{
	while (stack->empty() == false)
	{
		if (stack->top() == seq)
		{
			stack->pop();
			outputList->push_back('-');
			return true;
		}
		stack->pop();
	}
	return false;
}

int problem_1874()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	stack<int> stack;
	list<char> outputList;
	int n = 0;
	int num = 1;
	int seq = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> seq;

		while (num <= seq)
		{
			stack.push(num);
			outputList.push_back('+');
			++num;
		}

		if (stack.empty() == true || isMakeNumOfASC(&outputList, &stack, seq) == false)
		{
			cout << "NO" << "\n";
			return 0;
		}
	}

	list<char>::iterator iter;
	list<char>::iterator iterEnd = outputList.end();
	for (iter = outputList.begin(); iter != iterEnd; ++iter)
	{
		cout << *iter << "\n";
	}
	return 0;
}