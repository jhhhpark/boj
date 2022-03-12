#include <iostream>
#include <string>

using namespace std;

int proble_8958()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char str[80] = { 0, };
	int nTestCase = 0;

	cin >> nTestCase;

	for (int i = 0; i < nTestCase; ++i)
	{
		cin >> str;

		int nAcc = 0;
		int nScore = 0;
		int ndx = 0;
		while (str[ndx] != '\0')
		{
			if (str[ndx] == 'O')
			{
				++nScore;
				nAcc += nScore;
			}
			else
			{
				nScore = 0;
			}
			++ndx;
		}

		cout << nAcc << "\n";
	}

	return 0;
}