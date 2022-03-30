#include <iostream>

using namespace std;

bool isPrimeNumber(int n)
{
	if (n <= 1 || (n & 1) == 0)
	{
		return n == 2;
	}

	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int inputNum = 0;
	int count = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> inputNum;
		if (isPrimeNumber(inputNum) == true)
		{
			++count;
		}
	}

	cout << count << '\n';
	return 0;
}