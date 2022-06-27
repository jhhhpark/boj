#include <iostream>

using namespace std;

#define MAX_STAIR		300 + 1

int GetMaxScore(int* stairs, int N);
int GetMax(int n1, int n2);

int problem_2579()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int stairs[MAX_STAIR] = { 0, };
	int N = 0, score = 0;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> stairs[i];
	}

	score = GetMaxScore(stairs, N);
	cout << score << '\n';
	return 0;
}

int GetMaxScore(int* stairs, int N)
{
	int sum[MAX_STAIR] = { 0, };
	sum[1] = stairs[1];
	sum[2] = stairs[2] + stairs[1];
	sum[3] = GetMax(stairs[1], stairs[2]) + stairs[3];
	for (int i = 4; i <= N; ++i)
	{
		sum[i] = GetMax(stairs[i - 1] + sum[i - 3], sum[i - 2]) + stairs[i];
	}
	return sum[N];
}

int GetMax(int n1, int n2)
{
	return n1 > n2 ? n1 : n2;
}