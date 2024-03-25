#include "ArrayList.h"
#include <string>
#include <array>
#include <iostream>
using namespace std;

//Constructor de la clase ArrayList, tiene una capacidad predeterminada de 100
ArrayList::ArrayList() {
	this->capacidad = 100;
	this->size = 0;
	this->arr = new Object*[capacidad];
	
}
//Destructor de la clase: recorre el arreglo del ArrayList, liberado toda la memoria usada por este
ArrayList::~ArrayList() {
	for (int i = 0; i < this->size; i++) {
		delete this->arr[i];
	}
	delete this->arr;
}
//Metodo Suprimir: borra el objeto de la posicion especificada y hace los corrimientos necesarios
bool ArrayList::suprime(int position){
	if (position > 0 || position < size && !vacia()){
		delete this->arr[position-1];
		for (size_t i = position-1; i < size-1; i++){
			if(arr[i+1] != NULL)
				this->arr[i] = this->arr[i+1];

		}
		this->size--;
		return true;
		
	}
	else {
		return false;
	}
	
}
//Metodo de insecion a la lista, validado por si esta lleno el arreglo, inserta en la posicion especificada y corre los elementos para la derecha de ser necesario
bool ArrayList::inserta(Object* data, int position) {
	if (position >= 0 && position < capacidad && size != capacidad){
		for (int i = size+1; i >= position-1; i--){
			
				this->arr[i] = this->arr[i-1];
				
			
		}
		this->arr[position-1] = data;
		this->size++;
		return true;
	}
	else if (position >= 0 && position < capacidad && size == capacidad) {
		Object** temp = new Object*[capacidad+1];
		for (size_t i = 0; i < capacidad+1; i++){
			if (i != position-1 && i < position-1){
				temp[i] = this->arr[i];
			}
			else if(i == position-1){
				temp[i] = this->arr[i];
			}
			else {
				temp[i] = this->arr[i - 1];
			}
		}
		this->size++;
		anula();
		this->arr = temp;
		return true;
	}
	else {
		return false;
	}
}

//recorre el arreglo e imprime los objetos que tiene dentro cada espacio
void ArrayList::imprimeLista() {
	for (int i = 0; i < size; i++){
		if (i != size)
			cout << '[' << this->arr[i]->toString() << ']';
		
	}
}
//Verifica si el arreglo esta vacio, retorna un booleano falso si no esta vacia, de lo contrario, retorna verdadero
bool ArrayList::vacia() {
	if (size > 0)
		return false;
	else
		return true;
}
//Recorre el arreglo y libera la memoria de todos los elementos
void ArrayList::anula() {
	for (int i = 0; i < this->size; i++) {
		delete this->arr[i];
	}
	this->size = 0;
}
//recupera el objeto localizado en la posicion recibida por la funcion
Object* ArrayList::recupera(int position) {
	if (position > 0 || position < size){
		return this->arr[position - 1];
	}
}
//recupera el objeto una posicion atras al especificado por la funcion
Object* ArrayList::anterior(int position) {
	if (position > 1 || position <= size) {
		return this->arr[(position - 1)-1];
	}
}
//recupera el objeto una posicion delante al especificado por la funcion
Object* ArrayList::siguiente(int position) {
	if (position > 0 || position <= size - 1) {
		return this->arr[(position - 1) + 1];
	}
}
//Recorre el arreglo, comparando los datos con el que recibe la funcion, cuando encuentra uno igual, retorna el indice en el cual esta
int ArrayList::localiza(Object* dato) {
	int index = -1;
	for (size_t i = 0; i < this->size; i++){
		if (dato->equals(this->arr[i])){
			index = i;
		}
	}
	return index+1;
}
int ArrayList::getCapacidad() {
	return this->capacidad;
}





