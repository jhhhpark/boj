#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define MAX_SIZE			100

bool IsValidate(char ch, char picture, bool isNormal)
{
	if (isNormal == true || picture == 'B')
	{
		return ch == picture;
	}
	else
	{
		return ch == 'R' || ch == 'G';
	}
}

void CheckBoard(
	int N,
	string board[],
	bool pass[][MAX_SIZE],
	bool isNormal,
	int x, int y
) {
	int offX[] = { -1, 0, 1, 0 };
	int offY[] = { 0, -1, 0, 1 };

	stack<pair<int, int>> st;

	char picture = board[y][x];
	bool isPush = false;

	st.emplace(x, y);
	while (!st.empty())
	{
		pair<int, int> node = st.top();

		int curX = node.first;
		int curY = node.second;

		pass[curY][curX] = true;

		for (int i = 0; i < 4; ++i)
		{
			int toX = curX + offX[i];
			int toY = curY + offY[i];
			if (toX < 0 || toY < 0 || toX >= N || toY >= N || pass[toY][toX] == true) 
			{
				continue;
			}
			else
			{
				if (IsValidate(board[toY][toX], picture, isNormal) == true)
				{
					isPush = true;
					st.emplace(toX, toY);
					break;
				}
			}
		}

		if (isPush == false)
		{
			st.pop();
		}
		else
		{
			isPush = false;
		}
	}

	return;
}

int Progress(int N, string board[], bool isNormal)
{
	int result = 0;
	bool pass[MAX_SIZE][MAX_SIZE] = { false, };

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (pass[i][j] == true)
			{
				continue;
			}
			else
			{
				++result;
				CheckBoard(N, board, pass, isNormal, j, i);
			}
		}
	}

	return result;
}

int problem_10026()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string board[MAX_SIZE];
	int N;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; ++i)
	{
		getline(cin, board[i]);
	}

	int r1 = Progress(N, board, true);
	int r2 = Progress(N, board, false);

	cout << r1 << ' ' << r2 << '\n';
	return 0;
}