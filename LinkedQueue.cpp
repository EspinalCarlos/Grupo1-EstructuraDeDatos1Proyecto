#include "LinkedQueue.h"
#include <string>
#include <iostream>
using namespace std;

LinkedQueue::LinkedQueue() {
}

LinkedQueue::~LinkedQueue() {
    clear();
}

void LinkedQueue::queue(Object* dato) {
    Nodo* ptr = new Nodo();
    ptr->setDato(dato);
    if (!isEmpty()) {
        atras->setSiguiente(ptr);
        atras = ptr;
    }
    else {
        frente = ptr;
        atras = ptr;
    }
}

Object* LinkedQueue::dequeue() {
    if (isEmpty()) {
        return nullptr;
    }
    else {
        Nodo* ptr = frente;
        Object* dato = ptr->getDato();
        if (frente == atras) {
            atras = nullptr;
            frente = nullptr;
        }
        else {
            frente = frente->getSiguiente();
        }
        return dato;


    }
}

Object* LinkedQueue::peek() {
    if (isEmpty()) {
        return nullptr;
    }
    else {
        return frente->getDato();
    }
}

bool LinkedQueue::isEmpty() {
    if (frente == nullptr && atras == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

void LinkedQueue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

void LinkedQueue::printQueue() {
    if (isEmpty()) {
        cout << "La cola está vacía" << std::endl;
    }
    else {
        Nodo* ptr = frente;
        while (ptr != nullptr) {
            std::cout << ptr->getDato()->toString() << ", ";
            ptr = ptr->getSiguiente();
        }
        std::cout << std::endl;
    }
}
