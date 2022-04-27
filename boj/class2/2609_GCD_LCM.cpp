#include <iostream>
using namespace std;

int problem_2609()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n1 = 0;
	int n2 = 0;
	int GCD = 0;
	int LCM = 0;
	cin >> n1 >> n2;

	int t1 = n1;
	int t2 = n2;
	while (t1 % t2 != 0)
	{
		int mod = t1 % t2;
		t1 = t2;
		t2 = mod;
	}
	GCD = t2;
	LCM = n1 * n2 / t2;

	cout << GCD << '\n' << LCM << '\n';

	return 0;
}