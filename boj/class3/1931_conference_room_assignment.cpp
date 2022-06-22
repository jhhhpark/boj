#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int problem_1931()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> v;
	int N = 0, from = 0, to = 0;
	cin >> N;
	v.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> from >> to;
		v.push_back(make_pair(to, from));
	}
	sort(v.begin(), v.end());

	int earliest = 0, count = 0, begin = 0, end = 0;
	for (size_t i = 0; i < v.size(); ++i)
	{
		begin = v[i].second;
		end = v[i].first;
		if (earliest <= begin)
		{
			earliest = end;
			++count;
		}
	}
	cout << count << '\n';
	return 0;
}