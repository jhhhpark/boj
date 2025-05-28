#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	time_t timer = time(NULL);
	struct tm* now = localtime(&timer);

	int year = now->tm_year + 1900;
	int month = now->tm_mon + 1;
	int date = now->tm_mday;
	printf("%04d-%02d-%02d", year, month, date);
	return 0;
}