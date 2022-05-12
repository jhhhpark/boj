#include <cstdio>
#include <algorithm>

using namespace std;

char buf[1 << 15];
int idx = 1 << 15;

inline char read()
{
	if (idx == 1 << 15)
	{
		fread(buf, 1, 1 << 15, stdin);
		idx = 0;
	}
	return buf[idx++];
}

inline int readInt()
{
	int sum = 0;
	int flag = 1;
	char now = read();
	
	while (now == ' ' || now == '\n') now = read();
	if (now == '-')
	{
		flag = -1;
		now = read();
	}
	while (now >= '0' && now <= '9')
	{
		sum = sum * 10 + now - 48;
		now = read();
	}
	return sum * flag;
}

int compare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
}
int problem_11651()
{
	int n;
	n = readInt();
	pair<int, int> p[100000];

	for (int i = 0; i < n; ++i)
	{
		p[i].first = readInt();
		p[i].second = readInt();
	}
	sort(p, p + n, compare);
	for (int i = 0; i < n; ++i)
	{
		printf("%d %d\n", p[i].first, p[i].second);
	}

	return 0;
}