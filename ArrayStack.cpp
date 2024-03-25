
#include "ArrayStack.h"
using namespace std;

ArrayStack::ArrayStack() {
    capacidad = capacidadInicial;
    stackArray = new char[capacidad];
    top = -1;
}

ArrayStack::~ArrayStack() {
    delete[] stackArray;
}

void ArrayStack::push(char* data) {
    if (top == capacidad - 1) {
        int nuevaCapacidad = capacidad * 2;
        char* nuevoArray = new char[nuevaCapacidad];
        for (int i = 0; i < capacidad; ++i) {
            nuevoArray[i] = stackArray[i];
        }
        delete[] stackArray;
        stackArray = nuevoArray;
        capacidad = nuevaCapacidad;
    }
    top++;
    char c = *data;
    stackArray[top] = c;
}

void ArrayStack::pop() {
    if (top == -1) {
        cout << "La pila esta vacia" << endl;
        cout << endl;
    }
    else {
        cout << "\nCaracter: " << stackArray[top] << "\n\n";
        top--;
    }
}

void ArrayStack::peek() {
    if (top == -1) {
        cout << "La pila esta vacia" << endl;
    }
    else {
        cout << stackArray[top] << endl;
    }
    cout << endl;
}

void ArrayStack::isEmpty() {
    if (top == -1) {
        cout << "La pila esta vacia" << endl;
    }
    else {
        cout << "La pila no esta vacia" << endl;
    }
    cout << endl;
}

void ArrayStack::printStack() {
    if (top == -1) {
        cout << "La pila esta vacia" << endl;
    }
    else {
        cout << "Pila: " << endl;
        for (int i = top; i >= 0; i--) {
            cout << stackArray[i] << endl;
        }
    }
}

void ArrayStack::vaciar() {
    top = -1;
}