#include <iostream>

using namespace std;

int A()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 0;
	cin >> T;

	int aBoulders[3] = { 0 };
	for (int i = 0; i < T; ++i)
	{
		int nOddCnt = 0;
		for (int j = 0; j < 3; ++j)
		{
			cin >> aBoulders[j];
			nOddCnt += (aBoulders[j] & 1) == 1 ? 1 : 0;
		}
		cout << (nOddCnt >= 2 ? "B" : "R") << "\n";
	}

	return 0;
}