#include "ArrayList.h"
#include <string>
#include <array>
#include <iostream>
using namespace std;

//Constructor de la clase ArrayList, tiene una capacidad predeterminada de 10
ArrayList::ArrayList() {
	this->capacidad = 100;
	this->size = 0;
	this->arr = new Object*[capacidad];
	
}
ArrayList::~ArrayList() {
	for (int i = 0; i < this->size; i++) {
		delete this->arr[i];
	}
	delete this->arr;
}

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

bool ArrayList::inserta(Object* data, int position) {
	if (position >= 0 || position < capacidad && size != capacidad){
		for (int i = size; i > position; i--){
			this->arr[i + 1] = this->arr[i];
		}
		this->arr[position - 1] = data;
		this->size++;
		return true;
	}
	else if (position >= 0 || position < capacidad && size == capacidad) {
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

void ArrayList::append(Object* data) {
	if (size < capacidad){
		this->arr[size - 1] = data; \
		size++;
	}
	else if (size >= capacidad) {
		Object** temp = new Object* [capacidad + 1];
		for (size_t i = 0; i < capacidad+1; i++){
			if (i != (capacidad + 1) - 1) {
				this->arr[i] = temp[i];
			}
			else if(i == (capacidad+1)-1){
				this->arr[i] = data;
			}
		}
		capacidad++;
		size++;
		anula();
		this->arr = temp;
	}
}
void ArrayList::imprimeLista() {
	for (int i = 0; i < size; i++){
		if (i != size)
			cout << '[' << this->arr[i]->toString() << ']';
		
	}
}
bool ArrayList::vacia() {
	if (size > 0)
		return false;
	else
		return true;
}
void ArrayList::anula() {
	for (int i = 0; i < this->size; i++) {
		delete this->arr[i];
	}
	this->size = 0;
}

Object* ArrayList::recupera(int position) {
	if (position > 0 || position < size){
		return this->arr[position - 1];
	}
}

Object* ArrayList::anterior(int position) {
	if (position > 1 || position <= size) {
		return this->arr[(position - 1)-1];
	}
}

Object* ArrayList::siguiente(int position) {
	if (position > 0 || position <= size - 1) {
		return this->arr[(position - 1) + 1];
	}
}

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





