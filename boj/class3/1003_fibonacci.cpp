#include <iostream>

using namespace std;

int problem_1003()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	pair<int, int> fibo[41];
	fibo[0].first = 1;
	fibo[0].second = 0;
	fibo[1].first = 0;
	fibo[1].second = 1;
	for (int i = 2; i < sizeof(fibo) / sizeof(pair<int, int>); ++i)
	{
		int zeroCnt = fibo[i - 2].first + fibo[i - 1].first;
		int oneCnt = fibo[i - 2].second + fibo[i - 1].second;
		fibo[i].first = zeroCnt;
		fibo[i].second = oneCnt;
	}

	int T = 0, N = 0;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		cout << fibo[N].first << ' ' << fibo[N].second << '\n';
	}

	return 0;
}