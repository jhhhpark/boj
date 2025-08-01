#include <iostream>
#include <algorithm>

using namespace std;

#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

inline int max(int a, int b) { return a > b ? a : b; }

int stk[2][100002] = { 0, };
int dp[2][100002] = { 0, };

int main()
{
	fastio
	int t, n;
	int res = 0;
	cin >> t;
	while (t-- > 0) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {r
				cin >> stk[i][j];
			}
		}

		dp[0][1] = stk[0][1];
		dp[1][1] = stk[1][1];
		for (int i = 1; i < n; i++) {
			dp[0][i + 1] = max(dp[1][i - 1], dp[1][i]) + stk[0][i + 1];
			dp[1][i + 1] = max(dp[0][i - 1], dp[0][i]) + stk[1][i + 1];
		}

		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
	return 0;
}