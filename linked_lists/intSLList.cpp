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

void IntSLList::deleteNode()
{

}