#include <iostream>

using namespace std;

int problem_2839()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int result = -1;
	cin >> N;
	for (int i = N / 5; i >= 0; --i)
	{
		if ((N - i * 5) % 3 == 0)
		{
			result = i + (N - i * 5) / 3;
			break;
		}
	}
	cout << result << '\n';
	return 0;
}