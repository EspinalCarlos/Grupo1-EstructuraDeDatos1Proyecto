
#include "LinkedStack.h"
#include "NodoLStack.h"
using namespace std;

LinkedStack::LinkedStack() {
    this->top = nullptr;
}

LinkedStack::~LinkedStack() {
    while (top != nullptr) {
        NodoLStack* temp = top;
        top = top->next;
        delete temp;
    }
}

void LinkedStack::push(char* data) {
    char c = *data;
    NodoLStack* nuevoNodo = new NodoLStack(c);
    nuevoNodo->next = top;
    top = nuevoNodo;
}

void LinkedStack::pop() {
    if (top == nullptr) {
        cout << "La pila esta vacía" << endl;
    }
    else {
        NodoLStack* temp = top;
        cout <<"\nCaracter: " << temp->data << "\n\n";
        top = top->next;
        delete temp;
    }
}

void LinkedStack::peek() {
    if (top == nullptr) {
        cout << "La pila esta vacía" << endl;
    }
    else {
        cout << top->data << endl;
    }
    cout << endl;
}

void LinkedStack::isEmpty() {
    if (top == nullptr) {
        cout << "La pila esta vacía" << endl;
    }
    else {
        cout << "La pila no esta vacía" << endl;
    }
}

void LinkedStack::printStack() {
    if (top == nullptr) {
        cout << "La pila esta vacia" << endl;
    }
    else {
        NodoLStack* current = top;
        cout << "Pila: " << endl;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
}

void LinkedStack::vaciar() {
    while (top != nullptr) {
        NodoLStack* temp = top; 
        top = top->next;
        delete temp;
    }
}



