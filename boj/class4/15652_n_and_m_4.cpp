#include <iostream>

using namespace std;

int output[9] = { 0, };
int n, m;

void Sequence(int next, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << output[i] << ' ';
		}
		cout << '\n';
	} else {
		for (int i = next; i <= n; i++) {
			output[cnt] = i;
			Sequence(i, cnt + 1);
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	Sequence(1, 0);
	return 0;
}