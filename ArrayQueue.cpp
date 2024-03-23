#include "ArrayQueue.h"
#include <string>
#include <iostream>
using namespace std;

ArrayQueue::ArrayQueue() {
	queueList = new Object*[max_size];
	index_last = 0;
}

ArrayQueue::~ArrayQueue() {
	delete[] queueList;
}

void ArrayQueue::queue(Object* element) {
	if (index_last == max_size) {
		int prev_size = max_size;	//guarda el tam viejo del arreglo antes de expandirlo
		max_size = max_size * 2;
		Object** temp = new Object*[max_size];
		for (int i = 0; i < prev_size; i++) {
			temp[i] = queueList[i];
		}
		queueList = temp;
		delete[] temp;
	}
	queueList[index_last] = element;
	index_last++;
}

Object* ArrayQueue::dequeue() {
	if (index_last == 0) {
		return nullptr;
	}
	Object* element = queueList[index_last];
	for (int i = 0; i < index_last; i++) {
		queueList[i] = queueList[i + 1];
	}
	index_last--;
	return element;
}

Object* ArrayQueue::peek() {
	if (&queueList[0] == nullptr) {
		return nullptr;
	}
	return queueList[0];
}

bool ArrayQueue::isEmpty() {
	for (int i = 0; i < index_last; i++) {
		if (&queueList[0] != nullptr) {
			return false;
		}
	}
	return true;
}

void ArrayQueue::clear() {
	index_last = 0;
	delete[] queueList;
	queueList = new Object*[max_size];
}

void ArrayQueue::printQueue() {
	if (index_last > 0) {
		for (int i = 0; i < index_last; i++) {
			cout << queueList[i]->toString() << ", ";
		}
	}
	else {
		cout << "La cola esta vacia" << endl;
	}
}