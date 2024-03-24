#include "LinkedList.h"
#include"Object.h"
#include "Nodo.h"
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
	
}
