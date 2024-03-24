#pragma once
#include "Object.h"
#include <string>
class TDALista {
protected:
	int size;
public:
	virtual bool inserta(Object* data, int position)=0;
	virtual bool suprime(int)=0;
	virtual void anula()=0;
	virtual Object* recupera(int)=0;
	virtual Object* anterior(int)=0;
	virtual Object* siguiente(int)=0;
	virtual void imprimeLista()=0;
	virtual int localiza(Object*)=0;
	virtual bool vacia()=0;
	virtual void append(Object*)=0;
	virtual int getSize() { return this->size; }

};

