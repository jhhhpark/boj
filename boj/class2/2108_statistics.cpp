#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int problem_2108()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// Input
	int arr[8001] = { 0 };
	int average = 0;
	int median = 0;
	int mode = 0;
	int range = 0;

	int n = 0;
	cin >> n;

	int data = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> data;
		sum += data;
		++arr[data + 4000];
	}

	// Áß¾Ó°ª
	int count = 0;
	for (int i = 0; i < 8001; ++i)
	{
		count += arr[i];
		if (count > n / 2)
		{
			median = i - 4000;
			break;
		}
	}

	// ÃÖ´ë, ÃÖ¼Ú°ª
	int maxNum = 0;
	int minNum = 0;
	for (int i = 0; i < 8001; ++i)
	{
		if (arr[i] != 0)
		{
			minNum = i - 4000;
			break;
		}
	}
	for (int i = 8000; i > -1; --i)
	{
		if (arr[i] != 0)
		{
			maxNum = i - 4000;
			break;
		}
	}

	// ÃÖºó°ª
	int modeCount = 0;
	for (int i = 0; i < 8001; ++i)
	{
		modeCount = modeCount > arr[i] ? modeCount : arr[i];
	}
	int sameCount = 0;
	for (int i = 0; i < 8001; ++i)
	{
		if (arr[i] == modeCount)
		{
			mode = i - 4000;
			++sameCount;
			if (sameCount == 2)
			{
				break;
			}
		}
	}

	int result[4] = { (int)round((double)sum / (double)n), median, mode, maxNum - minNum };
	for (int i = 0; i < 4; ++i)
	{
		cout << result[i] << '\n';
	}
	
	return 0;
}