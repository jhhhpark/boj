#include <iostream>

using namespace std;

int problem_10250()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 0;
	cin >> T;

	int H = 0;
	int W = 0;
	int N = 0;
	for (int i = 0; i < T; ++i)
	{
		cin >> H >> W >> N;

		int floor = (N % H == 0 ? H : N % H) * 100;
		int number = (N % H == 0) ? N / H : N / H + 1;

		cout << floor + number << '\n';
	}
	return 0;
}