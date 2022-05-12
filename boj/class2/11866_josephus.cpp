#include <iostream>
#include <queue>
using namespace std;

int problem_11866()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;
	int N = 0, K = 0;
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		q.push(i + 1);
	}
	cout << '<';
	while (q.empty() == false)
	{
		for (int i = 1; i < K; ++i)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (q.empty() == false)
		{
			cout << ", ";
		}
	}
	cout << '>' << '\n';

	return 0;
}