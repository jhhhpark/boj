#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int mL = 0;
	int A[1001];
	int C[1001] = { 0, };

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		C[A[i]] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i] && C[A[i]] <= C[A[j]]) {
				C[A[i]] = C[A[j]] + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (mL < C[A[i]]) {
			mL = C[A[i]];
		}
	}

	cout << mL;
	return 0;
}