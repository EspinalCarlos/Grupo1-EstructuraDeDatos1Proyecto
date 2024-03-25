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
	virtual bool inserta(Object* data, int position) override;
	virtual bool suprime(int)override;
	virtual void anula();
	virtual Object* recupera(int)override;
	virtual Object* anterior(int)override;
	virtual Object* siguiente(int)override;
	virtual void imprimeLista()override;
	virtual int localiza(Object*)override;
	virtual bool vacia()override;
	
};

