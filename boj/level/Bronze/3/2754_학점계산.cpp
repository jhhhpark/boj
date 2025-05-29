#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string rank;
	unordered_map<string, string> credits;
	credits.emplace(make_pair("A+", "4.3"));
	credits.emplace(make_pair("A0", "4.0"));
	credits.emplace(make_pair("A-", "3.7"));
	credits.emplace(make_pair("B+", "3.3"));
	credits.emplace(make_pair("B0", "3.0"));
	credits.emplace(make_pair("B-", "2.7"));
	credits.emplace(make_pair("C+", "2.3"));
	credits.emplace(make_pair("C0", "2.0"));
	credits.emplace(make_pair("C-", "1.7"));
	credits.emplace(make_pair("D+", "1.3"));
	credits.emplace(make_pair("D0", "1.0"));
	credits.emplace(make_pair("D-", "0.7"));
	credits.emplace(make_pair("F", "0.0"));

	cin >> rank;
	cout << credits[rank];

	return 0;
}