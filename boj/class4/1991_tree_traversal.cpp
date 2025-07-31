#include <iostream>

using namespace std;

int r1 = 0, r2 = 0, r3 = 0;
int res[3][26];
int binaryTree[26][2];

void TreeOrder(int root) {
	res[0][r1++] = root;
	if (binaryTree[root][0] >= 0) TreeOrder(binaryTree[root][0]);
	res[1][r2++] = root;
	if (binaryTree[root][1] >= 0) TreeOrder(binaryTree[root][1]);
	res[2][r3++] = root;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char root;
		cin >> root;
		for (int j = 0; j < 2; j++) {
			char node;
			cin >> node;
			if (node == '.') {
				binaryTree[root - 'A'][j] = -1;
			} else {
				binaryTree[root - 'A'][j] = node - 'A';
			}
		}
	}

	TreeOrder(0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cout << (char)(res[i][j] + 'A');
		}
		cout << '\n';
	}
	return 0;
}