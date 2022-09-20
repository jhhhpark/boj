#include <iostream>

using namespace std;

int problem_11726()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tiles[1001] = { 0, };
	int N = 0;
	tiles[1] = 1;
	tiles[2] = 2;
	cin >> N;
	for (int i = 3; i <= N; ++i)
	{
		tiles[i] = (tiles[i - 1] + tiles[i - 2]) % 10007;
	}

	cout << tiles[N] << '\n';
	return 0;
}