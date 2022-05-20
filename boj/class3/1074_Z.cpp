#include <iostream>

using namespace std;

#define ELEM_SIZE			2
int N, r, c;

void Z(int length, int row, int column, int* count);
int Pow(int n, int length);

int problem_1074()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count = -1;
	cin >> N >> r >> c;
	Z(Pow(ELEM_SIZE, N), 0, 0, &count);
	cout << count << '\n';
	return 0;
}

int Pow(int n, int length)
{
	int result = 1;
	for (int i = 0; i < length; ++i)
	{
		result *= n;
	}
	return result;
}

void Z(int size, int row, int column, int* count)
{
	if (size <= ELEM_SIZE)
	{
		for (int i = row; i < row + ELEM_SIZE; ++i)
		{
			for (int j = column; j < column + ELEM_SIZE; ++j)
			{
				*count += 1;
				if (i == r && j == c) return;
			}
		}
	}
	else
	{
		bool isFound = false;
		int rowOffset = 0;
		int colOffset = 0;
		int halfSize = size / 2;
		if (r >= row + halfSize)
		{
			*count += size * halfSize;
			++rowOffset;
		}
		if (c >= column + halfSize)
		{
			*count += halfSize * halfSize;
			++colOffset;
		}
		row += rowOffset * halfSize;
		column += colOffset * halfSize;
		Z(size / 2, row, column, count);
	}
	return;
}