#include <iostream>

using namespace std;

void countOfPaper(int x, int y, int len);
bool isSameNumber(int x, int y, int len);

int papers[2188][2188] = { 0, };
int paperCount[3] = { 0, };

int problem_1780()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0, input = 0;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> input;
			papers[i][j] = input;
		}
	}

	countOfPaper(1, 1, N);
	for (int i = 0; i < 3; ++i)
	{
		cout << paperCount[i] << '\n';
	}

	return 0;
}

bool isSameNumber(int x, int y, int len)
{
	int number = papers[y][x];
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			if (papers[y + i][x + j] != number)
			{
				return false;
			}
		}
	}
	return true;
}

void countOfPaper(int x, int y, int len)
{
	if (len == 1 || isSameNumber(x, y, len) == true)
	{
		++paperCount[papers[y][x] + 1];
		return;
	}
	else
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				int divLen = len / 3;
				countOfPaper(x + (j * divLen), y + (i * divLen), divLen);
			}
		}
	}
	return;
}