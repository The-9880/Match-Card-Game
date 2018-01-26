#pragma once
#define DEFAULT_LIST 50
template <class T>
class List
{
private:
	int m_capacity;	//	Default capacity of the List container shall be 50.
	int m_size = 0;			//	m_size counts how many elements are in our list.
	T* m_container;			//	This is the underlying array which holds our objects. List acts like sort of a wrapper for this.
	void replaceContainer();	//	Function to handle doubling capacity when necessary, made private because it's not meant for explicit calls elsewhere.

public:
	List() : m_capacity(DEFAULT_LIST) { m_container = new T[m_capacity]; };
	List(unsigned int capacity) : m_capacity(capacity) { m_container = new T[capacity]; }

	//	List functions as per the lectures.
	inline bool isEmpty() const;	//	check if the list is empty
	inline bool isFull() const;	//	check if the list is full
	inline int getLength() const;	//	return the length of the list

	void insert(unsigned int pos, T object);	//	insert an element at position pos in the list
	void append(T object);			//	Adds an item to the end of the list.
	T remove(unsigned int pos);		//	remove element at position pos in the list and return it
	T retrieve(unsigned int pos) const;	//	retrieve the element at position pos
	T replace(unsigned int pos, T object);	//	displace the element at position pos with object and return it.
	void swap(unsigned int posOne, unsigned int posTwo);	//	swap the objects at two different positions.

	//template <class Comparison>
	//int find(T key) const;		//	This is meant to find an object similar to key in our list and return its position.

	int find(T key) const;			//	Meant to find an object similar to key in our list and return its position.


	class Iterator					//	Iterator class definition for list.
	{
	private:
		T* ptr;
	public:
		Iterator() {}
		Iterator(T* pr) : ptr(pr) {}
		Iterator operator++() { ptr++; return *this; }
		bool operator!=(Iterator& B) { return ptr != B.ptr; }
		T operator*() { return *ptr; }
		T getValue() { return *ptr; }
		void setValue(T value) { *ptr = value; }
	};

	Iterator begin() { return Iterator(&m_container[0]); }
	Iterator end() { return Iterator(&m_container[m_size - 1]); }
};

template <class T>
bool List<T>::isEmpty() const
{
	return (m_size == 0);
}

template <class T>
bool List<T>::isFull() const
{
	return m_size == m_capacity;
}

template <class T>
int List<T>::getLength() const
{
	return m_size;
}

template <class T>
void List<T>::replaceContainer()
{
	m_capacity *= 2;
	T* temp = new T[m_capacity];
	for (int i = 0; i < m_size; ++i)
	{
		temp[i] = m_container[i];
	}

	delete[] m_container;
	m_container = temp;
	temp = nullptr;
}

template <class T>
void List<T>::insert(unsigned int pos, T object)
{
	//	For intuitive usage, the argument pos will be taken starting from 1.
	//	Here, I'll convert it to its proper index value though.
	int idx = pos - 1;

	//	First, we'll check and handle the availability of space in the container.
	if (m_size == m_capacity)
		replaceContainer();

	//	Now, we'll handle the insertion by shifting all elements at and beyond the insertion point down by a space.
	for (int i = m_size; i > idx; --i)
	{
		m_container[i] = m_container[i - 1];
	}

	//	Now, we can set the T at idx equal to object.
	m_container[idx] = object;
	m_size++;
}

template <class T>
void List<T>::append(T object)
{
	//	Check for the space and then add to the end of the list.
	if (m_size == m_capacity)
		replaceContainer();
	m_container[m_size] = object;

	m_size++;
}

template <class T>
T List<T>::retrieve(unsigned int pos) const
{
	return m_container[pos - 1];
}

template <class T>
void List<T>::swap(unsigned int posOne, unsigned int posTwo)
{
	//	First, a simple check to save work if we're swapping an element with itself
	if (posOne == posTwo)
		return;

	//	convert to index-appropriate values.
	int pos1 = posOne - 1, pos2 = posTwo - 1;
	//	Classic swap using a temporary object/variable.
	T temp = m_container[pos1];
	m_container[pos1] = m_container[pos2];
	m_container[pos2] = temp;

}
/*		---	Old implementation.
template <class T> template <class Comparison>
int List<T>::find(T key) const
{
	for (int i = 0; i < m_size; ++i)
	{
		if (Comparison::compare(retrieve(i), key))
			return i;
	}

	return -1;
}
*/

template <class T>
int List<T>::find(T key) const
{
	for (int i = 1; i <= m_size; ++i)
	{
		if (retrieve(i) == key)
			return i;
	}

	return -1;
}

template <class T>
T List<T>::remove(unsigned int pos)
{
	//	Can 'remove' item by moving all succeeding elements forward one place in the list
	//	Overwriting it. Then, decrement size to make the last element inaccessible unless we overwrite it later (by adding an object at that position)
	T toRemove = m_container[pos - 1];

	for (int i = pos - 1; i < m_size; ++i)
	{
		m_container[i] = m_container[i + 1];
	}

	m_size--;
	return toRemove;
}

template <class T>
T List<T>::replace(unsigned int pos, T object)
{
	T displaced = m_container[pos - 1];
	m_container[pos - 1] = object;

	return displaced;
}