#pragma once
#include "TDALista.h"
#include "Object.h"
#include "Nodo.h"
class LinkedList: public TDALista{
protected:
	Nodo* primero;
	Nodo* ultimo;
public:
	LinkedList();
	~LinkedList();
	virtual bool inserta(Object* data, int position);
	virtual bool suprime(int);
	virtual void anula();
	virtual Object* recupera(int);
	virtual Object* anterior(int);
	virtual Object* siguiente(int);
	virtual void imprimeLista();
	virtual int localiza(Object*);
	virtual bool vacia();
	virtual void append(Object*);
};

