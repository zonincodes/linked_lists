#pragma once

class IntSLLNode {
public:
	IntSLLNode() {
		next = 0;
	}

	IntSLLNode(int i, IntSLLNode* ptr = 0) {
		info = i; 
		next = ptr;
	}

	int info;
	IntSLLNode* next;
};

class IntSLList
{
public:
	IntSLList() {
		head = tail = 0;
	}

	~IntSLList();

	int isEmpty() {
		return head == 0;
	}

	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode();
	bool isInList(int) const;


private:
	IntSLLNode* head, * tail;
};

