#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

enum Instructor
{
	PushFront,
	PushBack,
	PopFront,
	PopBack,
	Size,
	Empty,
	Front,
	Back
};

template <typename T>
struct Node {
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node(T data) {
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}
};

template <typename T>
class Deque
{
public:
	Deque()
	{
		left = new Node<T>(-1);
		right = new Node<T>(-1);
		length = 0;
		capacity = 1;

		left->prev = nullptr;
		left->next = right;
		right->prev = left;
		right->next = nullptr;
	}

	~Deque()
	{
		while (left != nullptr) {
			Node<T>* nextNode = left->next;
			delete left;
			left = nextNode;
		}
	}

	void push_front(T data) {
		if (full())
		{
			capacity *= 2;
		}

		Node<T>* newNode = new Node<T>(data);
		Node<T>* nextNode = left->next;
		newNode->next = nextNode;
		nextNode->prev = newNode;

		newNode->prev = left;
		left->next = newNode;
		++length;
	}

	void push_back(T data)
	{
		if (full())
		{
			capacity *= 2;
		}

		Node<T>* newNode = new Node<T>(data);
		Node<T>* prevNode = right->prev;
		prevNode->next = newNode;
		newNode->prev = prevNode;

		newNode->next = right;
		right->prev = newNode;
		++length;
	}

	T pop_front()
	{
		if (empty()) {
			return -1;
		}

		Node<T>* delNode = left->next;
		Node<T>* nextNode = delNode->next;
		T data = delNode->data;

		left->next = nextNode;
		nextNode->prev = left;
		--length;

		return data;
	}

	T pop_back()
	{
		if (empty())
		{
			return -1;
		}

		Node<T>* delNode = right->prev;
		T data = delNode->data;

		Node<T>* prevNode = delNode->prev;
		prevNode->next = right;
		right->prev = prevNode;
		--length;

		return data;
	}

	int size() const
	{
		return length;
	}

	int full() const
	{
		return length == capacity;
	}

	int empty() const
	{
		return length == 0;
	}

	T front()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return left->next->data;
		}
	}

	T back()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return right->prev->data;
		}
	}
private:
	Node<T>* left;
	Node<T>* right;
	int length;
	int capacity;
};

vector<string> split(string input, char delim)
{
	stringstream ss(input);
	vector<string> instructor;
	string temp;
	while (getline(ss, temp, delim))
	{
		instructor.push_back(temp);
	}
	return instructor;
}

int problem_10866()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string inst[8] = {
		"push_front", "push_back",
		"pop_front", "pop_back",
		"size", "empty",
		"front", "back"
	};
	Deque<int> dq;
	string input = "";

	int N = 0;
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; ++i)
	{
		getline(cin, input);
		vector<string> output = split(input, ' ');
		for (int j = 0; j < 8; ++j)
		{
			if (output[0] == inst[j])
			{
				switch (j)
				{
				case Instructor::PushFront:
					dq.push_front(atoi(output[1].c_str()));
					break;
				case Instructor::PushBack:
					dq.push_back(atoi(output[1].c_str()));
					break;
				case Instructor::PopFront:
					cout << dq.pop_front() << '\n';
					break;
				case Instructor::PopBack:
					cout << dq.pop_back() << '\n';
					break;
				case Instructor::Size:
					cout << dq.size() << '\n';
					break;
				case Instructor::Empty:
					cout << dq.empty() << '\n';
					break;
				case Instructor::Front:
					cout << dq.front() << '\n';
					break;
				case Instructor::Back:
					cout << dq.back() << '\n';
					break;
				default:
					break;
				}
			}
		}
	}

	return 0;
}