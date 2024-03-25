#pragma once
class Stack {
public:
	virtual void push(char*) = 0;
	virtual void pop() = 0;
	virtual void peek() = 0;
	virtual void isEmpty() = 0;
	virtual void printStack() = 0;
	virtual void vaciar() = 0;
};

