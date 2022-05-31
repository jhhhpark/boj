#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

#define MAX_VERTEX			1000

void DFS(bool[][MAX_VERTEX + 1], int, int);
void BFS(bool[][MAX_VERTEX + 1], int, int);
void print(vector<int>&);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool edges[MAX_VERTEX + 1][MAX_VERTEX + 1] = { false, };
	int N = 0, M = 0, V = 0;
	cin >> N >> M >> V;

	int from = 0, to = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> from >> to;
		edges[from][to] = true;
		edges[to][from] = true;
	}

	DFS(edges, N, V);
	BFS(edges, N, V);

	return 0;
}

void DFS(bool edges[][MAX_VERTEX + 1], int vCnt, int start)
{
	bool vertexs[MAX_VERTEX + 1] = { false, };
	stack<int> st;
	vector<int> v;
	v.reserve(vCnt);

	vertexs[start] = true;
	st.push(start);
	v.push_back(start);
	while (st.empty() == false)
	{
		int cur = st.top();
		st.pop();

		for (int i = 1; i <= vCnt; ++i)
		{
			if (vertexs[i] == false && edges[cur][i] == true)
			{
				vertexs[i] = true;

				st.push(cur);
				st.push(i);
				v.push_back(i);
				break;
			}
		}
	}
	
	print(v);
	return;
}

void BFS(bool edges[][MAX_VERTEX + 1], int vCnt, int start)
{
	bool vertexs[MAX_VERTEX + 1] = { false, };
	queue<int> q;
	vector<int> v;
	v.reserve(vCnt);

	vertexs[start] = true;
	q.push(start);
	v.push_back(start);
	while (q.empty() == false)
	{
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= vCnt; ++i)
		{
			if (vertexs[i] == false && edges[cur][i] == true)
			{
				vertexs[i] = true;

				q.push(i);
				v.push_back(i);
			}
		}
	}

	print(v);
	return;
}

void print(vector<int>& v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << ' ';
	}
	cout << '\n';
	return;
}