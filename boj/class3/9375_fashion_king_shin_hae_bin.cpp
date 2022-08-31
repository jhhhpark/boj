#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

#define MAX_CATEGORY		30

int problem_9375()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<string, int> map;
	vector<int> vec;
	vec.reserve(MAX_CATEGORY);
	int T, N;
	string name, category, delim = " ";
	int pos = 0, result = 1;

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		cin.ignore();
		for (int j = 0; j < N; ++j)
		{
			cin >> name >> category; // name not using
			if (map.find(category) == map.end())
			{
				map.insert({ category, 1 });
			}
			else
			{
				++map[category];
			}
		}

		unordered_map<string, int>::iterator iter = map.begin();
		while (iter != map.end()) 
		{
			result *= (iter->second + 1);
			++iter;
		}
		cout << result - 1 << '\n';

		map.clear();
		result = 1;
	}

	return 0;
}