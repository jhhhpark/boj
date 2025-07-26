#include <iostream>
#include <stack>

using namespace std;

stack<int> track;
bool visited[9][9] = { false, };
int output[9] = { 0, };
int n, m;

void comb(int next, int cnt) {
	if (cnt == m) {
		for (int idx = 0; idx < cnt; idx++) {
			cout << output[idx] << ' ';
		}
		cout << '\n';
	} else {
		for (int i = next; i <= n; i++) {
			if (cnt < m) {
				output[cnt] = i;
				comb(i + 1, cnt + 1);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt = 0;
	cin >> n >> m;
	comb(1, 0);

	//for (int base = 1; base <= n - m + 1; base++) {
	//	track.push(base);
	//	output[cnt++] = base;
	//	while (!track.empty()) {
	//		int dep = track.top();
	//		for (int dst = dep + 1; dst <= n; dst++) {
	//			if (track.size() == m) break;
	//			if (visited[dep][dst] == false) {
	//				visited[dep][dst] = true;
	//				visited[dst][dep] = true;
	//				track.push(dst);r
	//				output[cnt++] = dst;
	//				dep = dst;
	//			}
	//		}

	//		if (track.size() == m) {
	//			for (int i = 0; i < m; i++) {
	//				cout << output[i] << ' ';
	//			}
	//			cout << '\n';
	//		}

	//		dep = track.top();
	//		for (int i = dep + 1; i <= n; i++) {
	//			visited[dep][i] = false;
	//		}
	//		track.pop();
	//		cnt--;
	//	}
	//}

	return 0;
}