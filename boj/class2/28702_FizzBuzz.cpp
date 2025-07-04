#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char input[3][9] = { 0, };
	bool isEnd = false;
	for (int i = 0; i < 3; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < 3; i++) {
		char firstInput = input[i][0];
		if (firstInput != 'F' && firstInput != 'B') {
			int j = 0;
			int pow = 1;
			int result = 0;
			while (input[i][j] != '\0') {
				j++;
			}
			
			while (j > 0) {
				int num = (input[i][j - 1] - '0') * pow;
				result += num;
				pow *= 10;
				j--;
			}
			result = result + 3 - i;
			if (result % 3 != 0 && result % 5 != 0) {
				cout << result << '\n';
			} else {
				if (result % 3 == 0) {
					cout << "Fizz";
				}
				if (result % 5 == 0) {
					cout << "Buzz";
				}
				cout << '\n';
			}
			break;
		}
	}

	return 0;
}