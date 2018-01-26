#pragma once
#include "LinkedList.h"

template <class T>
class Queue
{

private:
	LinkedList<T> m_container;

public:
	Queue() {}
	~Queue() {}

	//	Queue functions, as per lectures
	inline bool isEmpty() const;	//	check if the queue is empty
	void enqueue(T obj);	//	queue an object
	T dequeue();	//	dequeue an object, return it
	inline T peek() const;		//	return a copy of the first item in the queue

};

template <class T>
bool Queue<T>::isEmpty() const
{
	return m_container.isEmpty();
}

template <class T>
void Queue<T>::enqueue(T obj)
{
	m_container.addTail(obj);
}

template <class T>
T Queue<T>::dequeue()
{
	return m_container.removeHead();
}

template <class T>
T Queue<T>::peek() const
{
	return m_container.retrieveHead();
}