#include <iostream>
#include <math.h>
using namespace std;

int problem_2908()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int nData1 = 0;
	int nData2 = 0;
	cin >> nData1 >> nData2;

	int n1 = 0;
	int n2 = 0;
	for (int i = 0; i < 3; ++i)
	{
		
		n1 += nData1 % 10 * (int)pow(10, 2 - i);
		n2 += nData2 % 10 * (int)pow(10, 2 - i);

		nData1 /= 10;
		nData2 /= 10;
	}

	cout << (n1 > n2 ? n1 : n2) << "\n";

	return 0;
}