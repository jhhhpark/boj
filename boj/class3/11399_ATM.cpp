#include <iostream>

using namespace std;

int Compare(void const* n1, void const* n2)
{
	return *(int*)n1 > *(int*)n2;
}

int problem_11399()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int P[1000] = { 0, };
	int N, sum = 0;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> P[i];
	}
	qsort(P, N, sizeof(int), Compare);

	for (int i = 0; i < N; ++i)
	{
		sum += P[i] * (N - i);
	}
	cout << sum << '\n';

	return 0;
}