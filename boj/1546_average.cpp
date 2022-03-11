#include <iostream>

using namespace std;

int problem_1546()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int* nArr = new int[N];

	int nMax = 0;
	int nSum = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> nArr[i];
		if (nMax < nArr[i])
		{
			nMax = nArr[i];
		}
		nSum += nArr[i];
	}

	cout << (float)nSum / (float)nMax * 100.f / (float)N;

	return 0;
}