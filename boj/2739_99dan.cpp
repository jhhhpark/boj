#include <iostream>

using namespace std;

int problem_2739()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	cin >> N;

	for (int i = 1; i <= 9; ++i)
	{
		cout << N << " * " << i << " = " << N * i << "\n";
	}

	return 0;
}