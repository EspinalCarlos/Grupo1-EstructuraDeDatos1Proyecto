#pragma once
#include "TDACola.h"
#include "Object.h"
#include "Nodo.h"
#include <string>


class LinkedQueue
	: public TDACola {
private:
	Nodo* frente;
	Nodo* atras;
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