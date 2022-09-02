#include <iostream>

using namespace std;

int problem_9461()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long P[101] = { 0ll, 1ll, 1ll, 1ll, 2ll, 2ll};
	int T, N;
	for (int i = 6; i < 101; ++i)
	{
		P[i] = P[i - 1] + P[i - 5];
	}

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		cout << P[N] << '\n';
	}

	return 0;
}