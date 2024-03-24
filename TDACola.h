#pragma once
#include "Object.h"
#include <string>
class TDACola {
protected:
	int max_size = 10;
public:
	virtual void queue(Object*) = 0;
	virtual Object* dequeue() = 0;
	virtual Object* peek() = 0;
	virtual bool isEmpty() = 0;
	virtual void clear() = 0;
	virtual void printQueue() = 0;
};