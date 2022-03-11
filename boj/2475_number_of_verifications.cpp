#include <iostream>

using namespace std;

int problem_2475()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int nArr[5] = { 0, };
	unsigned int varifyNum = 0;
	for (int i = 0; i < 5; ++i)
	{
		cin >> nArr[i];
		varifyNum += nArr[i] * nArr[i];
	}
	cout << varifyNum % 10 << '\n';
	return 0;
}