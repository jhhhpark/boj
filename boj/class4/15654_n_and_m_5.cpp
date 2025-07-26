#include <iostream>
#include <cstdlib>

using namespace std;

int n, m;
int output[8] = { 0, };
int arr[8] = { 0, };
bool visited[8] = { false, };

int Compare(const void* arg1, const void* arg2) {
	int n1 = *(int*)arg1;
	int n2 = *(int*)arg2;
	if (n1 == n2) {
		return 0;
	} else {
		if (n1 < n2) {
			return -1;
		} else {
			return 1;
		}
	}
}

void Sequence(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << output[i] << ' ';
		}
		cout << '\n';
	} else {
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				output[cnt] = arr[i];
				Sequence(cnt + 1);
				visited[i] = false;
			}
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	qsort((void*)arr, (size_t)n, (size_t)sizeof(int), Compare);
	Sequence(0);
	return 0;
}