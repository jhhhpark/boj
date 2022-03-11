#include <iostream>

using namespace std;

int problem_2562()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int nArr[9] = { 0, };
	int nMaxIndex = 0;
	for (int i = 0; i < sizeof(nArr) / sizeof(int); ++i)
	{
		cin >> nArr[i];
		nMaxIndex = ((nArr[nMaxIndex] < nArr[i]) ? i : nMaxIndex);
	}
	cout << nArr[nMaxIndex] << '\n' << nMaxIndex + 1 << '\n';

	return 0;
}