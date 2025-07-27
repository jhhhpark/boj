#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int result[100001];
bool check[100001];
vector<int> input[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	queue<int> q;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int nd1, nd2;
		cin >> nd1 >> nd2;
		input[nd1].emplace_back(nd2);
		input[nd2].emplace_back(nd1);
	}

	q.push(1);
	check[1] = true;
	while (!q.empty()) {
		int n1 = q.front();
		q.pop();
		for (int i = 0; i < input[n1].size(); i++) {
			int n2 = input[n1][i];
			if (check[n2] == false) {
				q.push(n2);
				check[n2] = true;
				result[n2] = n1;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << result[i] << '\n';
	}

	return 0;
}