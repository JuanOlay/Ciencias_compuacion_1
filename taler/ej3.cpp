#include <iostream>
using namespace std;

int main() {
    // Definimos una estructura llamada "nodo"
    struct nodo {
        int x, y;     // Dos variables enteras para almacenar datos
        nodo *sig;    // Puntero que apunta al siguiente nodo en la lista
    };
    
    int N, i, j;  // N es el numero de nodos, i y j son contadores
    nodo *cab = NULL, *Aux;  // "cab" es la cabeza de la lista, "Aux" es un nodo auxiliar
    size_t memoriaTotal = 0;  // Variable para acumular la memoria usada
    size_t tamanoEntero = sizeof(int);  // Tamaño de un entero en bytes
    size_t tamanoNodo = sizeof(nodo);  // Tamaño de un nodo en bytes
    
    cout << "Ingrese el valor de N: ";
    cin >> N;  // Pedimos al usuario el numero de nodos

    // Mostramos informacion sobre el tamaño de cada nodo
    cout << "Tamano de un nodo: " << tamanoNodo << " bytes" << endl;
    cout << "    - int x: " << sizeof(int) << " bytes" << endl;
    cout << "    - int y: " << sizeof(int) << " bytes" << endl;
    cout << "    - nodo *sig: " << sizeof(nodo*) << " bytes" << endl;
    
    // Creamos la lista enlazada con N nodos
    for(i = 0; i < N; i++) {
        Aux = new nodo;  // Reservamos memoria para un nuevo nodo
        memoriaTotal += tamanoNodo;  // Sumamos la memoria usada
        
        // Asignamos valores a los atributos del nodo
        Aux->x = i;
        Aux->y = N - i;
        Aux->sig = cab;  // El nuevo nodo apunta al nodo anterior
        cab = Aux;  // Ahora la cabeza de la lista es el nuevo nodo
    }
    
    // Mostramos los nodos creados
    cout << "\nNodos creados:" << endl;
    Aux = cab;
    int contador = 0;
    while(Aux != NULL) {
        cout << Aux->x << " " << Aux->y << endl;
        Aux = Aux->sig;
        contador++;
    }
    
    // Le sumamos a memoriaTotal la cantidad de memoria usada por las variables :p
    memoriaTotal += 3*tamanoEntero;
    
    // Mostramos un resumen del uso de memoria
    cout << "/nNumero de nodos creados: " << contador << endl;
    cout << "Memoria total asignada: " << memoriaTotal << " bytes" << endl;
    
    // Liberamos la memoria de la lista enlazada
    for(Aux = cab->sig; Aux != NULL; Aux = Aux->sig) {
        delete cab;  // Eliminamos el nodo actual
        cab = Aux;   // Pasamos al siguiente nodo
    }
    if (cab != NULL) {
        delete cab;  // Eliminamos el ultimo nodo si aun existe
    }
    
    return 0;
}
