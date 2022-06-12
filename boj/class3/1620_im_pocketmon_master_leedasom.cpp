#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isNumber(const char* str)
{
	int dist = str[0] - '0';
	return 0 <= dist && dist <= 9;
}

string strArr[100001];
int problem_1620()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	string name;
	unordered_map<string, int> books;
	for (int i = 1; i <= N; ++i)
	{
		cin >> name;

		books.insert(make_pair(name, i));
		strArr[i] = name;
	}

	for (int i = 0; i < M; ++i)
	{
		string input;
		cin >> input;
		if (isNumber(input.c_str()) == true)
		{
			int num = stoi(input);
			cout << strArr[num] << '\n';
		}
		else
		{
			cout << books[input] << '\n';
		}
	}

	return 0;
}