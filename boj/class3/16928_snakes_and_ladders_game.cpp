#include <iostream>

using namespace std;

int front = 0;
int back = 0;
int queue[101];
int visited[101] = { 0, };
int moveCount[101] = { 0, };
int ladders[101] = { 0, };
int snakes[101] = { 0, };

void BFS(int st) {
	queue[front++] = st;
	visited[st] = 1;
	moveCount[st] = 0;

	while (front != back) {
		int pop = queue[back++];
		for (int i = 1; i <= 6; i++) {
			int next = pop + i;
			if (next > 100) continue;
			if (visited[next] == 0) {
				if (ladders[next] != 0) {
					next = ladders[next];
				} else if (snakes[next] != 0) {
					next = snakes[next];
				}

				if (visited[next] == 0) {
					queue[front++] = next;
					visited[next] = 1;
					moveCount[next] = moveCount[pop] + 1;
				}
			}
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int st, dst, n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> st >> dst;
		ladders[st] = dst;
	}

	for (int j = 0; j < m; j++) {
		cin >> st >> dst;
		snakes[st] = dst;
	}

	BFS(1);

	cout << moveCount[100] << '\n';
	return 0;
}