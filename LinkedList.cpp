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
//inserta un dato al linkedlist, dependiendo del caso, corre los nodos que se tengan que correr, o asigna el nodo a primero o ultimo y hace los corrimientos necesarios
bool LinkedList::inserta(Object* dato, int position) {
	Nodo* newNode = new Nodo();
	newNode->setDato(dato);
	if (primero == nullptr && ultimo == nullptr) {
		primero = newNode;
		ultimo = newNode;
		size++;
		return true;
	}
	if (position == 1) {
		newNode->setSiguiente(primero);
		primero->setAnterior(newNode);
		primero = newNode;
		size++;
		return true;
	}
	if (position > 1 && position <= size + 1) {
		Nodo* temp = primero;
		for (int i = 1; i < position - 1; i++) {
			temp = temp->getSiguiente();
		}
		newNode->setSiguiente(temp->getSiguiente());
		if (temp->getSiguiente() != nullptr) {
			temp->getSiguiente()->setAnterior(newNode);
		}
		else {
			ultimo = newNode; 
		}
		temp->setSiguiente(newNode);
		newNode->setAnterior(temp);
		size++;
		return true;
	}
	return false;

}
//Tiene varias validaciones, ya que cada caso tiene un proceso diferente
bool LinkedList::suprime(int position) {
	Nodo* temp = this->primero;
	if (position == 1){
		primero = temp->getSiguiente();
		if (primero != nullptr){
			primero->setAnterior(nullptr);
		}
		else{
			ultimo = nullptr; 
		}
		delete temp;
		size--;
		return true;
	}
	else if (position == size) {
		ultimo = ultimo->getAnterior();
		if (ultimo != nullptr){
			ultimo->setSiguiente(nullptr);
			return true;
		}
		else {
			primero = nullptr;
			return true;
		}
	}else if(position <= 0 || position > size) {
		return false;
	}
	else {

		for (int i = 1; i < position - 1; i++) {
			temp = temp->getSiguiente();
		}
		Nodo* nodoAEliminar = temp->getSiguiente();
		temp->setSiguiente(nodoAEliminar->getSiguiente());
		if (nodoAEliminar == ultimo) {
			ultimo = temp;
		}
		else {
			nodoAEliminar->getSiguiente()->setAnterior(temp);
		}
		delete nodoAEliminar;
		size--;
		return true;
	}
}

//recorre lista hasta encontrar el dato que se busca, pero si no lo encuentra, retorna nullptr
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
//recorre toda la lista eliminando uno por uno los nodos, liberando toda la memoria que consumia cada uno, dejando en null los nodos primero y ultimo en caso de querer usarla otra vez la lista
void LinkedList::anula() {
	Nodo* temp = primero;
	while (temp != nullptr) {
		Nodo* siguiente = temp->getSiguiente();
		delete temp;
		temp = siguiente;
	}
	this->primero = nullptr;
	this->ultimo = nullptr;
	this->size = 0;
}
//recorre la lista hasta encontrar la posicion indicada, y retorna el nodo que tiene antes
Object* LinkedList::anterior(int position) {
	Nodo* n = this->primero;
	for (size_t i = 1; i <= position; i++) {
		if (i != position) {
			if (n->getSiguiente() != nullptr) n = n->getSiguiente();
		}
	}
	if (n->getAnterior() == nullptr) {
		return nullptr;
	}
	else {
		return n->getAnterior()->getDato();
	}
}

//recorre la lista hasta encontrar la posicion indicada, y retorna el nodo que tiene despues
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
//recorre la lista imprimiendo los contenidos de cada nodo
void LinkedList::imprimeLista() {
	if (!vacia()){
		Nodo* temp = this->primero;
		for (size_t i = 1; i <= size; i++) {
			cout << '[' << temp->getDato()->toString() << "]-";
			if (temp->getSiguiente() != nullptr)temp = temp->getSiguiente();
		}
		cout << endl;
	}
}
//recorre la lista, comparando el objeto recibido por la funcion, hasta encontrar el objeto que sea igual y retorna la posicion en la que esta
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
//verifica el size de la lista y si es 0, retorna true, significando que esta vacia, retorna false si tiene algun elemento
bool LinkedList::vacia() {
	if (size != 0){
		return false;
	} else{
		return true;
	}
}
