
#include "ArrayStack.h"
using namespace std;

ArrayStack::ArrayStack() {
    capacidad = capacidadInicial;
    stackArray = new char[capacidad];
    top = -1;
}

ArrayStack::~ArrayStack() {
    delete[] stackArray;
}
// Push: verifica si el array est� lleno, si lo est� crea un nuevo array con el doble del tama�o, luego suma un entero a la variable top y agrega el dato a la nueva posici�n de top*/
void ArrayStack::push(char* data) {
    if (top == capacidad - 1) {
        int nuevaCapacidad = capacidad * 2;
        char* nuevoArray = new char[nuevaCapacidad];
        for (int i = 0; i < capacidad; ++i) {
            nuevoArray[i] = stackArray[i];
        }
        delete[] stackArray;
        stackArray = nuevoArray;
        capacidad = nuevaCapacidad;
    }
    top++;
    char c = *data;
    stackArray[top] = c;
}
// Pop: Verifica si el array est� vac�o, luego reduce un entero a la variable top, volviendo inaccesible el dato superior en el array.
void ArrayStack::pop() {
    if (top == -1) {
        cout << "La pila esta vacia" << endl;
        cout << endl;
    }
    else {
        cout << "\nCaracter: " << stackArray[top] << "\n\n";
        top--;
    }
}
// Peek: imprime el contenido del array en la posici�n de top
void ArrayStack::peek() {
    if (top == -1) {
        cout << "La pila esta vacia" << endl;
    }
    else {
        cout << stackArray[top] << endl;
    }
    cout << endl;
}
// isEmpty: si top es igual a -1 imprime que el array est� vac�o, de lo contrario imprime que el array no est� vac�o
void ArrayStack::isEmpty() {
    if (top == -1) {
        cout << "La pila esta vacia" << endl;
    }
    else {
        cout << "La pila no esta vacia" << endl;
    }
    cout << endl;
}
// Print: verifica si el array est� vac�o, luego imprime el array si no est� vac�o.
void ArrayStack::printStack() {
    if (top == -1) {
        cout << "La pila esta vacia" << endl;
    }
    else {
        cout << "Pila: " << endl;
        for (int i = top; i >= 0; i--) {
            cout << stackArray[i] << endl;
        }
    }
}
// Vaciar: fuerza a top ser igual a -1 y crea un nuevo array con la capacidad inicial y lo establece como el array de uso.
void ArrayStack::vaciar() {
    top = -1;
}