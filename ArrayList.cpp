#include "ArrayList.h"
#include <string>
#include <array>
#include <iostream>
using namespace std;

//Constructor de la clase ArrayList, tiene una capacidad predeterminada de 10
ArrayList::ArrayList() {
	this->capacidad = 10;
	this->arr = new Object*[capacidad];
}
ArrayList::~ArrayList() {
	for (int i = 0; i < this->size; i++) {
		delete this->arr[i];
	}
	delete this->arr;
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

void ArrayList::imprimeLista() {
	for (int i = 0; i < size; i++){
		if (i != size)
			cout << '[' << this->arr[i] << ', ';
		else
			cout << this->arr[i] << "] ";
		
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
}




