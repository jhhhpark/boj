#include <iostream>

using namespace std;

int gcd(int a, int b) 
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int problem_6064()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int M, N, x, y, j;
	int cnt;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> M >> N >> x >> y;
		int lim = lcm(M, N);
		for (j = x; j <= lim; j += M)
		{
			int tmp = (j % N) == 0 ? N : j % N;
			if (tmp == y)
			{
				cout << j << '\n';
				break;
			}
		}
		if (j > lim) {
			cout << "-1\n";
			continue;
		}
	}
	return 0;
}