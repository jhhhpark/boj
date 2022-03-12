#include <iostream>

using namespace std;

int problem_2753()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int nYear = 0;
	cin >> nYear;

	cout << (nYear % 400 == 0 || nYear % 4 == 0 && nYear % 100 != 0 ? 1 : 0) << "\n";

	return 0;
}