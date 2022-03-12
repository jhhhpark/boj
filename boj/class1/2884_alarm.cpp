#include <iostream>

using namespace std;

int problem_2884()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int nHour = 0;
	int nMin = 0;
	cin >> nHour >> nMin;
	if (nMin < 45)
	{
		nHour = nHour == 0 ? 23 : nHour - 1;
	}

	if (nMin < 45)
	{
		nMin += 15;
	}
	else
	{
		nMin -= 45;
	}

	cout << nHour << " " << nMin << "\n";
	return 0;
}