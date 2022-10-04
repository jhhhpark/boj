#include <iostream>
using namespace std;

int problem_17626 ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int dp[50001] = { 0, };
	int n, j, cnt = 0;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1];
		for (int j = 1; j * j <= i; ++j)
		{
			dp[i] = dp[i] < dp[i - j * j] ? dp[i] : dp[i - j * j];
		}
		dp[i]++;
	}

	cout << dp[n] << '\n';
	return 0;
}