#include <iostream>
using namespace std;

int problem_10809()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int aAlpha[26] = { 0, };
	char aWord[101] = { 0, };
	cin >> aWord;

	int pos = 0;
	while (aWord[pos] != '\0')
	{
		int ndx = aWord[pos] - 'a';
		if (aAlpha[ndx] == 0)
		{
			aAlpha[ndx] = pos + 1;
		}
		++pos;
	}

	for (int i = 0; i < sizeof(aAlpha) / sizeof(int); ++i)
	{
		cout << aAlpha[i] - 1 << " ";
	}
	 
	return 0;
}