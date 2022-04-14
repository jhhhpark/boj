#include <iostream>
using namespace std;

typedef struct TagCard
{
	int CardNumber;
	TagCard()
		: CardNumber(0)
	{
	}
	TagCard(int cardNumber)
		: CardNumber(cardNumber)
	{
	}
}CARD, * PCARD;

template <typename T>
struct Node
{
	T Data;
	Node* PreNode;
	Node* NextNode;
	Node(T data)
	{
		Data = data;
		PreNode = nullptr;
		NextNode = nullptr;
	}
};

template <typename T>
class Queue
{
public:
	Queue()
	{
		headNode = new Node<T>(T());
		currentNode = headNode;
		queueLength = 0;
	}
	~Queue()
	{
		while (currentNode->PreNode != nullptr)
		{
			currentNode = currentNode->PreNode;
			delete currentNode->NextNode;
			currentNode->NextNode = nullptr;
		}
		delete headNode;
	}

	void EnQueue(T data) 
	{
		Node<T>* newNode = new Node<T>(data);
		currentNode->NextNode = newNode;
		newNode->PreNode = currentNode;

		currentNode = newNode;
		++queueLength;
		return;
	}

	T DeQueue()
	{
		if (IsEmpty() == true)
		{
			return headNode->Data;
		}
		else
		{
			Node<T>* deleteNode = headNode->NextNode;

			headNode->NextNode = deleteNode->NextNode;
			if (queueLength > 1)
			{
				headNode->NextNode->PreNode = headNode;
			}
			else
			{
				currentNode = headNode;
			}

			T deleteData = deleteNode->Data;
			delete deleteNode;

			--queueLength;
			return deleteData;
		}
	}

	int GetLength() const
	{
		return queueLength;
	}

	T Peek() const
	{
		if (IsEmpty() == true)
		{
			return headNode->Data;
		}
		else
		{
			return headNode->NextNode->Data;
		}
	}

	bool IsEmpty() const
	{
		return queueLength == 0;
	}

private:
	Node<T>* headNode;
	Node<T>* currentNode;
	int queueLength;
};


class CardQueue
{
public:
	void AddCard(int cardNumber)
	{
		CARD card(cardNumber);
		cardQueue.EnQueue(card);
		return;
	}

	void AddCard(CARD card)
	{
		cardQueue.EnQueue(card);
		return;
	}

	int DiscardCard() {
		if (cardQueue.IsEmpty() == true)
		{
			return INT_MAX;
		}
		else
		{
			CARD deleteCard = cardQueue.DeQueue();
			return deleteCard.CardNumber;
		}
	}

	int GetFrontCardNumber() const
	{
		return cardQueue.Peek().CardNumber;
	}

	int GetCardCount() const
	{
		return cardQueue.GetLength();
	}
private:
	Queue<CARD> cardQueue;
	
};

int problem_2164()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cardCount = 0;
	cin >> cardCount;
	// setting
	CardQueue queue;
	for (int i = 1; i <= cardCount; ++i)
	{
		queue.AddCard(i);
	}

	// logic
	while (queue.GetCardCount() > 1)
	{
		queue.DiscardCard();
		CARD backCard = queue.DiscardCard();
		queue.AddCard(backCard);
	}

	// output
	cout << queue.GetFrontCardNumber() << '\n';

	return 0;
}