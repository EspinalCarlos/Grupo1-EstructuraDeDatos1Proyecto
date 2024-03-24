#pragma once
#include "Object.h"
#include <string>
class TDACola : public Object {
protected:
	int max_size;
public:
	virtual bool queue() = 0;
	virtual Object* dequeue() = 0;
	virtual Object* peek() = 0;
	virtual bool isEmpty() = 0;
	virtual void clear() = 0;
	virtual void printQueue() = 0;
};