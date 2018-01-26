#pragma once
#include "Functors.h"
#include "List.h"

template < class T, class Order = lessThan>
class OrderedList
{
private:
	List<T> m_container;

public:

	OrderedList() { }
	OrderedList(unsigned int cap) : m_container(cap) { }

	//	Functions of an OrderedList, as per lectures.
	inline int getLength() const;
	inline bool isEmpty() const;
	inline bool isFull() const;

	int insert(T object);

	int find(T object) const;
	T remove(unsigned int pos);
	T retrieve(unsigned int pos);
};

template <class T, class Order>
int OrderedList<T, Order>::getLength() const
{
	return m_container.getLength();
}

template <class T, class Order>
bool OrderedList<T, Order>::isEmpty() const
{
	return m_container.isEmpty();
}

template<class T, class Order>
bool OrderedList<T, Order>::isFull() const
{
	return m_container.isFull();
}

template <class T, class Order>
int OrderedList<T, Order>::insert(T object)
{

	int idx;
	for (idx = 1; idx <= getLength(); ++idx)
	{
		if (Order::compare(object, m_container.retrieve(idx)))
			break;
	}
	m_container.insert(idx, object);
	return idx;
}

template <class T, class Order>
int OrderedList<T, Order>::find(T object) const
{
	return m_container.find(object);
}

template <class T, class Order>
T OrderedList<T, Order>::remove(unsigned int pos)
{
	return m_container.remove(pos);
}

template <class T, class Order>
T OrderedList<T, Order>::retrieve(unsigned int pos)
{
	return m_container.retrieve(pos);
}