#include <iostream>
#include <stack>

#define MAX_POS			50
#define MIN_POS			0

using namespace std;

int countOfEarthworms(int cabages[][MAX_POS + 1], int N, int M, int K);
void eatCabage(int cabages[][MAX_POS + 1], bool check[][MAX_POS + 1], int x, int y, int* remain);

int problem_1012()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int eqrthwarmCount = 0;
	int T, N, M, K;
	int X, Y;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int cabages[MAX_POS + 1][MAX_POS + 1] = { 0, };
		cin >> M >> N >> K;
		for (int j = 0; j < K; ++j)
		{
			cin >> X >> Y;
			cabages[Y][X] = 1;
		}
		eqrthwarmCount = countOfEarthworms(cabages, M, N, K);
		cout << eqrthwarmCount << '\n';
	}

	return 0;
}

int countOfEarthworms(int cabages[][MAX_POS + 1], int column, int row, int remainCabages)
{
	bool check[51][51] = { false, };
	int earthwarmCount = 0;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			if (check[i][j] == false && cabages[i][j] == 1)
			{
				++earthwarmCount;
				eatCabage(cabages, check, j, i, &remainCabages);
			}
		}
		if (remainCabages <= 0) break;
	}
	return earthwarmCount;
}

void eatCabage(int cabages[][MAX_POS + 1], bool check[][MAX_POS + 1], int x, int y, int* remainCabages)
{
	stack<pair<int, int>> farm;
	int offset[4][2] = { {-1, 0}, {1, 0}, {0,-1}, {0, 1} };

	farm.push(pair<int, int>(x, y));
	*remainCabages -= 1;
	check[y][x] = true;
	while (!farm.empty())
	{
		pair<int, int> cur = farm.top();
		farm.pop();
		for (int i = 0; i < sizeof(offset) / sizeof(offset[0]); ++i)
		{
			int nextX = cur.first + offset[i][0];
			int nextY = cur.second + offset[i][1];

			if (nextX < MIN_POS || nextY < MIN_POS
				|| nextX > MAX_POS || nextY > MAX_POS
				|| cabages[nextY][nextX] == 0
				|| check[nextY][nextX] == true)
			{
				continue;
			}
			else
			{
				farm.push(cur);
				farm.push(pair<int, int>(nextX, nextY));
				*remainCabages -= 1;
				check[nextY][nextX] = true;
				break;
			}
		}
	}
	return;
}