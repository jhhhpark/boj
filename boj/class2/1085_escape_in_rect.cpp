#include <iostream>

using namespace std;

int Abs(int n)
{
	return n < 0 ? ~n + 1 : n;
}

int problem_1085()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int nX = 0;
	int nY = 0;
	int nW = 0;
	int nH = 0;
	int aMin[2] = { 0, };
	int nDist = 499;

	cin >> nX >> nY >> nW >> nH;
	
	aMin[0] = Abs(nX - nW);
	aMin[1] = Abs(nY - nH);
	
	aMin[0] = aMin[0] < nX ? aMin[0] : nX;
	aMin[1] = aMin[1] < nY ? aMin[1] : nY;

	cout << (aMin[0] < aMin[1] ? aMin[0] : aMin[1]) << '\n';
	return 0;
}