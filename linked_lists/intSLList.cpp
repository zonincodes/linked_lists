#include "intSLList.h"
#include <iostream>

IntSLList::~IntSLList()
{
	for (IntSLLNode* p; !isEmpty(); )
	{
		p = head->next;
		delete head;
		head = p;
	}
}

void IntSLList::addToHead(int el)
{
	head = new IntSLLNode(el, head);
	if (tail == 0)
		tail = head;
}

void IntSLList::addToTail(int el)
{
	if (tail != 0) {
		tail->next = new IntSLLNode(el);
		tail = tail->next;
	}
	else head = tail = new IntSLLNode(el);
}

int IntSLList::deleteFromHead()
{
	int el = head->info;
	IntSLLNode* temp = head;
	if (head == tail)
	{
		head = tail = 0;
	}
	else {
		head = head->next;
	}
	delete temp;
	return el;
}

int IntSLList::deleteFromTail()
{
	int el = tail->info;

	if (head == tail)
	{
		delete head;
		head = tail = 0;
	}
	else {
		IntSLLNode* tmp;

		for (tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp;
		tail->next = 0;
	}
	return el;

}

void IntSLList::deleteNode(int el)
{
	if (head != tail)										// if non empty list;
	{
		if (head == tail && el == head->info)				// if only one
		{
			delete head;									// node is in the list
			head = tail = 0;
		}

		else if (el == head->info)							//if more than one node and el is equal to head
		{
			deleteFromHead();								// the old head is deleted
		}
		else
		{													// if more than one node is in the list
			IntSLLNode* pred, * tmp;
			for (pred = head, tmp = head->next;				// and a none head node
				tmp != 0 && !(tmp->info == el);				// is deleted
				pred = pred->next, tmp = tmp->next);		

			if (tmp != 0)
			{
				pred->next = tmp->next;
				if (tmp == tail)
					tail = pred;
				delete tmp;
			}
		}
	}
}

bool IntSLList::isInList(int el) const {
	IntSLLNode* tmp;
	for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
	return tmp != 0;
}