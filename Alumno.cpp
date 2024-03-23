#include "Alumno.h"
#include<string>
#include<iostream>
#include <array>

//Consturctor de la clase Alumno, solo tiene el nombre y el numero de cuenta ya que es lo unico que tiene la clase
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
