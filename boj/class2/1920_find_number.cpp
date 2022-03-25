#include <iostream>
#include <unordered_map>
using namespace std;

#define EXIST		1
int problem_1920()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map<int, int> numberMap;
	unordered_map<int, int>::iterator iter;
	int input = 0;
	
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		numberMap.insert(std::make_pair(input, EXIST));
	}

	int M = 0;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> input;
		iter = numberMap.find(input);
		cout << (iter != numberMap.end() ? 1 : 0) << '\n';
	}

	return 0;
}