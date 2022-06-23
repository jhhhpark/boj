#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE		65

bool IsSameValue(bool matrix[][65], int x, int y, int len);
void QuadTree(bool matrix[][65], int x, int y, int len, string* result);

int problem_1992()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string result;
	result.reserve(MAX_SIZE * MAX_SIZE * 5);
	bool matrix[MAX_SIZE][MAX_SIZE] = { false, };
	int N = 0;
	char input[MAX_SIZE] = { 0, };
	cin >> N;
	cin.ignore();

	for (int i = 1; i <= N; ++i)
	{
		cin.getline(input, MAX_SIZE);
		for (int j = 1; j <= N; ++j)
		{
			matrix[i][j] = input[j - 1] - '0';
		}
	}

	QuadTree(matrix, 1, 1, N, &result);
	cout << result << '\n';
	return 0;
}

bool IsSameValue(bool matrix[][65], int x, int y, int len)
{
	bool value = matrix[y][x];
	for (int i = y; i < y + len; ++i)
	{
		for (int j = x; j < x + len; ++j)
		{
			if (matrix[i][j] != value)
			{
				return false;
			}
		}
	}
	return true;
}

void QuadTree(bool matrix[][65], int x, int y, int len, string* result)
{
	if (len == 1 || IsSameValue(matrix, x, y, len) == true)
	{
		int n = matrix[y][x] == true ? 1 : 0;
		result->append(to_string(n));
	}
	else
	{
		result->append("(");
		// todo quadtree
		int half = len / 2;
		QuadTree(matrix, x, y, half, result);
		QuadTree(matrix, x + half, y, half, result);
		QuadTree(matrix, x, y + half, half, result);
		QuadTree(matrix, x + half, y + half, half, result);
		result->append(")");
	}
	return;
}