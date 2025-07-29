#include <iostream>
#include <climits>

using namespace std;

int house[1000][3];
int ci[3][2] = { 1, 2, 0, 2, 0, 1 };
int memo[1000][3] = { 0, };

int Distance(int n, int c) {
	if (n == 0) {
		return house[n][c];
	} else {
		int i1 = ci[c][0];
		int i2 = ci[c][1];
		if (memo[n][c] == 0) {
			int r1 = Distance(n - 1, i1);
			int r2 = Distance(n - 1, i2);
			int mv = min(r1, r2);
			memo[n][c] = mv;
		}
		return house[n][c] + memo[n][c];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int cost = INT_MAX;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> house[i][j];
		}
	}
	
	for (int i = 0; i < 3; i++) {
		int res = Distance(n - 1, i);
		if (res < cost) {
			cost = res;
		}
	}

	cout << cost;
	return 0;
}