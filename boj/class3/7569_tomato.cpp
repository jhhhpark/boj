#include <iostream>
#include <queue>

using namespace std;

#define RIPE			1
#define NOT_RIPE		0
#define NOTHING		-1

int tomatoBox[101][101][101] = { 0, };
int M, N, H;

struct Point3 {
	int m;
	int n;
	int h;
};

bool IsNotRipeTomato() {
	for (int h = 1; h <= H; ++h)
	{
		for (int n = 1; n <= N; ++n)
		{
			for (int m = 1; m <= M; ++m)
			{
				if (tomatoBox[h][n][m] == NOT_RIPE)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool IsBoundOfBox(int m, int n, int h)
{
	return h >= 1 && n >= 1 && m >= 1 && h <= H && n <= N && m <= M;
}

void ChangeTomato(queue<Point3>& tomatoQ, const Point3& _pt)
{
	int h, n, m;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = -1; j < 2; j+=2)
		{
			h = i == 2 ? _pt.h + j : _pt.h;
			n = i == 1 ? _pt.n + j : _pt.n;
			m = i == 0 ? _pt.m + j : _pt.m;
			if (IsBoundOfBox(m, n, h) == true && tomatoBox[h][n][m] == NOT_RIPE)
			{
				tomatoBox[h][n][m] = RIPE;
				tomatoQ.push(Point3{ m, n, h });
			}
		}
	}
	return;
}

int CountOfDaysForRipeTomato(queue<Point3>& tomatoQ) {
	int days = 0;

	while (true)
	{
		int len = tomatoQ.size();
		for (int i = 0; i < len; ++i)
		{
			Point3 tomatoInfo = tomatoQ.front();
			ChangeTomato(tomatoQ, tomatoInfo);
			tomatoQ.pop();
		}

		if (tomatoQ.empty() == true)
		{
			break;
		}
		else
		{
			++days;
		}
	}

	return IsNotRipeTomato() == true ? -1 : days;
}

int problem_7569()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue<Point3> tomatoQ;
	int days;

	cin >> M >> N >> H;
	for (int h = 1; h <= H; ++h)
	{
		for (int n = 1; n <= N; ++n)
		{
			for (int m = 1; m <= M; ++m)
			{
				cin >> tomatoBox[h][n][m];
				if (tomatoBox[h][n][m] == RIPE)
				{
					tomatoQ.push(Point3{ m, n, h });
				}
			}
		}
	}

	days = CountOfDaysForRipeTomato(tomatoQ);
	cout << days << '\n';

	return 0;
}