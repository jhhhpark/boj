#include <iostream>

using namespace std;

int problem_11727()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int arrTile[1001] = { 0, };
	arrTile[1] = 1;
	int n = 0;
	cin >> n;
	for (int i = 2; i <= n; ++i)
	{
		arrTile[i] = (arrTile[i - 1] * 2 + ((i & 1) == 0 ? 1 : -1)) % 10007;
	}
	cout << arrTile[n] << '\n';

	return 0;
}