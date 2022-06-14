#include <iostream>
#include <queue>
using namespace std;

bool bPoint[100001] = { false, };
int countOfMove(int depart, int dest);

int problem_1697()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count = 0;
	int N, K;
	cin >> N >> K;

	count = countOfMove(N, K);
	cout << count << '\n';

	return 0;
}

int countOfMove(int depart, int dest)
{
	queue<int> q;
	int count = 0;

	bPoint[depart] = true;
	q.push(depart);
	while (q.empty() == false)
	{
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			int cur = q.front();
			q.pop();
			if (cur == dest) {
				return count;
			}
			else
			{
				bPoint[cur] = true;
				if (cur - 1 >= 0 && bPoint[cur - 1] == false)
				{
					q.push(cur - 1);
				}
				if (cur + 1 <= 100000 && bPoint[cur + 1] == false)
				{
					q.push(cur + 1);
				}
				if (cur * 2 <= 100000 && bPoint[cur * 2] == false)
				{
					q.push(cur * 2);
				}
			}
		}
		++count;
	}

	return count;
}