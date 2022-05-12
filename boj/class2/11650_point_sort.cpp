#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Point {
	int x;
	int y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
}POINT, *PPOINT;

int compare(POINT p1, POINT p2)
{
	return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
}

int problem_11650()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<POINT> v;
	v.reserve(100000);
	
	int N = 0;
	int x, y;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		POINT point(x, y);
		v.push_back(point);
	}
	sort(begin(v), end(v), compare);
	for (int i = 0; i < N; ++i)
	{
		cout << v[i].x << ' ' << v[i].y << '\n';
	}

	return 0;
}