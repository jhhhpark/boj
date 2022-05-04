#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int problem_7568()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<int, int>> ranks;
	int w = 0;
	int h = 0;

	int n = 0;
	cin >> n;
	ranks.reserve(n + 1);
	for (int i = 0; i < n; ++i)
	{
		cin >> w >> h;
		ranks.push_back(pair<int, int>(w, h));
	}

	for (int i = 0; i < n; ++i)
	{
		int rank = 1;
		for (int j = 0; j < n; ++j)
		{
			int rankCount = 0;
			rankCount += ranks[i].first < ranks[j].first ? 1 : 0;
			rankCount += ranks[i].second < ranks[j].second ? 1 : 0;
			rank += rankCount == 2 ? 1 : 0;
		}
		cout << rank << ' ';
	}

	return 0;
}