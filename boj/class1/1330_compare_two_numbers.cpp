#include <iostream>

using namespace std;

int problem_1330()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int nData1 = 0;
	int nData2 = 0;
	string strOutput = "";

	// input
	cin >> nData1 >> nData2;

	// output
	if (nData1 > nData2) 
	{
		strOutput = ">";
	}
	else if (nData1 < nData2)  
	{
		strOutput = "<";
	}
	else 
	{
		strOutput = "==";
	}

	cout << strOutput << '\n';
	return 0;
}