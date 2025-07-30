#include <iostream>

using namespace std;

unsigned long long a, b, c, res;

unsigned long long recursive_multiple(unsigned long long base, unsigned long long exp) {
	if (exp <= 0) {
		return 1;
	} else {
		if ((exp & 1) == 1) {
			unsigned long long half_result = recursive_multiple(base, (exp - 1) / 2);
			return (base * half_result % c) * half_result % c;
		} else {
			unsigned long long half_result = recursive_multiple(base, exp / 2);
			return half_result * half_result % c;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;
	res = recursive_multiple(a % c, b);
	cout << res;

	return 0;
}