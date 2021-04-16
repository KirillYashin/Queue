#pragma once
#include <iostream>
#include <List.h>
#include <Exception.h>
#include <Element.h>

template <class T>
class Queue : public List <T>
{
protected:
	int count;
public:
	Queue(int len = 0);
	Queue(Queue <T>& que);
	void Push(T el);
	T Top();
	T Get();
	bool IsFull(); 
	bool IsEmpty();
	void Print();
};

template <class T>
Queue<T>::Queue(int len) : List<T>()
{
	count = 0;
}

template <class T>
Queue<T>::Queue(Queue<T>& que) : List<T>(que)
{
	count = que.count;
}

template <class T>
void Queue<T>::Push(T el)
{
	if (IsFull())
		throw Exception("Queue is full");
	else
	{
		List<T>::PushBegin(el);
		count++;
	}
}

template<class T>
T Queue<T>::Top()
{
	if (IsEmpty())
		throw Exception("Queue is empty");
	else {
		Element<T>* temp = List<T>::begin;
		while (temp->GetNext() != 0)
		{
			temp = temp->GetNext();
		}
		T ans = temp->GetData();
		return ans;
	}
}

template <class T>
T Queue<T>::Get()
{
	if (IsEmpty())
		throw Exception("Queue is empty");
	else
	{
		count--;
		return List<T>::GetEnd();
	}
}

template <class T>
bool Queue<T>::IsFull()
{
	return List<T>::IsFull();
}

template <class T>
bool Queue<T>::IsEmpty()
{
	return (count == 0);
}

template<class T>
void Queue<T>::Print()
{
	List<T>::Print();
}
