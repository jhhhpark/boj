#include <iostream>

using namespace std;

int problem_10869()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A;
	int B;
	cin >> A >> B;

	cout << A + B << "\n"
		<< A - B << "\n"
		<< A * B << "\n"
		<< A / B << "\n"
		<< A % B << "\n";

	return 0;
}