#include <iostream>

using namespace std;

int factorial(int n)
{
	int result = 1;
	for (int i = 0; i < n; ++i)
	{
		result *= n - i;
	}
	return result;
}

int problem_11050()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	int result = 0;
	cin >> N >> K;
	result = factorial(N) / factorial(N - K) / factorial(K);
	cout << result << '\n';
	return 0;
}