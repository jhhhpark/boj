#include <iostream>
#include <stack>

using namespace std;

#define MAX_COMPUTER	101

int CountOfCompWithVirus(bool network[][MAX_COMPUTER], int computers);

int problem_2606()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool network[MAX_COMPUTER][MAX_COMPUTER] = { false, };
	int computers, networks, from, to, count;
	cin >> computers >> networks;
	for (int i = 1; i <= networks; ++i)
	{
		cin >> from >> to;
		network[from][to] = true;
		network[to][from] = true;
	}
	count = CountOfCompWithVirus(network, computers);
	cout << count << '\n';
	return 0;
}

int CountOfCompWithVirus(bool network[][MAX_COMPUTER], int computers) {
	stack<int> st;
	bool compWithVirus[MAX_COMPUTER] = { false, };
	int count = 0, start= 1;

	st.push(start);
	compWithVirus[start] = true;
	while (st.empty() == false)
	{
		int from = st.top();
		st.pop();
		for (int to = start; to <= computers; ++to)
		{
			if (compWithVirus[to] == false && network[from][to] == true)
			{
				st.push(from);
				st.push(to);
				compWithVirus[to] = true;
				++count;
				break;
			}
		}
	}

	return count;
}
