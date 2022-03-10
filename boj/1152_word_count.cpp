#include <iostream>
#include <string>

#define TRIM_SIGN	" \t\n\r\v\f"

inline std::string& lTrim(std::string& str, const char* drop = TRIM_SIGN)
{
	str.erase(0, str.find_first_not_of(drop));
	return str;
}

inline std::string& rTrim(std::string& str, const char* drop = TRIM_SIGN)
{
	str.erase(str.find_last_not_of(drop) + 1);
	return str;
}

inline std::string& Trim(std::string& str, const char* drop = TRIM_SIGN)
{
	rTrim(lTrim(str));
	return str;
}

int problem_1152()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string str = "";
	int nCount = 0;

	std::getline(std::cin, str);
	Trim(str, " ");
	if (str.length() > 0)
	{
		++nCount;
	}
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == ' ')
		{
			++nCount;
		}
	}
	std::cout << nCount << '\n';
	return 0;
}