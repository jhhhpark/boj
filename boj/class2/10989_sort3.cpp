#include <iostream>

using namespace std;

int compare (int n, int m) {
	return n < m;
}
int problem_10989()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[10001] = { 0, };

	int N = 0;
	cin >> N;
	
	int num = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		++arr[num];
	}

	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
	{
		while (arr[i] != 0)
		{
			cout << i << '\n';
			--arr[i];
		}
	}

	return 0;
}