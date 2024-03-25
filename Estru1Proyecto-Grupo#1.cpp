﻿
#include <iostream>
using namespace std;

#include "Object.h"
#include "TDALista.h"
#include "ArrayList.h"
#include "Alumno.h"
#include <string>
#include "TDACola.h"
#include "ArrayQueue.h"
#include "LinkedList.h"
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include "ArrayStack.h"


void menuPilas() {
    bool fin = true;

    cout << "---------Stack---------" << endl;

    do {
        cout << "1. Trabajar con ArrayStack \n"
            << "2. Trabajar con LinkedStacked \n"
            << "3. Regresar al Menu Principal \n";

        int seleccion = 0;
        cin >> seleccion;

        if (seleccion == 1) {
            ArrayStack* pila = new ArrayStack();
            bool salir1 = true;
            do {
                cout << "Operaciones del Stack: \n"
                    << "1. Push \n"
                    << "2. Pop \n"
                    << "3. Peek \n"
                    << "4. IsEmpty \n"
                    << "5. PrintStack \n"
                    << "6. Vaciar \n"
                    << "7. Salir" << endl;
                int seleccion1 = 0;
                cin >> seleccion1;

                switch (seleccion1) {
                case 1: {
                    cout << "Ingrese un caracter: ";
                    char linea;
                    cin >> linea;
                    char* c = &linea;
                    pila->push(c);
                    break;
                }

                case 2:
                    pila->pop();
                    break;

                case 3:
                    pila->peek();
                    break;

                case 4:
                    pila->isEmpty();
                    break;

                case 5:
                    pila->printStack();
                    break;

                case 6:
                    pila->vaciar();
                    break;

                case 7:
                    salir1 = false;
                    break;

                default:
                    break;
                }
            } while (salir1);

            delete pila;

        }
        else if (seleccion == 2) {
            LinkedStack* pila = new LinkedStack();
            bool salir2 = true;
            do {
                cout << "Operaciones del Stack: \n"
                    << "1. Push \n"
                    << "2. Pop \n"
                    << "3. Peek \n"
                    << "4. IsEmpty \n"
                    << "5. PrintStack \n"
                    << "6. Vaciar \n"
                    << "7. Salir" << endl;
                int seleccion2 = 0;
                cin >> seleccion2;

                switch (seleccion2) {
                case 1: {
                    cout << "Ingrese un caracter: ";
                    char linea;
                    cin >> linea;
                    char* c = &linea;
                    pila->push(c);
                    break;
                }

                case 2:
                    pila->pop();
                    break;

                case 3:
                    pila->peek();
                    break;

                case 4:
                    pila->isEmpty();
                    break;

                case 5:
                    pila->printStack();
                    break;

                case 6:
                    pila->vaciar();
                    break;

                case 7:
                    salir2 = false;
                    break;

                default:
                    break;
                }
            } while (salir2);

            delete pila;

        }
        else if (seleccion == 3) {
            cout << "---------" << endl;
            fin = false;
        }
        else {
            cout << "Opci�n no v�lida" << endl;
        }

    } while (fin);
}


void menuPrincipal(){
    cout << "---- MENU PRINCIPAL ----\n\n1.Trabajar con Listas\n2.Trabajar con Pilas\n3. Trabajar con Colas\n4. Salir\n\n";
}
void menuListas(){
    cout << "---- Operaciones con Listas ----\n\n1. Insertar Elemento\n2.Imprimir Elementos\n3.Buscar Elemento\n4. Borrar Elemento\n5. Ver si esta vacia\n6. Obtener elemento por posicion\n7. Obtener Siguiente\n8. Obtener Anterior\n9. Borrar todos los elementos de la lista\n10. Regresar al menu anterior ";
}

