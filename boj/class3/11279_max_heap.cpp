#include <iostream>

using namespace std;
#define HEAP_MAX_SIZE		100000

template <typename T>
struct Node {
	T data;
public:
	Node()
		: data(0)
	{
	}
	Node(T _data)
		: data(_data)
	{
	}
};

template <typename T>
class Heap
{
public:
	Heap()
		: mSize(0)
	{
	}
	virtual ~Heap()
	{
		for (int i = 0; i <= mSize; ++i)
		{
			delete mHeap[i];
		}
		mSize = 0;
	}

public:
	T Peek() const { return mSize == 0 ? 0 : mHeap[1]->data; }
	int GetCapacity() { return HEAP_MAX_SIZE; }
	int GetSize() { return mSize; }
	bool IsEmpty() { return mSize == 0; }
	bool IsFull() { return mSize == HEAP_MAX_SIZE; }

	void InsertData(const T data)
	{
		if (IsFull() == true)
		{
			return;
		}
		else
		{
			Node<T>* newNode = new Node<T>(data);
			mSize++;
			mHeap[mSize] = newNode;
			
			int parent = mSize / 2;
			int child = mSize;
			while (parent > 0)
			{
				if (IsCompare(mHeap[parent], mHeap[child]) == true)
				{
					Swap(parent, child);
					child = parent;
					parent /= 2;
				}
				else
				{
					break;
				}
			}
		}
	}

	bool DeleteData()
	{
		if (IsEmpty() == true)
		{
			return false;
		}
		else
		{
			delete mHeap[1];
			mHeap[1] = mHeap[mSize];
			mHeap[mSize] = nullptr;
			mSize--;

			int parent = 1;
			int change = 0;
			while (parent * 2 <= mSize)
			{
				change = parent * 2;
				if (change + 1 <= mSize && IsCompare(mHeap[change], mHeap[change + 1]) == true)
				{
					++change;
				}
				if (IsCompare(mHeap[parent], mHeap[change]) == true)
				{
					Swap(parent, change);
					parent = change;
				}
				else
				{
					break;
				}
			}
			return true;
		}
	}

protected:
	virtual bool IsCompare(const Node<T>* n1, const Node<T>* n2) = 0;

private:
	void Swap(int index1, int index2)
	{
		Node<T>* tmp = mHeap[index1];
		mHeap[index1] = mHeap[index2];
		mHeap[index2] = tmp;
		return;
	}
private:
	Node<T>* mHeap[HEAP_MAX_SIZE];
	int			mSize;
};

template <typename T>
class MaxHeap
	: public Heap<T>
{
	bool IsCompare(const Node<T>* n1, const Node<T>* n2)
	{
		return n1->data < n2->data;
	}
};


int problem_11279()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	MaxHeap<int> heap;

	int T, N;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		if (N == 0)
		{
			cout << heap.Peek() << '\n';
			heap.DeleteData();
		}
		else
		{
			heap.InsertData(N);
		}
	}
	return 0;
}