#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int problem_2775()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k = 0;
	int n = 0;
	int testCase = 0;
	cin >> testCase;

	int arr[15][15] = { 0, };
	for (int i = 1; i < 15; ++i)
	{
		arr[0][i] = i;
	}
	for (int floor = 1; floor < 15; ++floor)
	{
		for (int no = 1; no < 15; ++no)
		{
			arr[floor][no] = arr[floor - 1][no] + arr[floor][no - 1];
		}
	}
	for (int i = 0; i < testCase; ++i)
	{
		cin >> k >> n;
		cout << arr[k][n] << '\n';
	}

	return 0;
}