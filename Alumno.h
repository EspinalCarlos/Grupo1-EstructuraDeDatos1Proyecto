#include<iostream>
#include"Object.h"
#include <string>

using namespace std;

class Alumno: public Object{
private:
    string nombreAlumno;
    int numeroCuenta;

public:
    Alumno(string name, int accNumber);
    ~Alumno();
    string getNombre();
    int getNumeroCuenta();
};