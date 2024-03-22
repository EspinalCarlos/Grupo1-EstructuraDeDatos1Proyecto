#pragma once
#include "Object.h"
#include <string>
class TDALista : public Object {
protected:
	int size;
public:
	virtual bool inserta(Object* data, int position);
	virtual bool suprime(int) ;
	virtual void anula() ;
	virtual Object* recupera(int) ;
	virtual Object* anterior(int) ;
	virtual Object* siguiente(int) ;
	virtual void imprimeLista() ;
	virtual int localiza(Object*) ;
	virtual bool vacia() ;
	virtual void append(Object*) ;

};

