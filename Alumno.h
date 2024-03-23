#include<iostream>
#include"Object.h"
#include <string>

using namespace std;

class Alumno: public Object{
private:
    string nombreAlumno;
    string numeroCuenta;

public:
    Alumno(string name, string accNumber);
    ~Alumno();
    virtual bool equals(Object*)override;
    virtual string toString()override;
    string getNombre();
    string getNumeroCuenta();
};