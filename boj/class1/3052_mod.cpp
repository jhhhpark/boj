#include <iostream>

using namespace std;

int problem_3052()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int aModNums[43] = { 0, };
	int nInput = 0;
	int nCount = 0;
	for (int i = 0; i < 10; ++i)
	{
		cin >> nInput;
		++aModNums[nInput % 42];
	}

	for (int i = 0; i < sizeof(aModNums) / sizeof(int); ++i)
	{
		nCount += aModNums[i] > 0 ? 1 : 0;
	}
	
	cout << nCount << "\n";
	return 0;
}