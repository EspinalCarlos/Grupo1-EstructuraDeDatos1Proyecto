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

const string red = "\033[1;31m";
const string green = "\033[1;32m";
const string l_blue = "\033[1;36m";
const string yellow = "\033[1;33m";
const string purple = "\033[1;35m";
const string white = "\033[0m";

void menuPilas() {
    bool fin = true;

    cout << l_blue << "---------Stack---------" << endl;

    do {
        cout << l_blue << "1. Trabajar con ArrayStack \n"
            << "2. Trabajar con LinkedStacked \n"
            << "3. Regresar al Menu Principal \n";

        int seleccion = 0;
        cin >> seleccion;

        if (seleccion == 1) {
            ArrayStack* pila = new ArrayStack();
            bool salir1 = true;
            do {
                cout << purple << "Operaciones del Stack: \n"
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
                    cout << purple << "Ingrese un caracter: ";
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
                cout << purple << "Operaciones del Stack: \n"
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
                    cout << purple << "Ingrese un caracter: ";
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
            cout << white << "---------" << endl;
            fin = false;
        }
        else {
            cout << red << "Opcion no valida" << endl;
        }

    } while (fin);
}

void menuPrincipal(){
    cout << yellow << "---- MENU PRINCIPAL ----\n\n1.Trabajar con Listas\n2.Trabajar con Pilas\n3. Trabajar con Colas\n4. Salir\n\n";
}

void menuListas(){
    cout << purple << "---- Operaciones con Listas ----\n\n1. Insertar Elemento\n2.Imprimir Elementos\n3.Buscar Elemento\n4. Borrar Elemento\n5. Ver si esta vacia\n6. Obtener elemento por posicion\n7. Obtener Siguiente\n8. Obtener Anterior\n9. Borrar todos los elementos de la lista\n10. Regresar al menu anterior ";
}

void menuColas() {
    int opQ;
    TDACola* cola = nullptr;
    cout << l_blue << "Menu Tipo de Cola\n\n1. Trabajar con ArrayQueue\n2. Trabajar con LinkedQueue\n3. Regresar al Menu Principal" << endl;
    cin >> opQ;
    switch (opQ) {
    case 1:
        cola = new ArrayQueue();
        break;
    case 2:
        cola = new LinkedQueue();
        break;
    case 3:
        break;
    default:
        cout << red << "OPCION INGRESADA NO VALIDA: INGRESE UN NUMERO VALIDO" << endl;
        break;
    }
    if (opQ == 1 || opQ == 2) {
        int opSubMenuQ;
        string nombre;
        string numC;
        Alumno* a = nullptr;
        Object* temp = nullptr;
        do {
            cout << purple << "Operaciones de Colas\n\n1. Encolar\n2. Desencolar\n3. Ver Frente\n4. Verificar si esta vacia\n5. Imprimir Elementos\n6. Borrar los elementos\n7. Regresar al Menu Anterior" << endl;
            cin >> opSubMenuQ;
            switch (opSubMenuQ) {
            case 1:
                cout << purple << "Ingrese el nombre completo del alumno: " << endl;
                cin >> nombre;
                cout << purple << "Ingrese el numero de cuenta del alumno: " << endl;
                cin >> numC;
                a = new Alumno(nombre, numC);
                cola->queue(a);
                break;
            case 2:
                temp = cola->dequeue();
                if (temp == nullptr) {
                    cout << red << "La cola esta vacia" << endl;
                }
                else {
                    a = dynamic_cast<Alumno*>(temp);
                    cout << green << "El primer elemento en la cola es: " + a->toString() + " y se ha quitado de la cola" << endl;
                }                 
                break;
            case 3:
                temp = cola->peek();
                if (temp == nullptr) {
                    cout << red << "La cola esta vacia" << endl;
                }
                else {
                    a = dynamic_cast<Alumno*>(temp);
                    cout << green << "El primer elemento en la cola es: " + a->toString() << endl;
                }      
                break;
            case 4:
                if (cola->isEmpty()) {
                    cout << green << "La cola esta vacia" << endl;
                }
                else {
                    cout << red << "La cola no esta vacia" << endl;
                }
                break;
            case 5:
                cola->printQueue();
                break;
            case 6:
                cola->clear();
                break;
            case 7:
                cout << white << "Regresando al menu ... \n\n" << endl;
                break;
            default:
                cout << red << "OPCION INGRESADA NO VALIDA: INGRESE UN NUMERO VALIDO" << endl;
                break;
            }
        } while (opSubMenuQ != 7);
        if (a != nullptr) {
            delete a;
        }
        if (cola != nullptr) {
            delete cola;
        }
        if (temp != nullptr) {
            delete temp;
        }
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
            cout << l_blue << "--- Menu Tipo Lista ---\n\n1. Array List\n2. Linked List\n\n Ingrese su opcion: ";
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
                        cout << purple << "--- Insertar Alumno a la Lista ---\nIngrese el nombre completo del Alumno: ";
                        cin.clear();
                        cin.ignore();
                        getline(cin, nombreA);
                        cout << purple << "\nIngrese el numero de cuenta del alumno: ";
                        getline(cin, numeroC);
                        cout << endl;
                        a = new Alumno(nombreA, numeroC);
                        cout << purple << "\nIngrese el indice al que desea insertar el alumno: ";
                        cin >> indiceInsert;
                        cout << endl;
                        if (indiceInsert <= lista->getSize()+1 && indiceInsert > 0) {
                            lista->inserta(a, indiceInsert);
                        }
                        else {
                            while (indiceInsert > lista->getSize()+1 || indiceInsert <= 0) {
                                cout << red << "Indice invalido porfavor ingrese un indice valido: ";
                                cin >> indiceInsert;
                            }
                            lista->inserta(a, indiceInsert);
                        }
                        cout << green << "\nAlumno insertado a la lista correctamente\n";
                        cout << green << "\nDesea agregar otro alumno a la lista? (1.si 0. no): ";
                        cin >> addLoop;
                        cout << endl;


                    } while (addLoop != 0);
                    break;
                case 2:
                    cout << purple << "\n--- Impresion de Lista --- \n";
                    if (!lista->vacia())
                        lista->imprimeLista();
                    else
                        cout << red << "La lista esta vacia.";
                    break;
                case 3:
                    cout << purple << "\n--- Busqueda en la Lista ---\n";
                    cout << purple << "Ingrese el numero de cuenta del estudiante: ";
                    cin >> numeroC;
                    localizaNum = lista->localiza(new Alumno("", numeroC));
                    if (localizaNum != 0)
                        cout << endl << purple << "\nNombre del estudiante: " << dynamic_cast<Alumno*>(lista->recupera(lista->localiza(new Alumno("", numeroC))))->getNombre() << " Indice: " << lista->localiza(new Alumno("", numeroC)) << endl;
                    else
                        cout << red << "No existe alumno con tal numero\n\n";
                    break;
                case 4:
                    cout << purple << "\n--- Eliminacion en la Lista ---\n" << "Ingrese la posicion del alumno en la lista el cual desea eliminar: ";
                    cin >> indiceDelete;
                    if (lista->getSize() > 0 && indiceDelete <= lista->getSize()) {
                        lista->suprime(indiceDelete);
                        cout << green << "Alumno eliminado correctamente";
                    }
                    else if (lista->vacia()) {
                        cout << red << "No se pudo eliminar el alumno: LISTA VACIA";
                    }
                    else {
                        do {
                            cout << red << "No se pudo eliminar el alumno: INDICE INCORRECTO";
                            cin >> indiceDelete;

                        } while (indiceDelete > lista->getSize() || indiceDelete < 0);
                        lista->suprime(indiceDelete); 
                    }
                    break;
                case 5:
                    cout << purple << "\n--- Ver si esta vacia la lista ---";
                    if (!lista->vacia()){
                        cout << red << "\nLa lista no esta vacia, contiene " << lista->getSize() << " alumnos\n";
                    }
                    else {
                        cout << green << "\nLa lista esta vacia.\n";
                    }
                    break;
                case 6:
                    cout << purple << "\n--- Obtener alumno ingresando indice ---\n";
                    cout << purple << "Ingrese el indice que desea obtener: ";
                    cin >> indicePORINDEX;
                    if (indicePORINDEX > 0 && indicePORINDEX < lista->getSize())
                        cout << purple << "Nombre del Alumno: " << dynamic_cast<Alumno*>(lista->recupera(indicePORINDEX))->getNombre() << " Numero de Cuenta: " << dynamic_cast<Alumno*>(lista->recupera(indicePORINDEX))->getNumeroCuenta() << endl;
                    else
                        cout << red << "Indice invalido";

                    break;
                case 7:
                    cout << purple << "\n--- Obtener siguiente de un indice ---\n";
                    cout << purple << "Ingrese el indice que desea obtener: ";
                    cin >> indicePORINDEX;
                    cout << endl;
                    if (indicePORINDEX > 0 && indicePORINDEX <= lista->getSize()-1)
                        cout << purple << "Nombre del Alumno: " << dynamic_cast<Alumno*>(lista->siguiente(indicePORINDEX))->getNombre() << " Numero de Cuenta: " << dynamic_cast<Alumno*>(lista->siguiente(indicePORINDEX))->getNumeroCuenta() << endl;
                    else
                        cout << red << "Indice invalido";
                    break;
                case 8:
                    cout << purple << "\n--- Obtener anterior de un indice ---\n";
                    cout << purple << "Ingrese el indice que desea obtener: ";
                    cin >> indicePORINDEX;
                    if (indicePORINDEX > 1 && indicePORINDEX <= lista->getSize())
                        cout << purple << "Nombre del Alumno: " << dynamic_cast<Alumno*>(lista->anterior(indicePORINDEX))->getNombre() << " Numero de Cuenta: " << dynamic_cast<Alumno*>(lista->anterior(indicePORINDEX))->getNumeroCuenta() << endl;
                    else
                        cout << red << "Indice invalido";
                    break;
                case 9:
                    cout << purple << "\n--- Nulificacion de toda la lista ---\n";
                    if (!lista->vacia()){
                        lista->anula();
                        cout << green << "\nLista anulada correctamente\n";
                    }
                    else {
                        cout << red << "\nLa lista esta vacia, no hay nada que anular\n";
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


