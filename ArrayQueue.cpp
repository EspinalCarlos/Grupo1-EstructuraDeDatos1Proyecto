#include "ArrayQueue.h"
#include <string>
#include <iostream>
using namespace std;

ArrayQueue::ArrayQueue() { //inicializacion del ArrayQueue con su constructor
	queueList = new Object * [max_size];
	index_last = 0;
}

ArrayQueue::~ArrayQueue() { //destructor del ArrayQueue
	delete[] queueList;
}
//encola, que agrega un elemento a la cola y extiende el tam del arreglo si se llena antes de meter el objeto ingresado
void ArrayQueue::queue(Object* element) { 
	if (index_last == max_size) {
		int prev_size = max_size;	//guarda el tam viejo del arreglo antes de expandirlo
		max_size = max_size * 2;
		Object** temp = new Object * [max_size];
		for (int i = 0; i < prev_size; i++) {
			temp[i] = queueList[i];
		}
		queueList = temp;
		delete[] temp;
	}
	queueList[index_last] = element;
	index_last++;
}

//desencolar, que retorna un puntero nulo si el arreglo esta vacio, de lo contrario desencola y luego corre los objetos en la cola
Object* ArrayQueue::dequeue() {
	if (index_last == 0) {
		return nullptr;
	}
	else {
		Object* element = queueList[0];
		queueList[0] == nullptr;
		for (int i = 0; i < index_last; i++) {
			queueList[i] = queueList[i + 1];
		}
		index_last--;
		return element;
	}
}
//ver frente, que retorna un puntero nulo si el arreglo esta vacio, de lo contrario retorna el primer objeto en la cola
Object* ArrayQueue::peek() {
	if (index_last == 0) {
		return nullptr;
	}
	return queueList[0];
}
//isEmpty, que retorna true o false dependiendo de si hay un objeto no nulo en el arreglo
bool ArrayQueue::isEmpty() {
	for (int i = 0; i < index_last; i++) {
		if (&queueList[0] != nullptr) {
			return false;
		}
	}
	return true;
}
//limpiar, que elimina la cola y la vuelve a inicializar
void ArrayQueue::clear() {
	index_last = 0;
	delete[] queueList;
	queueList = new Object * [max_size];
}
//imprimir, que solo recorre la cola e imprime los toString correspondientes
void ArrayQueue::printQueue() {
	if (index_last > 0) {
		for (int i = 0; i < index_last; i++) {
			cout << queueList[i]->toString();
			if (i != index_last - 1) {
				cout << ", ";
			}
		}
	}
	else {
		cout << "La cola esta vacia" << endl;
	}
	cout << endl;
}