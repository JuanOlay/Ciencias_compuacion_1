#include <iostream>
using namespace std;

int main() {
    int N, i, j, **a;  // N es el tamaño, i y j son contadores, a es un puntero a un arreglo de punteros
    size_t memoriaTotal = 0;  // Acumulador de memoria utilizada
    size_t tamanoEntero = sizeof(int);  // Tamaño de un entero en bytes
    size_t tamanoPuntero = sizeof(int*);  // Tamaño de un puntero a entero en bytes
    
    cout << "Ingrese el valor de N: ";
    cin >> N;  // Pedimos al usuario un numero N
    
    // Calculamos el tamaño del arreglo de punteros
    size_t tamanoArregloPunteros = N * tamanoPuntero;
    memoriaTotal += tamanoArregloPunteros;  // Sumamos la memoria utilizada
    
    // Mostramos informacion sobre tamaños
    cout << "Tamano de un entero: " << tamanoEntero << " bytes" << endl;
    cout << "Tamano de un puntero a entero: " << tamanoPuntero << " bytes" << endl;
    cout << "Tamano del arreglo de punteros: " << tamanoArregloPunteros << " bytes" << endl;
    
    // Asignamos memoria para un arreglo de punteros
    a = new int *[N];
    
    // Recorremos cada fila de la matriz
    for(i = 0; i < N; i++) {
        // Calculamos el tamaño de cada fila
        size_t tamanoFila = N * tamanoEntero;
        memoriaTotal += tamanoFila;  // Sumamos la memoria utilizada
        
        // Asignamos memoria para la fila
        a[i] = new int [N];
        
        // Llenamos la fila con valores y los mostramos en pantalla
        for(j = 0; j < N; j++) {
            a[i][j] = j * i;  // Asignamos un valor al elemento
            cout << a[i][j] << " ";  // Mostramos el valor
        }
        cout << endl;  // Salto de linea
        
        // Liberamos la memoria de la fila despues de usarla
        delete[] a[i];
    }
    
    // Liberamos la memoria del arreglo de punteros
    delete[] a;
    
    // Le sumamos a memoriaTotal la cantidad de memoria usada por las variables :p
    memoriaTotal += 3*tamanoEntero;
    
    // Mostramos un resumen del uso de memoria ;)
    cout << "\nTamano de cada fila: " << N * tamanoEntero << " bytes" << endl;
    cout << "Memoria total asignada: " << memoriaTotal << " bytes" << endl;
    
    return 0;
}