void menuColas() {
    int opQ;
    TDACola* cola = nullptr;
    cout << "Menu Tipo de Cola\n\n1. Trabajar con ArrayQueue\n2. Trabajar con LinkedQueue\n3. Regresar al Menu Principal" << endl;
    cin >> opQ;
    switch (opQ) {
    case 1:
        cola = new ArrayQueue();
        break;
    case 2:
        cola = new LinkedQueue();
        break;
    default:
        cout << "OPCION INGRESADA NO VALIDA: INGRESE UN NUMERO VALIDO" << endl;
        break;
    }
    if (opQ == 1 || opQ == 2) {
        int opSubMenuQ;
        string nombre;
        string numC;
        Alumno* a = nullptr;
        Object* temp = nullptr;
        do {
            cout << "Operaciones de Colas\n\n1. Encolar\n2. Desencolar\n3. Ver Frente\n4. Verificar si esta vacia\n5. Imprimir Elementos\n6. Borrar los elementos\n7. Regresar al Menu Anterior" << endl;
            cin >> opSubMenuQ;
            switch (opSubMenuQ) {
            case 1:
                cout << "Ingrese el nombre completo del alumno: " << endl;
                cin >> nombre;
                cout << "Ingrese el numero de cuenta del alumno: " << endl;
                cin >> numC;
                a = new Alumno(nombre, numC);
                cola->queue(a);
                delete a;
                break;
            case 2:
                temp = cola->dequeue();
                if (temp == nullptr) {
                    cout << "La cola esta vacia" << endl;
                }
                else {
                    a = dynamic_cast<Alumno*>(temp);
                    cout << "El primer elemento en la cola es: " + a->toString() + " y se ha quitado de la cola" << endl;
                    delete a;
                    delete temp;
                }                 
                break;
            case 3:
                temp = cola->peek();
                if (temp == nullptr) {
                    cout << "La cola esta vacia" << endl;
                }
                else {
                    a = dynamic_cast<Alumno*>(temp);
                    cout << "El primer elemento en la cola es: " + a->toString() << endl;
                    delete a;
                    delete temp;
                }      
                break;
            case 4:
                if (cola->isEmpty()) {
                    cout << "La cola esta vacia" << endl;
                }
                else {
                    cout << "La cola no esta vacia" << endl;
                }
                break;
            case 5:
                cola->printQueue();
                break;
            case 6:
                cola->clear();
                break;
            case 7:
                cout << "Regresando al menu ... \n\n" << endl;
                delete cola;
                break;
            default:
                cout << "OPCION INGRESADA NO VALIDA: INGRESE UN NUMERO VALIDO" << endl;
                break;
            }
        } while (opSubMenuQ != 7);
    }
}

