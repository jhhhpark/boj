#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAP_SIZE		26

int countOfHouseGroup(int map[][MAP_SIZE], vector<int>& houseCounter, int N);
int countOfHouse(int map[][MAP_SIZE], bool houses[][MAP_SIZE], int N, int x, int y);

int problem_2667()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> houseCnt;
	int map[MAP_SIZE][MAP_SIZE] = { 0, };
	char input[MAP_SIZE] = { 0, };
	int N = 0, count = 0;
	cin >> N;
	cin.ignore();
	for (int i = 1; i <= N; ++i)
	{
		cin.getline(input, MAP_SIZE);
		for (int j = 1; j <= N; ++j)
		{
			map[i][j] = input[j-1] - '0';
		}
	}

	count = countOfHouseGroup(map, houseCnt, N);
	cout << count << '\n';
	for (size_t i = 0; i < houseCnt.size(); ++i)
	{
		cout << houseCnt[i] << '\n';
	}
	return 0;
}

int countOfHouseGroup(int map[][MAP_SIZE], vector<int>& houseCounter, int N)
{
	bool houses[MAP_SIZE][MAP_SIZE] = { false, };
	int houseGroups = 0;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (houses[i][j] == false && map[i][j] == 1)
			{
				int houseCnt = countOfHouse(map, houses, N, j, i);
				houseCounter.push_back(houseCnt);
				++houseGroups;
			}
		}
	}
	sort(houseCounter.begin(), houseCounter.end());

	return houseGroups;
}

int countOfHouse(int map[][MAP_SIZE], bool houses[][MAP_SIZE], int N, int x, int y)
{
	int direct[2][4] = { {0, 1, 0, -1}, {-1, 0, 1, 0} };
	int houseCnt = 0;
	queue<pair<int, int>> q;

	q.push(make_pair(y, x));
	houses[y][x] = true;
	++houseCnt;

	while (q.empty() == false)
	{
		pair<int, int> pos = q.front();
		int nextX = 0, nextY = 0;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			nextY = pos.first + direct[0][i];
			nextX = pos.second + direct[1][i];
			if (houses[nextY][nextX] == false && map[nextY][nextX] == 1)
			{
				houses[nextY][nextX] = true;
				q.push(make_pair(nextY, nextX));
				++houseCnt;
			}
		}

	}

	return houseCnt;
}