#pragma once
#define DEFAULT_STACK 50
#include "List.h"

//	What follows is a list-based implmentation of a Stack container.
template <class T>
class Stack
{

private:
	List<T> m_container;
	typename List<T>::Iterator m_top;//	Pointer to the element at the top of the stack - should always be equal to m_size - 1, last added element.

public:
	Stack(unsigned int cap = DEFAULT_STACK) : m_container(cap) { //m_top = m_container.end();
															   }
	~Stack() {}

	//	Creating functions suggested by lectures.
	inline bool isEmpty() const;	//	Queries if the container is empty
	inline bool isFull() const;		//	Queries if the capacity is full
	void push(T object);			//	Pushes a new T onto the stack
	T pop();						//	Removes the top element
	inline T peek() const;			//	Returns top position element
};

template <class T>
bool Stack<T>::isEmpty() const
{
	return m_container.isEmpty();
}

template <class T>
bool Stack<T>::isFull() const
{
	return m_container.isFull();
}

template <class T>
void Stack<T>::push(T object)
{
	m_container.insert(m_container.getLength() + 1, object);
	m_top = m_container.end();
}

template <class T>
T Stack<T>::pop()
{
	T toReturn = m_container.remove(m_container.getLength());
	m_top = m_container.end();

	return toReturn;
}

template <class T>
T Stack<T>::peek() const
{
	return m_container.retrieve(m_container.getLength());
}