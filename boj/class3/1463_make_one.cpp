#include <iostream>
using namespace std;

#define MIN(a, b) (a < b ? a : b)

int F(int N)
{
	if (N <= 1) return 0;
	int s1 = F(N / 3) + N % 3 + 1;
	int s2 = F(N / 2) + N % 2 + 1;
	return MIN(s1, s2);
}

int problem_1463()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, min = 0;
	cin >> N;

	min = F(N);
	cout << min << '\n';
	return 0;
}

