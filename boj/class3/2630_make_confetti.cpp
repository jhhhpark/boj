#include <iostream>

using namespace std;

#define MAX_NUM_SIZE		129


void CountOfPaper(int paper[][MAX_NUM_SIZE], int x, int y, int length, int* count);
bool IsSamePaper(int paper[][MAX_NUM_SIZE], int x, int y, int length);
int problem_2630()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int paper[MAX_NUM_SIZE][MAX_NUM_SIZE] = { 0, };
	int count[2] = { 0, };
	int length = 0;
	cin >> length;
	for (int i = 1; i <= length; ++i)
	{
		for (int j = 1; j <= length; ++j)
		{
			cin >> paper[i][j];
		}
	}
	CountOfPaper(paper, 1, 1, length, count);
	for (int i = 0; i < sizeof(count) / sizeof(int); ++i)
	{
		cout << count[i] << '\n';
	}
	
	return 0;
}

void CountOfPaper(int paper[][MAX_NUM_SIZE], int x, int y, int length, int* count)
{
	if (length == 1 || IsSamePaper(paper, x, y, length) == true)
	{
		int index = paper[y][x];
		++count[index];
	}
	else
	{
		int half = length / 2;
		CountOfPaper(paper, x, y, half, count);
		CountOfPaper(paper, x, y + half, half, count);
		CountOfPaper(paper, x + half, y, half, count);
		CountOfPaper(paper, x + half, y + half, half, count);
	}

	return;
}

bool IsSamePaper(int paper[][MAX_NUM_SIZE], int x, int y, int length)
{
	int value = paper[y][x];
	for (int i = y; i < y + length; ++i)
	{
		for (int j = x; j < x + length; ++j)
		{
			if (paper[i][j] != value)
			{
				return false;
			}
		}
	}
	return true;
}