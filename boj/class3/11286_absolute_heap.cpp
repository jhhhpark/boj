#include <iostream>
#include <cstring>

using namespace std;

#define OUTPUT_INSTRUCT			0
#define MAX_CAPACITY			100001

template <typename T>
struct Node
{
	T data;
public:
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
		: m_iSize(0)
	{
	}

	~Heap()
	{
		for (int i = 1; i <= m_iSize; ++i)
		{
			delete m_arrNode[i];
		}
		m_iSize = 0;
	}

public:
	virtual bool Compare(const Node<T>* node1, const Node<T>* node2) = 0;
	T GetPeek() const { return m_arrNode[1]; }
	int GetSize() { return m_iSize; }
	bool IsEmpty() { return m_iSize == 0; }
	bool IsFull() { return m_iSize == MAX_CAPACITY; }

	void SwapNode(int idx1, int idx2)
	{
		Node<T>* tmp = m_arrNode[idx1];
		m_arrNode[idx1] = m_arrNode[idx2];
		m_arrNode[idx2] = tmp;
		return;
	}

	Node<T>* InsertNode(T data)
	{
		if (IsFull() == true)
		{
			return nullptr;
		}

		Node<T>* pNode = new Node<T>(data);
		m_arrNode[m_iSize + 1] = pNode;
		m_iSize++;

		int iParent = m_iSize / 2;
		int iChild = m_iSize;

		while (iParent > 0)
		{
			if ((iChild & 1) == 1)
			{
				if (Compare(m_arrNode[iChild], m_arrNode[iChild - 1]) == true)
				{
					iChild = m_iSize - 1;
				}
			}
			if (Compare(m_arrNode[iParent], m_arrNode[iChild]) == true)
			{
				SwapNode(iParent, iChild);
			}

			iChild = iParent;
			iParent /= 2;
		}
		return pNode;
	}

	T DeleteNode()
	{
		if (IsEmpty() == true)
		{
			return 0;
		}

		T del = m_arrNode[1]->data;
		delete m_arrNode[1];
		m_arrNode[1] = m_arrNode[m_iSize];
		m_arrNode[m_iSize] = nullptr;
		m_iSize--;

		int iParent = 1;
		int iChild = iParent * 2;
		while (iChild <= m_iSize)
		{
			if (iChild + 1 <= m_iSize)
			{
				if (Compare(m_arrNode[iChild], m_arrNode[iChild + 1]) == true)
				{
					iChild++;
				}
			}

			if (Compare(m_arrNode[iParent], m_arrNode[iChild]) == false)
			{
				break;
			}
			else
			{
				SwapNode(iParent, iChild);
			}

			iParent = iChild;
			iChild = iParent * 2;
		}

		return del;
	}

private:
	Node<T>*	 m_arrNode[MAX_CAPACITY];
	int			 m_iSize;
};

template <typename T>
class AbsoluteHeap
	: public Heap<T>
{
	bool Compare(const Node<T>* nd1, const Node<T>* nd2)
	{
		T data1 = abs(nd1->data);
		T data2 = abs(nd2->data);

		if (data1 == data2)
		{
			return nd1->data > nd2->data;
		}
		else
		{
			return data1 > data2;
		}
	}
};

int problem_11286()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	AbsoluteHeap<int> heap;
	int T, x;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> x;
		if (x == OUTPUT_INSTRUCT)
		{
			int del = heap.DeleteNode();
			cout << del << '\n';
		}
		else
		{
			heap.InsertNode(x);
		}
	}

	return 0;
}