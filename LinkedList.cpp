#include "LinkedList.h"
#include"Object.h"
#include "Nodo.h"
#include <iostream>
#include<string>
using namespace std;

LinkedList::LinkedList() {
	this->primero = nullptr;
	this->ultimo = nullptr;
	this->size = 0;
}
LinkedList::~LinkedList() {

}

bool LinkedList::inserta(Object* dato, int position) {
	Nodo* newNode = new Nodo();
	newNode->setDato(dato);
	if (primero == nullptr && ultimo == nullptr){
		this->primero = newNode;
		size++;
	}
	else {
		if (position > 0 && position <= size && position!= 1){
			Nodo* temp = primero;
			for (size_t i = 0; i < position-1; i++){
				temp = temp->getSiguiente();
			}
			if (temp->getSiguiente() == nullptr){
				temp->setSiguiente(newNode);
				newNode->setAnterior(temp);
				this->ultimo = newNode; 
				return true;
			}
			else {
				temp->getAnterior()->setSiguiente(newNode); 
				temp->setAnterior(newNode); 
				newNode->setSiguiente(temp); 
				newNode->setAnterior(temp->getAnterior()); 
				return true;
			}
			
		} else if(position == 1){
			this->primero->setAnterior(newNode);
			newNode->setSiguiente(primero);
			this->primero = newNode;
			return true;
			
		}
		return false;
	}

}

bool LinkedList::suprime(int position) {
	return false;
}


Object* LinkedList::recupera(int position) {
	Nodo* temp = this->primero;
	for (size_t i = 1; i <= position; i++){
		if (i == position){
			return temp->getDato();
		}
		else {
			temp = temp->getSiguiente();
		}
	}
	return nullptr; 
}

void LinkedList::anula() {
	Nodo* temp = ultimo;
	for (size_t i = size; i >= 1; i--) {
		if (temp->getAnterior() != nullptr) {
			temp = temp->getAnterior();
			delete temp->getSiguiente();
		}
		else {
			delete temp;
		}
	}
}
Object* LinkedList::anterior(int position) {
	Nodo* n = this->primero;
	for (size_t i = 1; i <= position; i++) {
		if (i != position) {
			if (n->getSiguiente() != nullptr)n = n->getSiguiente();
		}
	}
	if (n->getAnterior() == nullptr) {
		return nullptr;
	}
	else {
		return n->getAnterior()->getDato();
	}
}


Object* LinkedList::siguiente(int position) {
	Nodo* n = this->primero;
	for (size_t i = 1; i <= position; i++){
		if (i!=position){
			if (n->getSiguiente() != nullptr)n = n->getSiguiente();
		}
	}
	if (n->getSiguiente() == nullptr){
		return nullptr;
	}
	else {
		return n->getSiguiente()->getDato();
	}
}

void LinkedList::imprimeLista() {
	Nodo* temp = this->primero;
	for (size_t i = 1; i <= size; i++){
		cout << '['<<temp->getDato()->toString()<<"]-";
		if(temp->getSiguiente() != nullptr)temp = temp->getSiguiente();
	}
	cout << endl;
}

int LinkedList::localiza(Object* obj) {
	Nodo* temp = this->primero;
	if (temp->getDato()->equals(obj)){
		return 1;
	}
	else {
		for (size_t i = 1; i <= size; i++){
			if (temp->getDato()->equals(obj)){
				return i ;
			}
			else {
				if (temp->getSiguiente() != nullptr)temp = temp->getSiguiente();
			}
		}
	}
	return -1;
}

bool LinkedList::vacia() {
	if (size != 0){
		return false;
	} else{
		return true;
	}
}
void LinkedList::append(Object* obj) {
	Nodo* newNodo = new Nodo();
	newNodo->setDato(obj);
	this->ultimo->setSiguiente(newNodo);
	newNodo->setAnterior(this->ultimo);
	ultimo = newNodo;
}