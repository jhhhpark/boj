#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

enum Instructor {
	Push,
	Pop,
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
class Queue {
public:
	Queue() {
		left = new Node<T>(-1);
		right = new Node<T>(-1);

		left->prev = nullptr;
		left->next = right;
		right->prev = left;
		right->next = nullptr;

		length = 0;
		capacity = 1;
	}
	~Queue() {
		while (left != nullptr)
		{
			Node<T>* nextNode = left->next;
			delete left;
			left = nextNode;
		}
	}

	void push(T data) {
		if (length == capacity) {
			capacity *= 2;
		}
		Node<T>* newNode = new Node<T>(data);
		
		Node<T>* prevNode = right->prev;
		prevNode->next = newNode;
		right->prev = newNode;

		newNode->next = right;
		newNode->prev = prevNode;
		++length;

		return;
	}

	T pop() {
		if (length == 0) {
			return -1;
		}

		Node<T>* delNode = left->next;
		T data = delNode->data;

		Node<T>* nextNode = delNode->next;
		nextNode->prev = left;
		left->next = nextNode;

		delete delNode;
		--length;

		return data;
	}

	int size() const {
		return length;
	}

	int empty() const {
		return length == 0;
	}

	T front() {
		if (length == 0) {
			return -1;
		}
		else
		{
			return left->next->data;
		}
	}

	T back() {
		if (length == 0) {
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

vector<string> split(string input, char delimiter) {
	vector<string> instructor;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		instructor.push_back(temp);
	}
	return instructor;
}

int problem_10845()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string inst[6] = { "push", "pop", "size", "empty", "front", "back"};
	Queue<int> q;
	string input = "";

	int N = 0;
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; ++i)
	{
		input.clear();
		getline(cin, input);
		vector<string> output = split(input, ' ');

		for (int j = 0; j < 6; ++j)
		{
			if (output[0] == inst[j]) 
			{
				switch (j)
				{
				case Instructor::Push:
					q.push(atoi(output[1].c_str()));
					break;
					case Instructor::Pop:
						cout << q.pop() << '\n';
					break;
					case Instructor::Size:
						cout << q.size() << '\n';
					break;
					case Instructor::Empty:
						cout << q.empty() << '\n';
					break;
					case Instructor::Front:
						cout << q.front() << '\n';
					break;
					case Instructor::Back:
						cout << q.back() << '\n';
					break;
				}
			}
		}
	}


	return 0;
}