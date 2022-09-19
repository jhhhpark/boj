#include <iostream>
#include <cstring>
using namespace std;

#define DEFAULT_LENGTH			20

class Set
{
public:
	Set()
		: arr{ false, },
		length(0),
		capacity(DEFAULT_LENGTH)
	{
	}
	~Set()
	{
	}

	int add(int data)
	{
		int ins = -1;
		if (arr[data] == false)
		{
			arr[data] = true;
			ins = data;
			++length;
		}
		return ins;
	}

	int remove(int data)
	{
		int rem = -1;
		if (arr[data] == true)
		{
			arr[data] = false;
			rem = data;
			--length;
		}
		return rem;
	}

	bool check(int data)
	{
		return arr[data];
	}

	void toggle(int data)
	{
		if (arr[data] == true)
		{
			arr[data] = false;
			--length;
		}
		else
		{
			arr[data] = true;
			++length;
		}
	}

	void all()
	{
		memset(arr, 1, sizeof(arr));
		length = capacity;
	}

	void empty()
	{
		memset(arr, 0, sizeof(arr));
		length = 0;
	}

private:
	bool arr[DEFAULT_LENGTH + 1];
	int length;
	int capacity;
};

int problem_11723()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	Set S;
	int M, x;
	
	cin >> M;
	cin.ignore(256, '\n');
	for (int i = 0; i < M; ++i)
	{
		cin >> input;
		if (input == "add")
		{
			cin >> x;
			S.add(x);
		}
		else if (input == "remove")
		{
			cin >> x;
			S.remove(x);
		}
		else if (input == "check")
		{
			cin >> x;
			cout << S.check(x) << '\n';
		}
		else if (input == "toggle")
		{
			cin >> x;
			S.toggle(x);
		}
		else if (input == "all")
		{
			S.all();
		}
		else if (input == "empty")
		{
			S.empty();
		}
		else
		{
			/* Wrong Type Instruction */
		}

	}

	return 0;
}