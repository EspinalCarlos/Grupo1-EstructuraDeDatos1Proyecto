#pragma once
#include "Object.h"
class Nodo{
protected:
	Object* dato;
	Nodo* siguiente;
	Nodo* anterior;
public:
	Nodo();
	~Nodo();
	void setSiguiente(Nodo*);
	void setAnterior(Nodo*);
	Nodo* getAnterior();
	Nodo* getSiguiente();
	void setDato(Object*);
	Object* getDato();
};

