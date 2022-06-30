#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_NUM_SIZE		100'001
#define MAX_STRING_SIZE		400'001

class AC 
{
public:
	AC()
	{
		mRevIndex = 1, mStart = 0, mEnd = 0;
		mVec.resize(MAX_NUM_SIZE, 0);
		memset(mStrFunc, 0, sizeof(mStrFunc));
	}

	bool Process() 
	{
		int revCount = 0, i = 0;
		while(mStrFunc[i] != '\0')
		{
			if (mStrFunc[i] == 'R')
			{
				++revCount;
			}
			else
			{
				if (isEmpty() == true)
				{
					cout << "error" << '\n';
					return false;
				}
				else
				{
					if ((revCount & 1) == 1)
					{
						reverseArray();
						revCount = 0;
					}
					deleteData();
				}
			}
			++i;
		}
		if (revCount > 0)
		{
			if ((revCount & 1) == 1)
			{
				reverseArray();
			}
		}
		return true;
	}
	void Input()
	{
		Init();

		cin.getline(mStrFunc, MAX_NUM_SIZE);

		char str[MAX_STRING_SIZE] = { 0, };
		int size = 0;
		cin >> size;
		cin.ignore();

		cin.getline(str, MAX_STRING_SIZE);
		int i = 0, n = 0;
		while (str[i] != ']')
		{
			int tmp = str[i] - '0';
			if (tmp >= 0 && tmp <= 9)
			{
				n *= 10;
				n += tmp;
			}
			else if (str[i] == ',')
			{
				mVec[mEnd] = n;
				++mEnd;
				n = 0;
			}
			++i;
		} 
		if (size > 0)
		{
			mVec[mEnd] = n;
			++mEnd;
		}

		return;
	}

	void Output()
	{
		cout << '[';
		int start = mRevIndex > 0 ? mStart : mEnd - 1;
		int end = mRevIndex > 0 ? mEnd: mStart - 1;
		while (start != end)
		{
			cout << mVec[start];
			if (distance(start, end) > 1)
			{
				cout << ',';
			}
			start += mRevIndex;
		}
		cout << ']' << '\n';
		return;
	}
private:
	int mRevIndex;
	int mStart, mEnd;
	vector<int> mVec;
	char mStrFunc[MAX_NUM_SIZE];

	bool isEmpty()
	{
		return mEnd == mStart;
	}

	void Init()
	{
		mStart = 0, mEnd = 0, mRevIndex = 1;
		memset(mStrFunc, 0, sizeof(mStrFunc));
		return;
	}

	void reverseArray()
	{
		mRevIndex = ~(mRevIndex) + 1;
		return;
	}

	void deleteData()
	{
		if (mRevIndex > 0) ++mStart; else --mEnd;
		return;
	}

	int distance(int n1, int n2)
	{
		int res = n1 - n2;
		return res > 0 ? res : ~res + 1;
	}
};

int problem_5430()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	AC ac;
	int T = 0;
	cin >> T;
	cin.ignore();

	for (int i = 0; i < T; ++i)
	{
		ac.Input();
		bool bSuccess = ac.Process(); 
		if (bSuccess == true)
		{
			ac.Output();
		}
	}

	return 0;
}