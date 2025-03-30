#include <cstdlib>
#include <iostream>
using namespace std;

// Definimos una estructura llamada "nodo"
struct nodo {
    int x, y;     // Variables enteras para almacenar datos
    nodo *sig;    // Puntero que apunta al siguiente nodo en la lista
};

int main(int argc, char **argv) {
    nodo **arr, *Aux;  // "arr" es un arreglo de punteros a nodos, "Aux" es un nodo auxiliar
    int N, tam, j, i;  // N es el numero de listas, tam es el numero de nodos por lista
    size_t memoriaTotal = 0;  // Variable para acumular la memoria usada
    
    // Calcular tamaños de los diferentes tipos de datos
    size_t tamanoEntero = sizeof(int);  // Tamaño de un entero en bytes
    size_t tamanoNodo = sizeof(nodo);
    size_t tamanoPunteroNodo = sizeof(nodo*);
    
    // Pedir valores de N (numero de listas) y tam (numero de nodos por lista)
    cout << "Escriba el valor de N: ";
    cin >> N;
    cout << "Escriba el valor de tam: ";
    cin >> tam;
    
    // Mostrar informacion sobre los tamaños en memoria
    cout << "\nInformacion de tamanos:" << endl;
    cout << "Tamano de un nodo: " << tamanoNodo << " bytes" << endl;
    cout << "    - int x: " << sizeof(int) << " bytes" << endl;
    cout << "    - int y: " << sizeof(int) << " bytes" << endl;
    cout << "    - nodo *sig: " << sizeof(nodo*) << " bytes" << endl;
    cout << "Tamano de un puntero a nodo: " << tamanoPunteroNodo << " bytes" << endl;
    
    // Crear un arreglo de punteros a nodos
    size_t tamanoArregloPunteros = N * tamanoPunteroNodo;
    memoriaTotal += tamanoArregloPunteros;
    cout << "Tamano del arreglo de punteros: " << tamanoArregloPunteros << " bytes" << endl;
    
    arr = new nodo *[N];  // Asignamos memoria para N punteros a listas enlazadas
    
    // Inicializar cada lista en NULL
    for (i = 0; i < N; i++) {
        arr[i] = NULL;
    }
    
    // Llenar cada lista enlazada con "tam" nodos
    size_t totalNodosCreados = 0;
    for (i = 0; i < N; i++) {
        for (j = 1; j <= tam; j++) {
            Aux = new nodo;  // Crear un nuevo nodo
            memoriaTotal += tamanoNodo;
            totalNodosCreados++;
            
            // Asignar valores a los nodos
            Aux->x = j;     
            Aux->y = N + i * j; 
            Aux->sig = arr[i];  // Enlazar el nuevo nodo al inicio de la lista
            arr[i] = Aux;      // Actualizar la cabeza de la lista
        }
    }
    
    // Mostrar el contenido de cada lista enlazada
    for (i = 0; i < N; i++) {
        Aux = arr[i];
        cout << "Lista " << i << ":" << endl;
        while (Aux != NULL) {
            cout << Aux->x << " " << Aux->y << " " << Aux->sig << endl;
            Aux = Aux->sig;
        }
    }
    
    memoriaTotal += 4*tamanoEntero;
    
    // Resumen del uso de memoria
    cout << "Numero total de nodos creados: " << totalNodosCreados << endl;
    cout << "Memoria total asignada: " << memoriaTotal << " bytes" << endl;
    
    // Liberar la memoria de cada lista enlazada
    for (i = 0; i < N; i++) {
        Aux = arr[i];
        while (Aux != NULL) {
            nodo *temp = Aux; // Guardamos el nodo actual
            Aux = Aux->sig;   // Pasamos al siguiente nodo
            delete temp;      // Liberamos la memoria del nodo actual
        }
    }
    
    // Liberar el arreglo de punteros
    delete[] arr;
    
    cout << "\nToda la memoria ha sido liberada." << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
