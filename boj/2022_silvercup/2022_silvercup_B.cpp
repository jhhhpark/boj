#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 0;
	cin >> T;

	int aBoulders[3] = { 0 };
	for (int i = 0; i < T; ++i)
	{
		int nEvenCnt = 0;
		for (int j = 0; j < 3; ++j)
		{
			cin >> aBoulders[j];
			nEvenCnt += (aBoulders[j] & 1) == 0 ? 1 : 0;
		}
		cout << (nEvenCnt >= 2 ? "B" : "R") << "\n";
	}

	return 0;
}