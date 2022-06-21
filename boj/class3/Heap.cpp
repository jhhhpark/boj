#include <iostream>
using namespace std;

#define MAX_HEAP_SIZE			500

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
	T Peek() const
	{
		return mSize == 0 ? INT_MAX : mHeap[1]->data;
	}

	int GetSize() const 
	{
		return mSize;
	}

	bool IsEmpty() const
	{
		return mSize <= 0;
	}

	bool IsFull() const
	{
		return mSize >= MAX_HEAP_SIZE;
	}

	Heap() 
	{
		mSize = 0;
	}

	~Heap()
	{
		for (int i = 1; i <= mSize; ++i)
		{
			delete mHeap[i];
		}
		mSize = 0;
	}

	void InsertData(const T data)
	{
		if (IsFull() == true)
		{
			cout << "Heap is Full." << '\n';
		}
		else
		{
			int index = ++mSize;
			while ((index != 1) && Compare(data, mHeap[index / 2]->data) == true)
			{
				mHeap[index] = mHeap[index / 2];
				index /= 2;
			}
			mHeap[index] = new Node<T>(data);
		}

		return;
	}

	const T DeleteData(const T data)
	{
		if (IsEmpty() == true)
		{
			cout << "Heap is empty." << '\n';
			return INT_MAX;
		}
		else
		{
			int parentIndex = 1;
			int childIndex = 2;

			Node<T>* tmp = mHeap[mSize--];
			T delData = mHeap[parentIndex]->data;

			delete mHeap[parentIndex];

			while (childIndex <= mSize)
			{
				if ((childIndex < mSize) && Compare(mHeap[childIndex]->data, mHeap[childIndex + 1]->data) == false)
				{
					++childIndex;
				}

				if (Compare(tmp->data, mHeap[childIndex]->data) == true)
				{
					break;
				}

				mHeap[parentIndex] = mHeap[childIndex];
				parentIndex = childIndex;
				childIndex *= 2;
			}

			mHeap[parentIndex] = tmp;
			return delData;
		}
	}
protected:
	virtual bool Compare(const T d1, const T d2) = 0;

private:
	int mSize;
	Node<T>* mHeap[MAX_HEAP_SIZE];
};

template <typename T>
class MaxHeap : public Heap<T>
{
protected:
	bool Compare(const T d1, const T d2) override
	{
		return d1 > d2;
	}
};

template <typename T>
class MinHeap : public Heap<T>
{
protected:
	bool Compare(const T d1, const T d2) override
	{
		return d1 > d2;
	}
};


int main(int argc, char* argv[])
{
	MinHeap<int> heap;
	for (int i = 0; i < 10; ++i)
	{
		heap.InsertData(i + 1);
		cout << "size : " << heap.GetSize() << ", current Max : " << heap.Peek() << '\n';
	}
	for (int i = 0; i < 10; ++i)
	{
		int del = heap.DeleteData(i + 1);
		cout << "size : " << heap.GetSize() << ", current Max : " << heap.Peek() << '\n';
	}

	return 0;
}