#include <iostream>

using namespace std;

int n;
int trg[501][501];
int cost[501][501] = { 0, };
int res = 0;

void SearchTree(int depth) {
	if (depth == n) {
		for (int i = 0; i < n; i++) {
			if (res < cost[n - 1][i]) {
				res = cost[n - 1][i];
			}
		}
	} else {
		for (int i = 0; i < depth; i++) {
			int pcost = cost[depth - 1][i];
			for (int j = 0; j < 2; j++) {
				int tcost = pcost + trg[depth][i + j];
				if (cost[depth][i + j] < tcost) {
					cost[depth][i + j] = tcost;
				}
			}
		}
		SearchTree(depth + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> trg[i][j];
		}
	}

	cost[0][0] = trg[0][0];
	SearchTree(1);

	cout << res;
	return 0;
}