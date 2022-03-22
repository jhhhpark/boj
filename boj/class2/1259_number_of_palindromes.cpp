#include <iostream>
#include <cstring>
using namespace std;

int problem_1259()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	const char* outputArray[2] = { "yes", "no" };
	char inputNum[6] = { 0, };
	while (true)
	{
		cin >> inputNum;
		if (atoi(inputNum) == 0)
		{
			break;
		}

		int length = strlen(inputNum);
		int ndx = 0;
		for (int i = 0; i < length / 2; ++i)
		{
			if (inputNum[i] != inputNum[length - 1 - i])
			{
				ndx = 1;
				break;
			}
		}

		cout << outputArray[ndx] << '\n';
	}

	return 0;
}