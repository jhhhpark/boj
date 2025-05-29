#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char str[100], i = 0;
	cin.getline(str, 100);
	while (str[i] != '\0') {
		if (islower(str[i]) != 0) {
			str[i] = toupper(str[i]);
		} else {
			str[i] = tolower(str[i]);
		}
		i++;
	}

	cout << str << '\n';

	return 0;
}