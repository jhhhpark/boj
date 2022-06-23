#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE		101

int GetMoveCountOfMaze(int maze[][MAX_SIZE], int endX, int endY);

int problem_2178()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int mazes[MAX_SIZE][MAX_SIZE] = { 0, };
	int N = 0, M = 0, count = 0;
	char input[MAX_SIZE] = { 0, };
	cin >> N >> M;
	cin.ignore();
	for (int i = 1; i <= N; ++i)
	{
		cin.getline(input, MAX_SIZE);
		for (int j = 1; j <= M; ++j)
		{
			mazes[i][j] = input[j-1] - '0';
		}
	}
	count = GetMoveCountOfMaze(mazes, M, N);
	cout << count << '\n';

	return 0;
}

int GetMoveCountOfMaze(int mazes[][MAX_SIZE], int endX, int endY)
{
	int dir[2][4] = { { -1, 0, 1, 0 }, {0, 1, 0, -1} };
	bool passed[MAX_SIZE][MAX_SIZE] = { false, };
	queue<pair<int, int>> log;
	int beginX = 1, beginY = 1, count = 0;

	log.push(make_pair(beginX, beginY));
	passed[beginX][beginY] = true;
	++count;
	while (log.empty() == false)
	{
		int size = log.size();
		for (int i = 0; i < size; ++i)
		{
			int x = 0, y = 0;
			pair<int, int> curPos = log.front();
			log.pop();
			for (int j = 0; j < 4; ++j)
			{
				x = curPos.first + dir[0][j];
				y = curPos.second + dir[1][j];
				if (x == endX && y == endY)
				{
					return ++count;
				}
				else if (x <= 0 || y <= 0 || x > endX || y > endY)
				{
					continue;
				}
				else if (passed[y][x] == false && mazes[y][x] == 1)
				{
					log.push(make_pair(x, y));
					passed[y][x] = true;
				}
				else
				{
					/* Nothing */
				}
			}
		}
		++count;
	}

	return count;
}
