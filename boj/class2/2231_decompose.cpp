#include <iostream>
#include <vector>
using namespace std;

int GetDicompose(int n)
{
	int decompose = n;
	while (n > 0)
	{
		decompose += n % 10;
		n /= 10;
	}
	return decompose;
}

int problem_2231()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int result = 0;
	cin >> N;

	for (int i = 1; i < N; ++i)
	{
		int index = GetDicompose(i);
		if (index == N)
		{
			result = i;
			break;
		}
	}
	cout << result << '\n';

	return 0;
}