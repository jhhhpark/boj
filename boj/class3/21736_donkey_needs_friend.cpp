#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Pos {
	int x;
	int y;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Pos I;
	stack<Pos> st;
	vector<vector<char>> campus;
	vector<vector<bool>> isVisit;
	int N, M, cnt = 0;
	int xOffset[] = { -1, 0, 1, 0 };
	int yOffset[] = { 0, -1, 0, 1 };

	cin >> N >> M;
	campus.reserve(N);
	isVisit.reserve(N);
	for (int i = 0; i < N; i++) {
		campus.emplace_back(vector<char>(M));
		isVisit.emplace_back(vector<bool>(M, false));
		for (int j = 0; j < M; j++) {
			cin >> campus[i][j];
			if (campus[i][j] == 'I') {
				I.x = j;
				I.y = i;
			}
		}
	}


	st.push(I);
	isVisit[I.y][I.x] = true;
	while (st.empty() == false) {
		Pos curPos = st.top();
		st.pop();
		for (int i = 0; i < 4; i++) {
			Pos nextPos;
			nextPos.y = curPos.y + yOffset[i];
			nextPos.x = curPos.x + xOffset[i];
			if (nextPos.x < 0 || nextPos.x >= M || nextPos.y < 0 || nextPos.y >= N) continue;
			char nextChar = campus[nextPos.y][nextPos.x];
			if (isVisit[nextPos.y][nextPos.x] == false && nextChar != 'X') {
				isVisit[nextPos.y][nextPos.x] = true;
				if (nextChar == 'P') {
					cnt++;
				}
				st.push(curPos);
				st.push(nextPos);
				break;
			}
		}
	}

	if (cnt > 0) {
		cout << cnt << '\n';
	} else {
		cout << "TT" << '\n';
	}

	return 0;
}