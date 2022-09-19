#include <iostream>
using namespace std;

void findRoute(int nodeCnt, bool edge[][101])
{
	for (int mid = 1; mid <= nodeCnt; ++mid)
	{
		for (int from = 1; from <= nodeCnt; ++from)
		{
			for (int to = 1; to <= nodeCnt; ++to)
			{
				if (edge[from][to] == false && edge[from][mid] == true && edge[mid][to] == true)
				{
					edge[from][to] = true;
				}
			}
		}
	} 
	return;
}

int problem_11403()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int nodeCnt = 0;
	bool edge[101][101] = { 0, };

	cin >> nodeCnt;
	for (int i = 1; i <= nodeCnt; ++i)
	{
		for (int j = 1; j <= nodeCnt; ++j)
		{
			cin >> edge[i][j];
		}
	}

	findRoute(nodeCnt, edge);
	for (int i = 1; i <= nodeCnt; ++i)
	{
		for (int j = 1; j <= nodeCnt; ++j)
		{
			cout << edge[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

