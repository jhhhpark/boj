#include <iostream>

using namespace std;

int problem_2438()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			cout << '*';
		}
		cout << '\n';
	}

	return 0;
}