#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, card[500000] = { 0, };
pair<int, int> counter[500000];

int findCardNumber(int num, int last)
{
	int low = 0;
	int high = last;
	int mid = 0;
	int cnt = 0;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (num < counter[mid].first)
		{
			high = mid - 1;
		}
		else if (num > counter[mid].first)
		{
			low = mid + 1;
		}
		else
		{
			cnt = counter[mid].second;
			break;
		}
	}

	return cnt;
}

int problem_10816()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> card[i];
	}
	sort(card, card + N);
	bool bFlag = false;
	int cardIndex = 0;
	int index = 0;
	while (index < N)
	{
		if (bFlag == false)
		{
			bFlag = true;
			counter[cardIndex].first = card[index];
			counter[cardIndex].second = 1;
			++index;
		}
		else
		{
			if (counter[cardIndex].first == card[index])
			{
				++counter[cardIndex].second;
				++index;
			}
			else
			{
				++cardIndex;
				bFlag = false;
			}
		}
	}

	cin >> M;
	int num = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> num;
		cout << findCardNumber(num, cardIndex) << ' ';
	}


	return 0;
}