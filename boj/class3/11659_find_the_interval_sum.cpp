#include <iostream>

using namespace std;

int problem_11659()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[100001] = { 0, };
	int N, M, i, j;
	int idx = 0;
	cin >> N >> M;
	for (idx = 1; idx <= N; ++idx)
	{
		cin >> arr[idx];
		arr[idx] += arr[idx - 1];
	}

	idx = 0;
	while (idx < M)
	{
		cin >> i >> j;
		cout << arr[j] - arr[i - 1] << '\n';
		++idx;
	}

	return 0;
}