#include <iostream>

using namespace std;

int problem_9498()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int aScore[6] = { 101, 90, 80, 70, 60, 0 };
	char aRank[6] = { 'A', 'B', 'C', 'D', 'F', 'F'};
	int nScore = 0;

	cin >> nScore;

	for (int i = 0; i < 5; ++i)
	{
		if (nScore < aScore[i] && nScore >= aScore[i + 1])
		{
			cout << aRank[i] << "\n";
			break;
		}
	}

	return 0;
}