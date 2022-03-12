#include <iostream>

using namespace std;

int problem_10818()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int nMin = 1000000;
	int nMax = -1000000;
	int nCnt = 0;
	int nData = 0;
	
	cin >> nCnt;

	for (int i = 0; i < nCnt; ++i)
	{
		cin >> nData;
		nMin = (nMin < nData) ? nMin : nData;
		nMax = (nMax > nData) ? nMax : nData;
	}

	cout << nMin << " " << nMax;

	return 0;
}