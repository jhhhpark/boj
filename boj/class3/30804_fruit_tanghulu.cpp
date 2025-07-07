#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> input;
	queue<int> basket;
	int i = 0, result = 0, N;
	int fruitCnt[10] = { 0, };
	
	cin >> N;
	input.reserve(N);
	for (int i = 0; i < N; i++) {
		int S;
		cin >> S;
		input.push_back(S);
	}


	do {
		basket.push(input[i]);
		fruitCnt[input[i]]++;

		int accCnt = 0;
		for (int i = 1; i < 10; i++) {
			if (fruitCnt[i] > 0) {
				accCnt++;
			}
		}
		if (accCnt > 2) {
			fruitCnt[basket.front()]--;
			basket.pop();
		} else {
			int size = basket.size();
			result = result < size ? size : result;
		}
		i++;
	} while (i < input.size());

	cout << result << '\n';
	return 0;
}