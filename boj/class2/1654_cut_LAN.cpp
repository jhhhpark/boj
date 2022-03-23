#include <iostream>
#include <limits.h>
using namespace std;

int cutToLineCount(int* LANs, int line, int K)
{
	int cnt = 0;
	for (int i = 0; i < K; ++i)
	{
		cnt += LANs[i] / line;
	}
	return cnt;
}

int cutToLongestLine(int* LANs, int max, int K, int N)
{
	if (cutToLineCount(LANs, max, K) >= N)
	{
		return max;
	}
	int begin = 1;
	int end = max;
	int line = 0;

	while (begin < end)
	{
		line = begin + (end - begin) / 2;
		if (cutToLineCount(LANs, line, K) < N)
		{
			end = line;
		}
		else
		{
			begin = line + 1;
		}
	}

	return begin - 1;
}

int problem_1654()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K = 0;
	int N = 0;
	int max = -1;
	int line = 0;
	cin >> K >> N;

	int* LANs = new int[K];
	for (int i = 0; i < K; ++i)
	{
		cin >> LANs[i];
		max = max > LANs[i] ? max : LANs[i];
	}
	line = cutToLongestLine(LANs, max, K, N);

	cout << line << '\n';

	delete[] LANs;
	return 0;
}