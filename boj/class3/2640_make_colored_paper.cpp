#include <iostream>

using namespace std;

constexpr int MAX_SIZE = 128;
bool paper[MAX_SIZE][MAX_SIZE];
int colorCount[2] = { 0, };

// 0: white, 1: blue
void Distribute(int x, int y, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (paper[y][x] != paper[y + i][x + j]) {
				size /= 2;
				Distribute(x, y, size);
				Distribute(x + size, y, size);
				Distribute(x, y + size, size);
				Distribute(x + size, y + size, size);
				return;
			}
		}
	}
	colorCount[paper[y][x]]++;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
	
	Distribute(0, 0, N);
	cout << colorCount[0] << '\n';
	cout << colorCount[1] << '\n';

	return 0;
}