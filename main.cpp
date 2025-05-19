#include <iostream>
#include "lista.h"

using namespace std;

// Sobrecargas de la función imprimirNodo para cada tipo de lista
void imprimirNodo(nodo<int, float>* nodo) {
    if (nodo == NULL) {
        cout << "La posicion no existe" << endl;
    } else {
        cout << "Dato1: " << nodo->dato1 << ", Dato2: " << nodo->dato2 << endl;
    }
}

void imprimirNodo(nodo<int, char*>* nodo) {
    if (nodo == NULL) {
        cout << "La posicion no existe" << endl;
    } else {
        cout << "Dato1: " << nodo->dato1 << ", Dato2: " << nodo->dato2 << endl;
    }
}

void imprimirNodo(nodo<char, char*>* nodo) {
    if (nodo == NULL) {
        cout << "La posicion no existe" << endl;
    } else {
        cout << "Dato1: " << nodo->dato1 << ", Dato2: " << nodo->dato2 << endl;
    }
}

// Sobrecargas de la función imprimirLista para cada tipo de lista
void imprimirLista(Lista<int, float>& lista) {
    cout << "\nContenido completo de la lista (entero, float):" << endl;
    for (int i = 0; i < lista.getLongitud(); i++) {
        nodo<int, float>* nodo = lista.buscar_posicion(i);
        if (nodo != NULL) {
            cout << "Posicion " << i << " - ";
            imprimirNodo(nodo);
        }
    }
}

void imprimirLista(Lista<int, char*>& lista) {
    cout << "\nContenido completo de la lista (entero, string):" << endl;
    for (int i = 0; i < lista.getLongitud(); i++) {
        nodo<int, char*>* nodo = lista.buscar_posicion(i);
        if (nodo != NULL) {
            cout << "Posicion " << i << " - ";
            imprimirNodo(nodo);
        }
    }
}

void imprimirLista(Lista<char, char*>& lista) {
    cout << "\nContenido completo de la lista (char, string):" << endl;
    for (int i = 0; i < lista.getLongitud(); i++) {
        nodo<char, char*>* nodo = lista.buscar_posicion(i);
        if (nodo != NULL) {
            cout << "Posicion " << i << " - ";
            imprimirNodo(nodo);
        }
    }
}

int main() {
    cout << "LISTA 1: ENTERO Y REALES" << endl;
    Lista<int, float> lista1;

    cout << "Insertando 3 valores al inicio:" << endl;
    lista1.insertar_inicio(10, 1.1);
    lista1.insertar_inicio(20, 2.2);
    lista1.insertar_inicio(30, 3.3);

    cout << "Insertando 3 valores al final:" << endl;
    lista1.insertar_final(40, 4.4);
    lista1.insertar_final(50, 5.5);
    lista1.insertar_final(60, 6.6);

    cout << "Insertando 4 valores en posiciones especificas:" << endl;
    lista1.insertar_posicion(15, 1.5, 1);
    lista1.insertar_posicion(25, 2.5, 3);
    lista1.insertar_posicion(35, 3.5, 5);
    lista1.insertar_posicion(45, 4.5, 7);

    cout << "Buscando posicion 2:" << endl;
    nodo<int, float>* pos2 = lista1.buscar_posicion(2);
    imprimirNodo(pos2);

    cout << "Borrando posicion 2:" << endl;
    lista1.borrar_posicion(2);

    cout << "Buscando posicion 2 despues de borrar:" << endl;
    pos2 = lista1.buscar_posicion(2);
    imprimirNodo(pos2);

    cout << "Modificando posicion 3:" << endl;
    lista1.modificar_posicion(100, 10.1, 3);

    cout << "Buscando posicion 3 despues de modificar:" << endl;
    nodo<int, float>* pos3 = lista1.buscar_posicion(3);
    imprimirNodo(pos3);

    imprimirLista(lista1);

    cout << "\nLISTA 2: ENTERO Y STRINGS" << endl;
    Lista<int, char*> lista2;

    cout << "Insertando 3 valores al inicio:" << endl;
    lista2.insertar_inicio(1, (char*)"uno");
    lista2.insertar_inicio(2, (char*)"dos");
    lista2.insertar_inicio(3, (char*)"tres");

    cout << "Insertando 3 valores al final:" << endl;
    lista2.insertar_final(4, (char*)"cuatro");
    lista2.insertar_final(5, (char*)"cinco");
    lista2.insertar_final(6, (char*)"seis");

    cout << "Insertando 4 valores en posiciones especificas:" << endl;
    lista2.insertar_posicion(7, (char*)"siete", 1);
    lista2.insertar_posicion(8, (char*)"ocho", 3);
    lista2.insertar_posicion(9, (char*)"nueve", 5);
    lista2.insertar_posicion(10, (char*)"diez", 7);

    cout << "Buscando posicion 4:" << endl;
    nodo<int, char*>* pos4 = lista2.buscar_posicion(4);
    imprimirNodo(pos4);

    cout << "Borrando posicion 4:" << endl;
    lista2.borrar_posicion(4);

    cout << "Buscando posicion 4 despues de borrar:" << endl;
    pos4 = lista2.buscar_posicion(4);
    imprimirNodo(pos4);

    cout << "Modificando posicion 5:" << endl;
    lista2.modificar_posicion(100, (char*)"cien", 5);

    cout << "Buscando posicion 5 despues de modificar:" << endl;
    nodo<int, char*>* pos5 = lista2.buscar_posicion(5);
    imprimirNodo(pos5);

    imprimirLista(lista2);

    cout << "\nLISTA 3: CARACTER Y STRING" << endl;
    Lista<char, char*> lista3;

    cout << "Insertando 3 valores al inicio:" << endl;
    lista3.insertar_inicio('A', (char*)"uno");
    lista3.insertar_inicio('B', (char*)"dos");
    lista3.insertar_inicio('C', (char*)"tres");

    cout << "Insertando 3 valores al final:" << endl;
    lista3.insertar_final('D', (char*)"cuatro");
    lista3.insertar_final('E', (char*)"cinco");
    lista3.insertar_final('F', (char*)"seis");

    cout << "Insertando 4 valores en posiciones especificas:" << endl;
    lista3.insertar_posicion('G', (char*)"siete", 1);
    lista3.insertar_posicion('H', (char*)"ocho", 3);
    lista3.insertar_posicion('I', (char*)"nueve", 5);
    lista3.insertar_posicion('J', (char*)"diez", 7);

    cout << "Intentando borrar posicion inexistente (15):" << endl;
    if (!lista3.borrar_posicion(15)) {
        cout << "No se pudo borrar la posicion 15 (no existe)" << endl;
    }

    cout << "Buscando posicion 3:" << endl;
    nodo<char, char*>* pos3_3 = lista3.buscar_posicion(3);
    imprimirNodo(pos3_3);

    cout << "Borrando posicion 3:" << endl;
    lista3.borrar_posicion(3);

    cout << "Buscando posicion 3 despues de borrar:" << endl;
    pos3_3 = lista3.buscar_posicion(3);
    imprimirNodo(pos3_3);

    cout << "Modificando posicion 2:" << endl;
    lista3.modificar_posicion('Z', (char*)"once", 2);

    cout << "Buscando posicion 2 despues de modificar:" << endl;
    nodo<char, char*>* pos2_3 = lista3.buscar_posicion(2);
    imprimirNodo(pos2_3);

    imprimirLista(lista3);
    
    return 0;
}