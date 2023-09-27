#pragma once

template <class T>
class DLLNode
{
public:
	DLLNode()
	{
		next = prev = 0;
	}
	DLLNode(const T& el, DLLNode* n = 0, DLLNode* p = 0) 
	{
		info = el; next = n; prev = p;
	}


	T info;
	DLLNode* next, * prev;
};

template<class T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	void AddToDLLTail(const T&);
	T deleteFromDLLTail();

protected:
	DLLNode<T> * head, *tail;
};

