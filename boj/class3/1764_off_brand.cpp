#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int problem_1764()
{
	vector<string> names, result;
	int N = 0, M = 0;
	string name;
	cin >> N >> M;
	names.resize(N);
	for (int i = 0; i < N; ++i) 
	{
		cin >> names[i];
	}
	sort(names.begin(), names.end());
	for (int i = 0; i < M; ++i) 
	{
		cin >> name;
		if (binary_search(names.begin(), names.end(), name) == true)
		{
			result.push_back(name);
		}
	}
	sort(result.begin(), result.end());
	int count = result.size();
	cout << count << '\n';
	for (int i = 0; i < count; ++i)
	{
		cout << result[i] << '\n';
	}
	return 0;
}