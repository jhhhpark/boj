#include <iostream>

using namespace std;

int problem_4153()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	unsigned int max;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		else
		{
			max = a > b ? a : b;
			max = max > c ? max : c;
			if (a * a + b * b + c * c == 2 * max * max)
			{
				puts("right");
			}
			else
			{
				puts("wrong");
			}
		}
	}
	return 0;
}