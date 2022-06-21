#include <iostream>

using namespace std;

#define MAX_HEAP_SIZE			100000
#define ROOT					1
#define DELETE_INSTRUCT			0

template <typename T>
struct Node
{
	T data;
	Node(T data)
	{
		this->data = data;
	}
};

template <typename T>
class Heap
{
public:
	Heap() : mSize(0) { }
	~Heap()
	{
		for (int i = 1; i <= mSize; ++i)
		{
			delete mHeap[i];
		}
		mSize = 0;
	}

	bool IsEmpty() const
	{
		return mSize == 0;
	}
	bool IsFull() const
	{
		return mSize == MAX_HEAP_SIZE;
	}
	void InsertData(const T data)
	{
		if (IsFull() == true)
		{
			cout << "heap is full!" << '\n';
			return;
		}
		else
		{
			int index = ++mSize;
			while ((index != ROOT) && isCompare(data, mHeap[index / 2]->data) == true)
			{
				mHeap[index] = mHeap[index / 2];
				index /= 2;
			}
			mHeap[index] = new Node<T>(data);
		}

		return;
	}

	T DeleteData()
	{
		if (IsEmpty() == true)
		{
			return 0;
		}
		else
		{
			int parent = ROOT;
			int child = ROOT + 1;
			Node<T>* comp = mHeap[mSize--];
			T delData = mHeap[ROOT]->data;

			delete mHeap[parent];
			while (child <= mSize)
			{
				if ((child < mSize) && (isCompare(mHeap[child]->data, mHeap[child + 1]->data) == false))
				{
					++child;
				}
				if (isCompare(comp->data, mHeap[child]->data) == true)
				{
					break;
				}
				mHeap[parent] = mHeap[child];
				parent = child;
				child *= 2;
			}
			mHeap[parent] = comp;
			return delData;
		}

		return 0;
	}
protected:
	virtual bool isCompare(T d1, T d2) = 0;

private:
	int mSize;
	Node<T>* mHeap[MAX_HEAP_SIZE];
};

template <typename T>
class MinHeap : public Heap<T>
{
protected:
	bool isCompare(T d1, T d2)
	{
		return d1 < d2;
	}
};

int problem_1927()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	MinHeap<int> heap;
	int N = 0, X = 0, del = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> X;
		if (X == DELETE_INSTRUCT)
		{
			del = heap.DeleteData();
			cout << del << '\n';
		}
		else
		{
			heap.InsertData(X);
		}
	}

	return 0;
}