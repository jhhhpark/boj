#include <iostream>
#include <queue>

using namespace std;

#define MAX_USER					100
#define MAX_RELATION				2147483647

int GetKevinBaconNumber(bool relations[][MAX_USER + 1], int from, int N);

int problem_1389()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool relations[MAX_USER + 1][MAX_USER + 1] = { false, };
	int minUser = 101;
	int minKevinBaconNumber = MAX_RELATION;
	int from = 0, to = 0;
	int N = 0, M = 0;
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		cin >> from >> to;
		relations[from][to] = true;
		relations[to][from] = true;
	}

	for (int from = 1; from <= N; ++from)
	{
		int kevinBaconNumber = GetKevinBaconNumber(relations, from, N);
		if (kevinBaconNumber < minKevinBaconNumber)
		{
			minKevinBaconNumber = kevinBaconNumber;
			minUser = from;
		}
	}

	cout << minUser << '\n';
	return 0;
}

int GetKevinBaconNumber(bool relations[][MAX_USER + 1], int from, int N)
{
	queue<int> q;
	bool users[MAX_USER + 1] = { false, };
	int kevinBaconNumber = 0;
	int degree = 1;

	q.push(from);
	users[from] = true;
	while (q.empty() == false)
	{
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			from = q.front();
			q.pop();
			for (int to = 1; to <= N; ++to)
			{
				if (users[to] == false && relations[from][to] == true)
				{
					users[to] = true;
					q.push(to);
					kevinBaconNumber += degree;
				}
			}
		}
		++degree;
	}

	return kevinBaconNumber;
}