int main(int argc, const char* argv[]){
    int opcionMM,opcionLists,opcionListsP,addLoop, indiceInsert, localizaNum, indiceDelete, indicePORINDEX;
    TDALista* lista = NULL;
    do{
        string nombreA;
        string numeroC;
        Alumno* a;
        menuPrincipal();
        cin >> opcionMM;
        switch (opcionMM){
        case 1:
            cout << "--- Menu Tipo Lista ---\n\n1. Array List\n2. Linked List\n\n Ingrese su opcion: ";
            cin >> opcionListsP;
           switch(opcionListsP){
                case 1:
                    lista = new ArrayList();
                    break;
                case 2:
                    lista = new LinkedList();
                    break;
           } 
            
           
            do {
                menuListas();
                cout << endl;
                cin >> opcionLists;
                switch (opcionLists) {
                case 1:
                    do {
                        cout << "--- Insertar Alumno a la Lista ---\nIngrese el nombre completo del Alumno: ";
                        cin.clear();
                        cin.ignore();
                        getline(cin, nombreA);
                        cout << "\nIngrese el numero de cuenta del alumno: ";
                        getline(cin, numeroC);
                        cout << endl;
                        a = new Alumno(nombreA, numeroC);
                        cout << "\nIngrese el indice al que desea insertar el alumno: ";
                        cin >> indiceInsert;
                        cout << endl;
                        if (indiceInsert <= lista->getSize()+1 && indiceInsert > 0) {
                            lista->inserta(a, indiceInsert);
                        }
                        else {
                            while (indiceInsert > lista->getSize()+1 || indiceInsert <= 0) {
                                cout << "Indice invalido porfavor ingrese un indice valido: ";
                                cin >> indiceInsert;
                            }
                            lista->inserta(a, indiceInsert);
                        }
                        cout << "\nAlumno insertado a la lista correctamente\n";
                        cout << "\nDesea agregar otro alumno a la lista? (1.si 0. no): ";
                        cin >> addLoop;
                        cout << endl;


                    } while (addLoop != 0);
                    break;
                case 2:
                    cout << "\n--- Impresion de Lista --- \n";
                    if (!lista->vacia())
                        lista->imprimeLista();
                    else
                        cout << "La lista esta vacia.";
                    break;
                case 3:
                    cout << "\n--- Busqueda en la Lista ---\n";
                    cout << "Ingrese el numero de cuenta del estudiante: ";
                    cin >> numeroC;
                    localizaNum = lista->localiza(new Alumno("", numeroC));
                    if (localizaNum != 0)
                        cout << endl << "\nNombre del estudiante: " << dynamic_cast<Alumno*>(lista->recupera(lista->localiza(new Alumno("", numeroC))))->getNombre() << " Indice: " << lista->localiza(new Alumno("", numeroC)) << endl;
                    else
                        cout << "No existe alumno con tal numero\n\n";
                    break;
                case 4:
                    cout << "\n--- Eliminacion en la Lista ---\n" << "Ingrese la posicion del alumno en la lista el cual desea eliminar: ";
                    cin >> indiceDelete;
                    if (lista->getSize() > 0 && indiceDelete <= lista->getSize()) {
                        lista->suprime(indiceDelete);
                        cout << "Alumno eliminado correctamente";
                    }
                    else if (lista->vacia()) {
                        cout << "No se pudo eliminar el alumno: LISTA VACIA";
                    }
                    else {
                        do {
                            cout << "No se pudo eliminar el alumno: INDICE INCORRECTO";
                            cin >> indiceDelete;

                        } while (indiceDelete > lista->getSize() || indiceDelete < 0);
                        lista->suprime(indiceDelete); 
                    }
                    break;
                case 5:
                    cout << "\n--- Ver si esta vacia la lista ---";
                    if (!lista->vacia()){
                        cout << "\nLa lista no esta vacia, contiene " << lista->getSize() << " alumnos\n";
                    }
                    else {
                        cout << "\nLa lista esta vacia.\n";
                    }
                    break;
                case 6:
                    cout << "\n--- Obtener alumno ingresando indice ---\n";
                    cout << "Ingrese el indice que desea obtener: ";
                    cin >> indicePORINDEX;
                    if (indicePORINDEX > 0 && indicePORINDEX < lista->getSize())
                        cout << "Nombre del Alumno: " << dynamic_cast<Alumno*>(lista->recupera(indicePORINDEX))->getNombre() << " Numero de Cuenta: " << dynamic_cast<Alumno*>(lista->recupera(indicePORINDEX))->getNumeroCuenta() << endl;
                    else
                        cout << "Indice invalido";

                    break;
                case 7:
                    cout << "\n--- Obtener siguiente de un indice ---\n";
                    cout << "Ingrese el indice que desea obtener: ";
                    cin >> indicePORINDEX;
                    cout << endl;
                    if (indicePORINDEX > 0 && indicePORINDEX <= lista->getSize()-1)
                        cout << "Nombre del Alumno: " << dynamic_cast<Alumno*>(lista->siguiente(indicePORINDEX))->getNombre() << " Numero de Cuenta: " << dynamic_cast<Alumno*>(lista->siguiente(indicePORINDEX))->getNumeroCuenta() << endl;
                    else
                        cout << "Indice invalido";
                    break;
                case 8:
                    cout << "\n--- Obtener anterior de un indice ---\n";
                    cout << "Ingrese el indice que desea obtener: ";
                    cin >> indicePORINDEX;
                    if (indicePORINDEX > 1 && indicePORINDEX <= lista->getSize())
                        cout << "Nombre del Alumno: " << dynamic_cast<Alumno*>(lista->anterior(indicePORINDEX))->getNombre() << " Numero de Cuenta: " << dynamic_cast<Alumno*>(lista->anterior(indicePORINDEX))->getNumeroCuenta() << endl;
                    else
                        cout << "Indice invalido";
                    break;
                case 9:
                    cout << "\n--- Nulificacion de toda la lista ---\n";
                    if (!lista->vacia()){
                        lista->anula();
                        cout << "\nLista anulada correctamente\n";
                    }
                    else {
                        cout << "\nLa lista esta vacia, no hay nada que anular\n";
                    }
                    break;
                case 10:
                    delete lista;
                    break;
                default:
                    break;
                }
            } while (opcionLists != 10);

            break;
        case 2:
            menuPilas();
            break;
        case 3:
            menuColas();
        }    
    }while(opcionMM != 4);
}


