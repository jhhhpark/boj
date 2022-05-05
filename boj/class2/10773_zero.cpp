#include <iostream>
#include <stack>
using namespace std;

int problem_10773()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> st;
	int K = 0;
	int num = 0;
	int sum = 0;
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		cin >> num;
		if (num == 0)
		{
			st.pop();
		}
		else
		{
			st.push(num);
		}
	}
	while (st.empty() == false)
	{
		sum += st.top();
		st.pop();
	}
	cout << sum << '\n';
	return 0;
}