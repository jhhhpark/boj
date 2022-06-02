#include <iostream>

using namespace std;

#define MIN			0
#define MAX_RELATION			500000

int Abs(int n)
{
	return n < 0 ? ~n + 1 : n;
}

int CountOfInputNumber(int* bkNums, int N)
{
	if (N <= 0)
	{
		return bkNums[0] == 0 && N == 0 ? 1 : -1;
	}

	int cnt = 0;
	while (N > 0)
	{
		int btn = N % 10;
		for (int i = 0; i < 10; ++i)
		{
			if (bkNums[i] > 0 && btn == i)
			{
				return -1;
			}
		}
		N /= 10;
		++cnt;
	}
	return cnt;
}
int problem_1107()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int bkNums[10] = { 0, };
	int signs[2] = { -1, +1 };
	int num, cur = 100, cnt = 0;

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> num;
		++bkNums[num];
	}

	int offset = 0;
	while (N - offset >= MIN || N + offset <= MAX_RELATION)
	{
		for (int i = 0; i < 2; ++i)
		{
			cnt = CountOfInputNumber(bkNums, N + (signs[i] * offset));
			if (cnt != -1)
			{
				cnt += offset;
				break;
			}
		}
		if (cnt != -1) break;
		++offset;
	}

	int moveCnt = Abs(cur - N);
	if (cnt == -1 || moveCnt < cnt) 
		cnt = moveCnt;

	cout << cnt << '\n';

	return 0;
}