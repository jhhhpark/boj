#include <iostream>

using namespace std;

int problem_2292()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int passCount = 1;
	int bound = 0;
	int N = 0;
	cin >> N;

	if (N > 1)
	{
		while (bound < N - 1)
		{
			bound += passCount * 6;
			++passCount;
		}
	}
	cout << passCount << '\n';
	return 0;
}
