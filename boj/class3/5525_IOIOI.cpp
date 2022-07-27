#include <iostream>

using namespace std;

int problem_5525()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0, M = 0, result = 0;
	string str;
	cin >> N >> M >> str;
	for (int i = 0; i < M; ++i)
	{
		if (str[i] == 'O') continue;
		int cnt = 0;

		while (str[i + 1] == 'O' && str[i + 2] == 'I')
		{
			++cnt;
			i += 2;
			if (cnt == N)
			{
				--cnt;
				++result;
			}
		}
	}

	cout << result << '\n';
	return 0;
}