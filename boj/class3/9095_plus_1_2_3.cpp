#include <iostream>
#include <vector>

using namespace std;

int problem_9095()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, cnt = 0;
	int arr[11] = { 1, 1, 2 };
	for (int i = 3; i < 11; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		cout << arr[N] << '\n';
	}

	return 0;
}