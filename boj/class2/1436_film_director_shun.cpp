#include <iostream>

using namespace std;

bool isEndNum(int num)
{
	int cnt = 0;
	while (num >= 666)
	{
		if (num % 1000 == 666)
		{
			return true;
		}
		else
		{
			num /= 10;
		}
	}
	return false;
}

int problem_1436()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int inputEndCount = 0;
	int num = 665;

	cin >> inputEndCount;
	while (inputEndCount > 0)
	{
		++num;
		if (isEndNum(num) == true)
		{
			--inputEndCount;
		}
	}

	cout << num << '\n';

	return 0;
}