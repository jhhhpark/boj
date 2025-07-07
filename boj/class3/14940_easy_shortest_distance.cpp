#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
	int x;
	int y;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int m;
	Pos dst;
	queue<Pos> q;
	int xOffset[] = { -1, 0, 1, 0 };
	int yOffset[] = { 0, -1, 0, 1 };
	vector<vector<int>> map;
	vector<vector<int>> result;

	cin >> n >> m;
	map.reserve(n);
	result.reserve(n);
	for (int i = 0; i < n; i++) {
		map.emplace_back(vector<int>(m));
		result.emplace_back(vector<int>(m, -1));
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) result[i][j] = 0;
			if (map[i][j] == 2) {
				dst.y = i;
				dst.x = j;
			}
		}
	}

	q.push(dst);
	result[dst.y][dst.x] = 0;
	while (q.empty() == false) {
		Pos cur = q.front();
		q.pop();
		for (int j = 0; j < 4; j++) {
			Pos next;
			next.x = cur.x + xOffset[j];
			next.y = cur.y + yOffset[j];
			if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) continue;
			if (result[next.y][next.x] != -1) continue;
			q.push(next);
			result[next.y][next.x] = result[cur.y][cur.x] + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}