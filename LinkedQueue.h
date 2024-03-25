#pragma once
#include "TDACola.h"
#include "Object.h"
#include "NodoLStack.h"
#include <string>


class LinkedQueue
	: public TDACola {
private:
	NodoLStack* frente;
	NodoLStack* atras;
	Object** queueList;
public:
	LinkedQueue();
	~LinkedQueue();
	virtual void queue(Object*);
	virtual Object* dequeue();
	virtual Object* peek();
	virtual bool isEmpty();
	virtual void clear();
	virtual void printQueue();
};