#include <iostream>
#include <cstring>

#define STRING_SIZE		(1000)

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	char str[STRING_SIZE];

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> str;
		cout << str[0] << str[strlen(str) - 1] << '\n';
	}

	return 0;
}