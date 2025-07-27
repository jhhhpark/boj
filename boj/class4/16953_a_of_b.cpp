#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, cnt = 1;
	cin >> a >> b;

	while (a < b) {
		if ((b & 1) == 1 && (b % 10) != 1) break;
		b = b & 1 ? b / 10 : b / 2;
		cnt++;
	}

	cout << (a == b ? cnt : -1) << '\n';
	return 0;
}