#pragma once
#include "TDACola.h"
#include <string>
class ArrayQueue : public TDACola
{
private:
	int index_last;
	Object** queueList;
public:
	ArrayQueue();
	~ArrayQueue();
	virtual void queue(Object*);
	virtual Object* dequeue();
	virtual Object* peek();
	virtual bool isEmpty();
	virtual void clear();
	virtual void printQueue();
};