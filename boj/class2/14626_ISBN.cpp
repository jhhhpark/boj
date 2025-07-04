#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int kArr[10] = { 0, 7, 4, 1, 8, 5, 2, 9, 6, 3 };
	char input[14];
	int sum = 0;
	int k = 0;

	cin >> input;
	int length = sizeof(input) - 2;
	for (int i = 0; i < length; i++) {
		int bias = i % 2 == 0 ? 1 : 3;
		if (input[i] == '*') {
			k = bias;
			continue;
		}
		int num = input[i] - '0';
		sum += num * bias;
	}
	sum += input[length] - '0';
	int res = (10 - (sum % 10)) % 10;
	cout << (k == 3 ? kArr[res] : res) << '\n';
	return 0;
}