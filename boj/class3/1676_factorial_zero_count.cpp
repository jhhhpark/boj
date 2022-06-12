#include <iostream>

using namespace std;

int countOfDivideNum(int N, int num)
{
	int count = 0;
	while (N % num == 0) 
	{ 
		N /= num;
		++count;
	}
	return count;
}

int problem_1676()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int div2 = 0;
	int div5 = 0;
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		div2 += countOfDivideNum(i, 2);
		div5 += countOfDivideNum(i, 5);
	}
	cout << min(div2, div5) << '\n';

	return 0;
}