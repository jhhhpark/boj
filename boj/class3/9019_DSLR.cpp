#include <iostream>
#include <queue>
#include <string>

using namespace std;

string Progress(int n, int ans)
{
	bool visited[10000] = { false, };
	queue<pair<int, string>> q;
	q.emplace(n, "");
	visited[n] = true;

	while (q.empty() == false)
	{
		int cur = q.front().first;
		string cmd = q.front().second;
		q.pop();
		if (cur == ans)
		{
			return cmd;
		}

		int D, S, L, R;
		D = cur * 2 % 10000;
		S = cur - 1 < 0 ? 9999 : cur - 1;
		L = cur % 1000 * 10 + cur / 1000;
		R = cur % 10 * 1000 + cur / 10;

		if (visited[D] == false)
		{
			visited[D] = true;
			q.emplace(D, cmd + "D");
		}

		if (visited[S] == false)
		{
			visited[S] = true;
			q.emplace(S, cmd + "S");
		}

		if (visited[L] == false)
		{
			visited[L] = true;
			q.emplace(L, cmd + "L");
		}

		if (visited[R] == false)
		{
			visited[R] = true;
			q.emplace(R, cmd + "R");
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> cmdLine;
	int T, n, ans;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> n >> ans;
		string cmdLine = Progress(n, ans);
		cout << cmdLine << '\n';
	}

	return 0;
}