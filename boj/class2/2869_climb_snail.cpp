#include <iostream>
#include <string>
using namespace std;

int problem_2869()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A = 0;
	int B = 0;
	int V = 0;
	int result = 0;
	cin >> A >> B >> V;

	cout << (V - B - 1) / (A - B) + 1<< endl;

	return 0;
}