#include "Alumno.h"
#include<string>
#include<iostream>
#include <array>

Alumno::Alumno(string name, int accNum){
    this->nombreAlumno = name; 
    this->numeroCuenta = accNum;
}

Alumno::~Alumno(){}

string Alumno::getNombre(){
    return this->nombreAlumno;
}
int Alumno::getNumeroCuenta(){
    return this->numeroCuenta;
}
