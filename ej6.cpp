#include <iostream>
using namespace std;

// Definicion de la estructura "nodo"
struct nodo {
    int a; // Primer valor del nodo
    int b; // Segundo valor del nodo
};

int main(int argc, char** argv) {
    int N, i, j; // Variables para iteraciones
    nodo **a; // Arreglo bidimensional de nodos
    size_t memoriaTotal = 0; // Variable para rastrear la memoria utilizada
    
    // Calcular tamanos de los elementos principales
    size_t tamanoEntero = sizeof(int); // Tamano de un entero
    size_t tamanoNodo = sizeof(nodo); // Tamano de un nodo (estructura)
    size_t tamanoPunteroNodo = sizeof(nodo*); // Tamano de un puntero a nodo
    
    // Solicitar al usuario el valor de N (dimensiones del arreglo)
    cout << "Ingrese el valor de N: ";
    cin >> N;
    
    // Mostrar informacion sobre los tamanos
    cout << "\nInformacion de tamanos:" << endl;
    cout << "Tamano de un nodo (estructura): " << tamanoNodo << " bytes" << endl;
    cout << "    - int a: " << tamanoEntero << " bytes" << endl;
    cout << "    - int b: " << tamanoEntero << " bytes" << endl;
    cout << "Tamano de un puntero a nodo: " << tamanoPunteroNodo << " bytes" << endl;
    
    // Reservar memoria para el primer nivel: Arreglo de punteros a nodos
    size_t tamanoArregloPunteros = N * tamanoPunteroNodo;
    memoriaTotal += tamanoArregloPunteros;
    a = new nodo *[N]; // Crear el primer nivel (arreglo de punteros)
    
    // Reservar memoria para el segundo nivel: Arreglos de nodos
    size_t tamanoArregloNodos = N * tamanoNodo; // Tamano de cada fila de nodos
    size_t totalNodos = N * tamanoArregloNodos; // Tamano total de todos los nodos
    memoriaTotal += totalNodos;

    // Llenar el arreglo con valores
    for(i = 0; i < N; i++) {
        a[i] = new nodo[N]; // Crear la fila de nodos
        for(j = 0; j < N; j++) {
            a[i][j].a = j * i; // Asignar valor a "a"
            a[i][j].b = j + i; // Asignar valor a "b"
        }
    }
    
    // Mostrar los valores almacenados y liberar memoria
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            cout << a[i][j].a << "," << a[i][j].b << " "; // Mostrar valores
        }
        delete[] a[i]; // Liberar memoria de cada fila de nodos
        cout << endl;
    }
    delete[] a; // Liberar memoria del arreglo de punteros
    
    // Sumar tamanos de variables enteras auxiliares
    memoriaTotal += 3 * tamanoEntero;
    
    // Mostrar resumen de memoria utilizada
    cout << "Memoria total asignada: " << memoriaTotal << " bytes" << endl;
    
    return 0;
}
