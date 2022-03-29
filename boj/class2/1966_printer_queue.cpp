#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T Data;

	Node* PrevNode;
	Node* NextNode;

	Node(T data)
		: Data(data),
		PrevNode(nullptr),
		NextNode(nullptr)
	{
	}

	Node()
		: PrevNode(nullptr),
		NextNode(nullptr)
	{
	}
};

template <typename T>
class CQueue
{
public:
	CQueue()
	{
		mHead = new Node<T>();
		mTail = new Node<T>();

		mHead->PrevNode = nullptr;
		mHead->NextNode = mTail;
		mTail->PrevNode = mHead;
		mTail->NextNode = nullptr;

		mLength = 0;
	}

	~CQueue()
	{
		Node<T>* node = mHead;
		while (node != nullptr)
		{
			Node<T>* nextNode = node->NextNode;
			delete node;
			node = nextNode;
		}
	}

	void EnQueue(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		newNode->PrevNode = mTail->PrevNode;
		newNode->NextNode = mTail;

		mTail->PrevNode->NextNode = newNode;
		mTail->PrevNode = newNode;

		++mLength;
		return;
	}

	T DeQueue()
	{
		if (mLength <= 0)
		{
			return mHead->Data;
		}
		Node<T>* deleteNode = mHead->NextNode;
		T deleteData = deleteNode->Data;

		deleteNode->NextNode->PrevNode = mHead;
		mHead->NextNode = deleteNode->NextNode;

		delete deleteNode;

		--mLength;

		return deleteData;
	}

	T Peek() const
	{
		return mHead->NextNode->Data;
	}

	int Size() const
	{
		return mLength;
	}

	void Clear()
	{
		int size = Size();
		for (int i = 0; i < size; ++i)
		{
			DeQueue();
		}

		return;
	}

private:
	Node<T>* mHead;
	Node<T>* mTail;

	int mLength;
};


struct Document
{
	int priority;
	int position;
	Document()
		: priority(-1),
		position(-1)
	{
	}

	Document(int _priority)
		: priority(_priority),
		position(-1)
	{
	}
	Document(int _priority, int _position)
		:priority(_priority),
		position(_position)
	{
	}
};

class CPrinterQueue
{
public:
	CPrinterQueue()
	{
	}

	~CPrinterQueue()
	{
	}

	void InputDocument(int count) {
		int priority = 0;
		for (int i = 0; i < count; ++i)
		{
			cin >> priority;
			Document document(priority, i);
			queue.EnQueue(document);
		}
		return;
	}

	Document FindDocument(int index)
	{
		Document findDocument;
		for (int i = 0; i < queue.Size(); ++i)
		{
			Document document = queue.DeQueue();
			if (i == index)
			{
				findDocument = document;
			}
			queue.EnQueue(document);
		}
		return findDocument;
	}

	bool DeleteDocument(Document deleteDocument)
	{
		for (int i = 0; i < queue.Size(); ++i)
		{
			Document document = queue.DeQueue();
			if (document.priority == deleteDocument.priority)
			{
				return true;
			}
			queue.EnQueue(document);
		}

		return false;
	}

	Document GetHighPriorityDocument() {
		Document highDocument;
		for (int i = 0; i < queue.Size(); ++i)
		{
			Document document = queue.DeQueue();
			if (highDocument.priority < document.priority)
			{
				highDocument = document;
			}
			queue.EnQueue(document);
		}
		return highDocument;
	}

	int GetLength() const {
		return queue.Size();
	}

	void Clear() {
		queue.Clear();
		return;
	}

	bool isSameDocument(Document src, Document dest) 
	{
		return src.position == dest.position && src.priority == dest.priority;
	}

private:
	CQueue<Document> queue;
};


int problem_1966()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	CPrinterQueue printerQueue;
	int testCase = 0;
	cin >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		int documentCount = 0;
		int documentPosition = 0;
		cin >> documentCount >> documentPosition;
		int order = 1;

		printerQueue.InputDocument(documentCount);

		Document targetDocument = printerQueue.FindDocument(documentPosition);

		int size = printerQueue.GetLength();
		for (int j = 0; j < size; ++j)
		{
			Document highPriorityDocument = printerQueue.GetHighPriorityDocument();
			if (printerQueue.isSameDocument(highPriorityDocument, targetDocument))
			{
				break;
			}
			else
			{
				++order;
				printerQueue.DeleteDocument(highPriorityDocument);
			}
		}
		cout << order << '\n';
		printerQueue.Clear();
	}

	return 0;
}