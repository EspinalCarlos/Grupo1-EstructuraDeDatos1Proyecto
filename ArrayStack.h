#pragma once
#include <iostream>
#include "Stack.h"

class ArrayStack : public Stack{
private:
    static const int capacidadInicial = 20;
    char* stackArray;
    int capacidad;
    int top;

public:
    ArrayStack();
    ~ArrayStack();
    void push(char*) override;
    void pop() override;
    void peek() override;
    void isEmpty() override;
    void printStack() override;
    void vaciar() override;
};