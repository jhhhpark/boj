#include <iostream>
using namespace std;


int compare(void const* n1, void const* n2)
{
	int v1 = *(int*)n1;
	int v2 = *(int*)n2;
	return v1 > v2;
}

int problem_2609()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << '\n';
	}
	delete[] arr;
	return 0;
}