#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define PUSH		0
#define POP			1
#define SIZE		2
#define TOP			3
#define EMPTY		4

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node()
	{
		data = -1;
		next = nullptr;
		prev = nullptr;
	}
	Node(T data)
	{
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}
};

template <typename T>
class Stack
{
public:
	Stack()
	{
		this->current = nullptr;
		this->front = new Node<T>();
		this->end = new Node<T>();
		this->length = 0;
		this->capacity = 1;

		front->prev = nullptr;
		front->next = end;

		end->prev = front;
		end->next = nullptr;
	}

	~Stack()
	{
		Node<T>* node = front;
		while (node != nullptr)
		{
			Node<T>* next = node->next;
			delete node;
			node = next;
		}
	}

	void push(T data)
	{
		if (length == capacity)
		{
			capacity *= 2;
		}

		Node<T>* newNode = new Node<T>(data);
		Node<T>* prevNode = end->prev;

		end->prev = newNode;
		prevNode->next = newNode;

		newNode->prev = prevNode;
		newNode->next = end;

		current = newNode;
		++length;
		return;
	}

	T pop()
	{
		if (length == 0)
		{
			return -1;
		}
		T data = current->data;

		Node<T>* prevNode = current->prev;

		prevNode->next = end;
		end->prev = prevNode;

		delete current;
		current = prevNode;
		--length;

		return data;
	}

	int size() const
	{
		return length;
	}

	int empty() const
	{
		return length == 0;
	}

	T top()
	{
		if (length == 0)
		{
			return -1;
		}
		return current->data;
	}

private:
	Node<T>* current;
	Node<T>* front;
	Node<T>* end;
	int length;
	int capacity;
};

vector<string> split(string input, char delimiter)
{
	vector<string> instructor;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter))
	{
		instructor.push_back(temp);
	}
	return instructor;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string inst[5] = { "push", "pop", "size", "top", "empty" };
	Stack<int> st;
	string input;
	int N = 0;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; ++i)
	{
		getline(cin, input);
		vector<string> output = split(input, ' ');

		for (int j = 0; j < 5; ++j)
		{
			if (output[0] == inst[j])
			{
				switch (j)
				{
				case PUSH:
					st.push(stoi(output[1]));
					break;
				case POP:
					cout << st.pop() << '\n';
					break;
				case SIZE:
					cout << st.size() << '\n';
					break;
				case TOP:
					cout << st.top() << '\n';
					break;
				case EMPTY:
					cout << st.empty() << '\n';
					break;
				default:
					break;
				}
				break;
			}
		}
	}

	return 0;
}