#include <iostream>

using namespace std;

int problem_11720()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	char strNum[101] = { 0, };
	int nSum = 0;
	cin >> N >> strNum;

	int index = 0;
	for (int i = 0; i < N; ++i)
	{
		nSum += strNum[i] - '0';
	}
	cout << nSum;

	return 0;
}