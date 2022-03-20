#include <iostream>
#include <set>
#include <string>
using namespace std;

struct compare {
	bool operator() (const string& w1, const string& w2) const
	{
		if (w1.size() == w2.size())
		{
			return w1 < w2;
		}
		else
			return w1.size() < w2.size();
	}
};

int problem_1181()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	string word = "";
	set<string, compare> words;

	// input
	for (int i = 0; i < n; ++i)
	{
		cin >> word;
		words.insert(word);
	}

	set<string>::iterator iter;
	set<string>::iterator iterEnd = words.cend();
	for (iter = words.cbegin(); iter != iterEnd; ++iter)
	{
		cout << *iter << '\n';
	}

	return 0;
}