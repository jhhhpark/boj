#include <iostream>

using namespace std;

#define SHIRT_SIZE	6

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[SHIRT_SIZE];
	int n, t, p, bundle = 0;

	cin >> n;
	for (int i = 0; i < SHIRT_SIZE; i++) {
		cin >> arr[i];
	}
	cin >> t >> p;

	for (int i = 0; i < SHIRT_SIZE; i++) {
		if (arr[i] > 0) bundle += (arr[i] - 1) / t + 1;
	}
	cout << bundle << '\n';
	cout << n / p << ' ' << (n % p);

	return 0;
}