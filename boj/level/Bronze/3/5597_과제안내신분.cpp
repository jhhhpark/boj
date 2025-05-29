#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool bSubmit[31] = { false, };
	int number;
	for (int i = 0; i < 28; i++) {
		cin >> number;
		bSubmit[number] = true;
	}

	for (int i = 1; i <= 30; i++) {
		if (bSubmit[i] == false) {
			cout << i << '\n';
		}
	}

	return 0;
}