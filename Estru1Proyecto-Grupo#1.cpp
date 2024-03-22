
#include <iostream>
using namespace std;

#include "Object.h"
#include "TDALista.h"
#include "ArrayList.h"
#include <string>



void menuPrincipal(){
    cout << "---- MENU PRINCIPAL ----\n\n1.Trabajar con Listas\n2.Trabajar con Pilas\n3. Trabajar con Colas\n4. Salir\n\n";
}
void menuListas(){
    cout << "---- Operaciones con Listas ----\n\n1. Insertar Elemento\n2.Imprimir Elementos\n3.Buscar Elemento\n4. Borrar Elemento\n5. Ver si esta vacia\n6. Obtener elemento por posicion\n7. Obtener Siguiente\n8. Obtener Anterior\n9. Borrar todos los elementos de la lista\n10. Regresar al menu anterior ";
}

int main(){
    int opcionMM,opcionLists,opcionListsP;
    TDALista* lista = NULL;
    
    do{
        string nombreA;

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
                    
                    break;
           } 
            
            menuListas();
            cin >> opcionLists;
            switch (opcionLists)
            {
            case 1:
                cout << "--- Insertar Alumno a la Lista ---\nIngrese el nombre completo del Alumno: ";

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
            
                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:

                break;
            default:
                break;
            }


            break;
        
        default:
            cout << "Opcion Invalida, vuelva a intentarlo";
        }    
    }while(opcionMM != 4);
    
}


