#pragma once
#include <string>
#include"Object.h"
#include "TDALista.h"
class ArrayList: public TDALista{
public:
	ArrayList();
	~ArrayList();
	virtual bool inserta(Object* data, int position) ;
	virtual bool suprime(int);
	virtual void anula();
	virtual Object* recupera(int);
	virtual Object* anterior(int);
	virtual Object* siguiente(int);
	virtual void imprimeLista();
	virtual int localiza(Object*);
	virtual bool vacia();
	virtual void append(Object*);
	int getCapacidad();
protected:
	Object** arr;
	int capacidad;
};

