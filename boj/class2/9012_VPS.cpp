#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int problem_9012()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	stack<char> s;
	char buffer[51] = { 0, };

	int T = 0;
	cin >> T;
	cin.ignore();

	for (int i = 0; i < T; ++i)
	{
		while (!s.empty()) { s.pop(); }
		memset(buffer, 0, sizeof(buffer));

		cin.getline(buffer, sizeof(buffer));

		int j = 0;
		bool bVPS = true;
		while (buffer[j] != '\0')
		{
			if (buffer[j] == '(')
			{
				s.push(buffer[i]);
			}
			else if (buffer[j] == ')')
			{
				if (s.empty() == true)
				{
					bVPS = false;
					break;
				}
				else
				{
					s.pop();
				}
			}
			++j;
		}
		if (s.empty() == false) bVPS = false;
		cout << (bVPS == true ? "YES" : "NO") << '\n';
	}
	
	return 0;
}