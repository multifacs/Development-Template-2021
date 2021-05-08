#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
	Node* pNext;
	T data;

	Node(T data = T(), Node* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
};

template<class T>
class SList
{
protected:
	int Size;
	Node<T>* head;

	Node<T>* find_prev(int index)
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;
		return previous;
	}
public:
	class Iterator
	{
	private:
		Node<T>* node;
	public:
		Iterator(Node<T>* _n) : node(_n) {}
		Iterator(Iterator& _v) : node(_v.node) {}

		bool CanMove() { return (node != nullptr); }
		void Move() { node = node->pNext; }

		bool operator==(const Iterator& _v) { return node == _v.node; }
		bool operator!=(const Iterator& _v) { return !((*this) == _v); }

		Iterator operator++(int)
		{
			if (!CanMove())
				throw logic_error("reached end");
			Move();
			return (*this);
		}
		Iterator& operator=(const Iterator& _v)
		{
			node = _v.node;
			return (*this);
		}

		T& operator* () {
			if (node != nullptr)
				return node->data;
			else
				throw logic_error("empty pointer");
		}
	};

	SList()
	{
		Size = 0;
		head = nullptr;
	}
	SList(const SList<T>& _l)
	{
		Size = 0;
		head = nullptr;
		Iterator k = _l.begin_const();
		while(k.CanMove())
		{
			push_back(*k);
			k++;
		}
	}
	~SList()
	{
		clear();
	}

	SList<T>& operator=(const SList<T>& other)
	{
		if (&other == this)
			return *this;
		if (this->root != nullptr)
			clear();

		Size = 0;
		head = nullptr;
		Iterator k = _l.begin_const();
		while (k.CanMove())
		{
			push_back(*k);
			k++;
		}

		return *this;
	}

	Iterator begin() { return Iterator(head); }
	Iterator begin_const() const { return Iterator(head); }
	Iterator end() { return Iterator(nullptr); }

	int GetSize() const { return Size; }

	void push_back(T data)
	{
		if (head == nullptr)
			head = new Node<T>(data);
		else
		{
			Node<T>* current = this->head;
			while (current->pNext != nullptr)
				current = current->pNext;
			current->pNext = new Node<T>(data);
		};

		Size++;
	}

	void pop_front()
	{
		if (Size == 0)
			throw logic_error("list empty");

		Node<T>* temp = head;
		head = head->pNext;
		delete temp;
		Size--;
	}

	void clear()
	{
		while (Size)
			pop_front();
	}

	void push_front(T data)
	{
		head = new Node<T>(data, head);
		Size++;
	}

	void insert(T data, int index)
	{
		if (index < 0 || index > Size)
			throw logic_error("incorrect index");

		if (index == 0)
			push_front(data);
		else if (index == Size)
			push_back(data);
		else
		{
			Node<T>* previous = find_prev(index);

			Node<T>* newNode = new Node<T>(data, previous->pNext);
			previous->pNext = newNode;
			
			Size++;
		}
	}

	void remove(int index)
	{
		if (index < 0 || index >= Size)
			throw logic_error("incorrect index");

		if (index == 0)
			pop_front();
		else if (index == Size - 1)
			pop_back();
		else
		{
			Node<T>* previous = find_prev(index);

			Node<T>* toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;

			delete toDelete;
			Size--;
		}
	}

	void pop_back()
	{
		if (Size == 0)
			throw logic_error("list empty");

		Node<T>* previous = find_prev(Size - 1);

		Node<T>* temp = previous->pNext;
		previous->pNext = nullptr;

		delete temp;
		Size--;
	}

	friend ostream& operator << (ostream& ostr, SList<T>& _l)
	{
		Iterator k = _l.begin();
		ostr << "{";
		for (int i = 0; i < _l.GetSize() - 1; i++)
		{
			ostr << *k << ", ";
			k++;
		}
		ostr << *k << "}";

		return ostr;
	}
};

