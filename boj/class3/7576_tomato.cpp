#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define RIPE				1
#define NOT_RIPE			0
#define NOTHING				-1

struct Point 
{
	int m;
	int n;
};

void RipeTomato(vector<vector<int>>& tomatoBox, queue<Point>& ripeQ, int M, int N)
{
	Point pt = ripeQ.front();

	for (int i = 0; i < 2; ++i)
	{
		for (int j = -1; j < 2; j += 2)
		{
			int m = pt.m + (i == 0 ? j : 0);
			int n = pt.n + (i == 1 ? j : 0);
			if (m < 0 || n < 0 || m >= M || n >= N)
			{
				continue;
			}
			else
			{
				if (tomatoBox[n][m] == NOT_RIPE)
				{
					tomatoBox[n][m] = RIPE;
					ripeQ.push(Point{ m, n });
				}
			}
		}
	}

	return;
}

bool IsRipeAll(const vector<vector<int>>& tomatoBox, int M, int N) 
{
	for (int n = 0; n < N; ++n)
	{
		for (int m = 0; m < M; ++m)
		{
			if (tomatoBox[n][m] == NOT_RIPE)
			{
				return false;
			}
		}
	}
	return true;
}

int Progress(vector<vector<int>>& tomatoBox, int M, int N)
{
	int days = 0;
	queue<Point>ripeQ;

	for (int n = 0; n < N; ++n)
	{
		for (int m = 0; m < M; ++m)
		{
			if (tomatoBox[n][m] == RIPE)
			{
				ripeQ.push(Point{ m, n });
			}
		}
	}

	while(true)
	{
		int len = ripeQ.size();
		for (int i = 0; i < len; ++i)
		{
			RipeTomato(tomatoBox, ripeQ, M, N);
			ripeQ.pop();
		}
		
		if (ripeQ.empty() == true)
		{
			break;
		}
		else
		{
			++days;
		}
	}

	if (IsRipeAll(tomatoBox, M, N) == false)
	{
		days = -1;
	}

	return days;
}


int problem_7576()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int input, M, N, days;
	cin >> M >> N;
	vector<vector<int>> tomatoBox(N, vector<int>());

	for (int i = 0; i < N; ++i)
	{
		tomatoBox[i].reserve(M);
		for (int j = 0; j < M; ++j)
		{
			cin >> input;
			tomatoBox[i].push_back(input);
		}
	}
	
	days = Progress(tomatoBox, M, N);
	cout << days << '\n';

	return 0;
}