#include "Alumno.h"
#include<string>
#include<iostream>
#include <array>
using namespace std;
//Consturctor de la clase Alumno, solo tiene el nombre y el numero de cuenta ya que es lo unico que tiene la clase
Alumno::Alumno(string name, string accNum){
    this->nombreAlumno = name; 
    this->numeroCuenta = accNum;
}

Alumno::~Alumno(){}

string Alumno::getNombre(){
    return this->nombreAlumno;
}
string Alumno::getNumeroCuenta() {
    return this->numeroCuenta;
}

bool Alumno::equals(Object* obj) {
    if (this == dynamic_cast<Alumno*>(obj)){
        return true;
    }
    else {
        return false;
    }
}

string Alumno::toString() {
    return numeroCuenta;
}

