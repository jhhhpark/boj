#include <cstdlib>
#include <iostream>

using namespace std;

int ASC(void const* d1, void const* d2)
{
	int* n = (int*)d1;
	int* m = (int*)d2;
	return *n <= *m ? -1 : 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int* arr;
	int i, n;
	int del, start, end;
	int res = 0;
	
	cin >> n;
	if (n != 0)
	{
		arr = new int[n];
		del = (n * 15 + 50) / 100;
		start = del;
		end = n - del;
		for (i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		qsort(arr, n, sizeof(int), ASC);
		for (i = start; i < end; ++i)
		{
			res += arr[i];
		}

		n -= (del * 2);
		res = ((res * 100) / n + 50) / 100;
		delete[] arr;
	}
	
	cout << res;
	return 0;
}