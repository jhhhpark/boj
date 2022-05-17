#include <iostream>

using namespace std;

#define MAX_HEIGHT		256

int problem_18111()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int blocks[MAX_HEIGHT + 1] = { 0, };
	int time = 2 * 256 * 500 * 500 + 1, height = 0;
	int N, M, B, T;
	cin >> N >> M >> B;
	for (int i = 0; i < N * M; ++i)
	{
		cin >> T;
		blocks[T]++;
	}

	for (int h = 0; h <= MAX_HEIGHT; ++h)
	{
		int needBlock = 0, gainBlock = 0;
		for (int i = 0; i < h; ++i) needBlock += (h - i) * blocks[i];
		for (int i = MAX_HEIGHT; i > h; --i) gainBlock += (i - h) * blocks[i];

		T = needBlock + gainBlock * 2;
		if (B - needBlock + gainBlock < 0) break;
		if (time < T) break;
		time = T;
		height = h;
	}

	cout << time << ' ' << height << '\n';
	return 0;
}