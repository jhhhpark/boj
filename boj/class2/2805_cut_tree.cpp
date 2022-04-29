#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ASC(int n, int m)
{
	return n < m;
}

long long getSumOfCutTrees(vector<int>& trees, int cut)
{
	long long sum = 0;
	for (size_t i = 0; i < trees.size(); ++i)
	{
		sum += (long long)cut >= (long long)trees[i] ? 0LL : (long long)trees[i] - (long long)cut;
	}
	return sum;
}

long long getCutOfTreeMaxLength(vector<int>& trees, int endLen, int wantLen)
{
	int startLen = 1;
	int curLen = 0;
	long long sumLen = 0LL;

	while (startLen < endLen)
	{
		curLen = startLen + (endLen - startLen) / 2;
		sumLen = getSumOfCutTrees(trees, curLen);
		if (sumLen >= (long long)wantLen)
		{
			startLen = curLen + 1;
		}
		else
		{
			endLen = curLen;
		}
	}

	return startLen - 1;
}

int problem_2805()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> trees;
	int tree = 0;
	int cutLen = 0;
	int endLen = 0;

	int N = 0;
	int M = 0;
	cin >> N >> M;

	trees.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> tree;
		endLen = endLen < tree ? tree : endLen;
		trees.push_back(tree);
	}
	sort(trees.begin(), trees.end(), ASC);

	cutLen = getCutOfTreeMaxLength(trees, endLen, M);
	cout << cutLen << '\n';



	return 0;
}