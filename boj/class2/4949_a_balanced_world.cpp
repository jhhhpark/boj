#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define NO			0
#define YES			1
bool isCheckPair(char c1, char c2)
{
	if (c1 == '(' && c2 == ')') return true;
	if (c1 == '[' && c2 == ']') return true;
	return false;
}
int problem_4949()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	stack<char> st;
	const char* result[2] = { "no", "yes"};
	string buffer;
	while (true)
	{
		while (!st.empty()) { st.pop(); }
		getline(cin, buffer);
		if (buffer.length() == 1 && buffer[0] == '.') break;
		int flag = YES;
		for(int i = 0 ; i < buffer.length(); ++i)
		{
			if (buffer[i] == '(' || buffer[i] == '[')
			{
				st.push(buffer[i]);
			}
			else if (buffer[i] == ')' || buffer[i] == ']')
			{
				if (st.empty() == true)
				{
					flag = NO;
					break;
				}
				else
				{
					if (isCheckPair(st.top(), buffer[i]) == true)
					{
						st.pop();
					}
					else
					{
						flag = NO;
						break;
					}
				}
			}
		}
		if (st.empty() == false) flag = NO;
		cout << result[flag] << '\n';
	}
	return 0;
}