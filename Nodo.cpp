#include "Nodo.h"
using namespace std;

Nodo::Nodo(){
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