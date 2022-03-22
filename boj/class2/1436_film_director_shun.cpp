#include <iostream>

using namespace std;

bool isEndNum(int num)
{
	int cnt = 0;
	while (num > 0)
	{
		cnt = num % 10 == 6 ? cnt + 1 : 0;
		num /= 10;
		if (cnt >= 3)
		{
			break;
		}
	}
	return cnt >= 3;
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
		if (isEndNum(++num) == true)
		{
			--inputEndCount;
		}
	}

	cout << num << '\n';

	return 0;
}