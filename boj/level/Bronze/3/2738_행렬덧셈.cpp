#include <iostream>

using namespace std;

int matrix1[100][100];
int matrix2[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix1[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix2[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix1[i][j] += matrix2[i][j];
			cout << matrix1[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}