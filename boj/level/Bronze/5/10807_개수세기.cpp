#include <iostream>

using namespace std;

#define ARRAY_SIZE	100

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[ARRAY_SIZE];
	int n, v, cnt = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> v;

	for (int i = 0; i < n; i++) {
		if (arr[i] == v) {
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}