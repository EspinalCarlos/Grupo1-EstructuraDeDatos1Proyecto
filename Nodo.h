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
};

