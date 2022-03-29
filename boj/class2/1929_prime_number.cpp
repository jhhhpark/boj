#include <iostream>

using namespace std;

bool isPrimeNumber(int n)
{
	if (n == 1 || (n & 1) == 0)
	{
		return n == 2;
	}
	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int problem_1929()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M = 0;
	int N = 0;
	cin >> M >> N;

	for (int i = M; i <= N; ++i)
	{
		if (isPrimeNumber(i) == true)
		{
			cout << i << '\n';
		}
	}

	return 0;
}