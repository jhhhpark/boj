#include <iostream>
#include <cstring>
using namespace std;

int problem_2675()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char str[21] = { 0, };
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		// input
		int n = 0;
		cin >> n >> str;

		// calc
		for (int i = 0; i < strlen(str); ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << str[i];
			}
		}
		cout << '\n';
	}

	return 0;
}