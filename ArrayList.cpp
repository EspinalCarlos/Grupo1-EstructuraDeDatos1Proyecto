#include "ArrayList.h"
#include <string>
#include <array>
using namespace std;

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
	}
	else if (position >= 0 || position < capacidad && size == capacidad) {

	}
	else {
		return false;
	}
}




