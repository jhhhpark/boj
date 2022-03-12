#include <iostream>

using namespace std;

int problem_2577()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int aNum[10] = { 0, };
	int A;
	int B;
	int C;
	cin >> A >> B >> C;
	int nNum = A * B * C;

	while (nNum > 0)
	{
		++aNum[nNum % 10];
		nNum /= 10;
	}
	for (int i = 0; i < sizeof(aNum) / sizeof(int); ++i)
	{
		cout << aNum[i] << '\n';
	}

	return 0;
}