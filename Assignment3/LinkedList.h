#pragma once

template <class T>
class LinkedList
{

private:
	class Node
	{
	public:
		Node(T object, Node* nxt = nullptr) : value(object), next(nxt) {}
		Node* next;
		T value;
	};

	Node* m_head;
	unsigned int m_size;


public:
	LinkedList() {}
	~LinkedList()
	{
		Node* node = nullptr;
		Node* currentNode = m_head;

		for (int i = 0; i < m_size; ++i)
		{
			node = currentNode;
			currentNode = currentNode->next;
			delete node;

		}
		node = nullptr;
		currentNode = nullptr;
		m_head = nullptr;
	}

	int size() const;	//	returns the size of the linked list
	bool isEmpty() const;	//	returns if the ll is empty or now
	void addHead(T obj);	//	add an object to the front of the list
	T removeHead();		// remove the first object in the ll
	T retrieveHead() const; // return a copy of the first element in the list.
	void addTail(T obj);	//	add an object to the end of the linked list -- useful for Queue's enqueue.
	void removeTail();		//	remove the object at the end of the linked list
	T retrieveTail() const;	//	retrieve the object at the end of the ll


	T retrieve(unsigned int n) const;	//	retrieve the object at position n - listed for complete definition of linked list, not implemented for lack of use in Queue
	void add(unsigned int n, T obj);	//	adds an object to position n	--	is listed for a complete definition of a linked list, not implemented
										//	because I won't be using this in my program.
	T replace(unsigned int n, T obj);	//	replaces n with obj and returns the displaced T; listed but not implemented.
	T remove(unsigned int n);			//	remove and return the object at position n; listed but not implemented.

};

template <class T>
int LinkedList<T>::size() const
{
	return m_size;
}

template <class T>
bool LinkedList<T>::isEmpty() const
{
	return m_size == 0;
}

template <class T>
void LinkedList<T>::addHead(T obj)
{
	/*		---	Old implementation
	Node* temp = m_head;
	m_head = &obj;
	m_head->next = temp;

	temp = nullptr;
	m_size++;
	*/
	Node* temp = m_head;

	m_head = new Node(obj, temp);
	temp = nullptr;

	m_size++;
}

template <class T>
T LinkedList<T>::removeHead()
{
	T toReturn = m_head->value;

	Node* temp = m_head;
	m_head = m_head->next;

	delete temp;
	temp = nullptr;
	m_size--;

	return toReturn;
}

template <class T>
T LinkedList<T>::retrieveHead() const
{
	return m_head->value;
}

template <class T>
void LinkedList<T>::addTail(T obj)
{
	if (m_head)
	{
		Node* temp = m_head;
		for (int i = 1; i < m_size; ++i)
		{
			temp = temp->next;
		}

		temp->next = new Node(obj);
		temp = nullptr;
	}
	else
	{
		m_head = new Node(obj, nullptr);
	}


	m_size++;
}

template <class T>
void LinkedList<T>::removeTail()
{
	Node* temp = m_head;

	for (int i = 1; i < m_size; ++i)
	{
		temp = temp->next;
	}

	delete temp->next;

	temp->next = nullptr;

	m_size--;
}

template <class T>
T LinkedList<T>::retrieveTail() const
{
	Node* temp = m_head;

	for (int i = 1; i < m_size; ++i)
	{
		temp = temp->next;
	}

	return temp->value;
}