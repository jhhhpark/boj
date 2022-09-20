#include <iostream>
#include <queue>

using namespace std;

void PassComponents(int from, int N, bool vertex[1001], bool edge[][1001]);
int problem_11724()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool edge[1001][1001] = { false, };
	bool vertex[1001] = { false, };
	int N, M, u, v, cnt = 0;
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v;
		edge[u][v] = true;
		edge[v][u] = true;
	}

	for (int from = 1; from <= N; ++from)
	{
		if (vertex[from] == false)
		{
			++cnt;
			PassComponents(from, N, vertex, edge);
		}
	}

	cout << cnt << '\n';
	return 0;
}

void PassComponents(int from, int N, bool vertex[1001], bool edge[][1001])
{
	queue<int> q;

	q.push(from);
	vertex[from] = true;
	while (!q.empty())
	{
		from = q.front();
		q.pop();

		for (int to = 1; to <= N; ++to)
		{
			if (vertex[to] == false && edge[from][to] == true)
			{
				vertex[to] = true;
				q.push(to);
			}
		}
	}
}