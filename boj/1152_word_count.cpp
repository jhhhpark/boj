#include <iostream>

using std::string;

#define TRIM_SPACE	" \t\n\r\v\f"

inline string& ltrim(string& str, const char* drop = TRIM_SPACE)
{
	str.erase(0, str.find_first_not_of(drop + 1));
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	string strWord;


	return 0;
}