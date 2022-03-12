#include <iostream>
using namespace std;

int problem_2920()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int asc = 12345678;
	int dsc = 87654321;

	int n = 0;
	int nScale = 0;

	for (int i = 0; i < 8; ++i)
	{
		cin >> n;
		nScale = 10 * nScale + n;
	}

	if (nScale == asc)
	{
		cout << "ascending" << "\n";
	}
	else if (nScale == dsc)
	{
		cout << "descending" << "\n";
	}
	else
	{
		cout << "mixed" << "\n";
	}

	return 0;
}