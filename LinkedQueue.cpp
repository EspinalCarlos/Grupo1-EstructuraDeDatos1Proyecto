#include "LinkedQueue.h"
#include <string>
#include <iostream>
#include "Nodo.h"
using namespace std;

LinkedQueue::LinkedQueue() { //EL constructor que inicializa el LinkedQueue
}

LinkedQueue::~LinkedQueue() {//El destructor
    clear();
}

void LinkedQueue::queue(Object* dato) {//Este metodo inserta un objeto al final del LinkedQueue
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

Object* LinkedQueue::dequeue() { //retorna el primero objeto del queue, y lo saca
    if (isEmpty()) {
        return nullptr;
    }
    else {
        Nodo* ptr = frente;
        Object* dato = ptr->getDato();
        if (frente == atras) { //verifica si solo hay un objeto
            atras = nullptr;
            frente = nullptr;
        }
        else {
            frente = frente->getSiguiente();
        }
        return dato;


    }
}

Object* LinkedQueue::peek() { //Imprime el primer objeto del queue
    if (isEmpty()) {
        return nullptr;
    }
    else {
        return frente->getDato();
    }
}

bool LinkedQueue::isEmpty() { //Verifica si el queue esta vacio o no
    if (frente == nullptr && atras == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

void LinkedQueue::clear() { //borra todos los datos del queue
    while (!isEmpty()) { //Recorre el queue, borrando cada rato
        dequeue();
    }
}

void LinkedQueue::printQueue() {//Imprime todos los datos en el queue
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
