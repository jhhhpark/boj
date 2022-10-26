#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_SIZE						1'000'000
#define DELETE_MIN_INSTRUCTION			-1
#define DELETE_MAX_INSTRUCTION			1


void SyncPriorityMinQ(
	bool* invalid,
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& minQ
)
{
	while (minQ.empty() == false && invalid[minQ.top().second] == true)
	{
		minQ.pop();
	}

	return;
}

void SyncPriorityMaxQ(
	bool* invalid,
	priority_queue<pair<int, int>, vector<pair<int, int>>>& maxQ
) {
	while (maxQ.empty() == false && invalid[maxQ.top().second] == true)
	{
		maxQ.pop();
	}

	return;
}

void PrintQ(
	priority_queue<pair<int, int>, vector<pair<int, int>>>& maxQ,
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& minQ
) {
	bool empty = maxQ.empty() || minQ.empty();
	if (empty == true)
	{
		cout << "EMPTY" << '\n';
	}
	else
	{
		cout << maxQ.top().first << ' ' << minQ.top().first << '\n';
	}

	return;
}

void Progress(
	priority_queue<pair<int, int>, vector<pair<int, int>>>& maxQ,
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& minQ
) {
	bool invalid[MAX_SIZE] = { false, };
	int N, num;
	char order;

	cin >> N;
	for (int index = 0; index < N; ++index)
	{
		cin >> order >> num;
		if (order == 'I')
		{
			minQ.emplace(num, index);
			maxQ.emplace(num, index);
		}
		else if (order == 'D')
		{
			if (num == DELETE_MIN_INSTRUCTION)
			{
				SyncPriorityMinQ(invalid, minQ);
				if (minQ.empty() == false)
				{
					int del = minQ.top().second;
					invalid[del] = true;
					minQ.pop();
				}
			}
			else if (num == DELETE_MAX_INSTRUCTION)
			{
				SyncPriorityMaxQ(invalid, maxQ);
				if (maxQ.empty() == false)
				{
					int del = maxQ.top().second;
					invalid[del] = true;
					maxQ.pop();
				}
			}

		}
	}

	SyncPriorityMinQ(invalid, minQ);
	SyncPriorityMaxQ(invalid, maxQ);
	return;
}

int problem_7662()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		vector<pair<int, int>> v1;
		vector<pair<int, int>> v2;
		v1.reserve(MAX_SIZE);
		v2.reserve(MAX_SIZE);

		priority_queue<pair<int, int>, vector<pair<int, int>>> maxQ(less<pair<int, int>>(), move(v1));
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minQ(greater<pair<int, int>>(), move(v2));

		Progress(maxQ, minQ);
		PrintQ(maxQ, minQ);
	}

	return 0;
}