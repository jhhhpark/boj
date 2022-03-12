#include <iostream>

using namespace std;

int problem_2439()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = N-1; j >= 0; --j)
		{
			cout << ((i < j) ? ' ' : '*');
		}
		cout << '\n';
	}

	return 0;
}