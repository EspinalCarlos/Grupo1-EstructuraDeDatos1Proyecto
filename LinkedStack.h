#pragma once
#include "NodoLStack.h"
#include <iostream>
#include "Stack.h"

class LinkedStack : public Stack {
private:
    NodoLStack* top;

public:
    LinkedStack();
    ~LinkedStack();
    void push(char* data) override;
    void pop() override;
    void peek() override;
    void isEmpty() override;
    void printStack() override;
    void vaciar() override;
};



