#include <iostream>

using namespace std;

int problem_11047()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arrCoin[10] = { 1, };
	int N, K, cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> arrCoin[i];
	}

	int index = N - 1;
	while (K > 0)
	{
		int tmp = K / arrCoin[index];
		if (tmp > 0)
		{
			cnt += tmp;
			K %= arrCoin[index];
		}
		--index;
	}
	cout << cnt << '\n';
	return 0;
}