#include "genDLList.h"



template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = tail = 0;
}

template<class T>
void DoublyLinkedList<T>::AddToDLLTail(const T& el)
{
	if (tail != 0)
	{
		tail = new DLLNode<T>(el, 0, tail);
		tail->prev->next = tail;

	}
	else {
		head = tail = new DLLNode<T>(el);     
	}
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail()
{
	T el = tail->info;
	if (head == tail)
	{
		delete head;
		headd = tail = 0;
	}
	else
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = 0;
	}
	return el;
}