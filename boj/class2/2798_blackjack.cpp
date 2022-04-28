#include <iostream>

using namespace std;

int problem_2798()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	int m = 0;
	int sum = 0;
	int result = 0;
	cin >> n >> m;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = i + 1; j < n - 1; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= m)
				{
					result = result <= sum ? sum : result;
				}
			}
		}
	}
	cout << result << '\n';
	delete[] arr;
	return 0;
}