#include "Nodo.h"
using namespace std;

Nodo::Nodo(){
	this->anterior = nullptr;
	this->siguiente = nullptr;
}

Nodo::~Nodo() {
	delete this->dato;
}

void Nodo::setSiguiente(Nodo* node) {
	this->siguiente = node;
}
void Nodo::setAnterior(Nodo* node) {
	this->anterior = node;
}
Nodo* Nodo::getAnterior() {
	return this->anterior;
}
Nodo* Nodo::getSiguiente() {
	return this->siguiente;
}
Object* Nodo::getDato() {
	return this->dato;
}
void Nodo::setDato(Object* obj) {
	this->dato = obj;
}