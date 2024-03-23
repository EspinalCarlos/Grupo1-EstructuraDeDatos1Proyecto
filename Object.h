#pragma once
#include <string>
using namespace std;
class Object{
public:
	//funcion que recibe otro objeto como parametro y se compara el objeto con el cual se llamo la funcion, retorna un boolean si es o no es igual
	virtual bool equals(Object*) = 0;
	//funcion que retorna representacion en cadena de el objeto
	virtual string toString() = 0;

};

