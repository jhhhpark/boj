#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ULL;

ULL getHash(char c, int r, int n, int M)
{
	ULL ri = 1;
	for (int i = 0; i < n; ++i)
	{
		ri = (ri * (ULL)r) % (ULL)M;
	}
	return ((ULL)(c - 'a' + 1) * ri);
}

int Problem_15829()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string word;
	ULL result = 0;
	int r = 31;
	int M = 1234567891;

	int L = 0;
	cin >> L;
	cin.ignore();
	getline(cin, word);
	for (int i = 0; i < L; ++i)
	{
		result += getHash(word[i], r, i, M);
		result %= (ULL)M;
	}

	cout << (int)result << '\n';
	return 0;
}