#pragma once
#include "Object.h"
#include <string>
class TDACola : public Object {
protected:
	int max_size;
public:
	virtual bool queue();
	virtual Object* dequeue();
	virtual Object* peek();
	virtual bool isEmpty();
	virtual void clear();
	virtual void printQueue();
};