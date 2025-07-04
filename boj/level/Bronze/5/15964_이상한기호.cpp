#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b;
	while (true) {
		cin >> a >> b;
		if (cin.eof()) {
			break;
		}
		cout << (a + b) * (a - b) << '\n';
	}
	
	return 0;
}