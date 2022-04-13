#include <iostream>

using namespace std;

int countOfModifyBlock(char aInputBoard[][51], int x, int y, char aBlackBoard[][8], char aWhiteBoard[][8])
{
	int nWCnt = 0;
	int nBCnt = 0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			nBCnt += aInputBoard[y + i][x + j] - aBlackBoard[i][j] == 0 ? 0 : 1;
			nWCnt += aInputBoard[y + i][x + j] - aWhiteBoard[i][j] == 0 ? 0 : 1;
		}
	}

	return nBCnt < nWCnt ? nBCnt : nWCnt;
}

int Toggle(int n)
{
	return n < 0 ? ~n + 1 : n;
}
int problem_1018()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// setup
	char aBlock[2] = { 'B', 'W' };
	char aBlackBoard[8][8] = { 0, };
	char aWhiteBoard[8][8] = { 0, };
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			int nbx = Toggle(i % 2 - j % 2);
			int nwx = Toggle(1 - i % 2 - j % 2);
			aBlackBoard[i][j] = aBlock[nbx];
			aWhiteBoard[i][j] = aBlock[nwx];
		}
	}

	// input
	char aInputBoard[51][51] = { 0, };
	int nWidth = 0;
	int nHeight = 0;
	int nCnt = 32;
	cin >> nHeight >> nWidth;
	
	for (int i = 0; i < nHeight; ++i)
	{
		cin >> aInputBoard[i];
	}

	// calc
	for (int i = 0; i <= nHeight - 8; ++i)
	{
		for (int j = 0; j <= nWidth - 8; ++j)
		{
			int nTempCnt = countOfModifyBlock(aInputBoard, j, i, aBlackBoard, aWhiteBoard);
			nCnt = nTempCnt < nCnt ? nTempCnt : nCnt;
		}
	}

	// output
	cout << nCnt << "\n";
	return 0;
}