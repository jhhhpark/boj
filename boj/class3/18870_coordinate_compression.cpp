#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int problem_18870()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> v, back;
	int N, input;
	
	cin >> N;

	v.reserve(1'000'000);
	back.reserve(1'000'000);

	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		v.push_back(input);
		back.push_back(input);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < N; ++i)
	{
		cout << lower_bound(v.begin(), v.end(), back[i]) - v.begin() << '\n';
	}

	return 0;
}