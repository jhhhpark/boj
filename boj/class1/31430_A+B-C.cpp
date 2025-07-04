#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, k, B;
	cin >> a >> b >> c;

	k = a;
	B = b;
	while (B > 0) {
		k *= 10;
		B /= 10;
	}

	cout << a + b - c << '\n' << k + b - c << "\n";
	return 0;
}