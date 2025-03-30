#include <iostream>
using namespace std;

// Definicion de una estructura llamada "nodo"
struct nodo {
    int x, y; // Coordenadas o valores del nodo
    nodo *s;  // Puntero al siguiente nodo en la lista
};

int main(int argc, char** argv) {
    int N, i, j, k; // Variables de control
    nodo ***a, *Aux; // "a" es un arreglo tridimensional de punteros a nodos
    size_t memoriaTotal = 0; // Variable para rastrear la memoria asignada
    
    // Calcular tamanos de los elementos principales
    size_t tamanoEntero = sizeof(int);  // Tamaño de un entero en bytes
    size_t tamanoNodo = sizeof(nodo); // Tamano de un solo nodo
    size_t tamanoPunteroNodo = sizeof(nodo*); // Tamano de un puntero a nodo
    size_t tamanoPunteroDoblePuntero = sizeof(nodo**); // Tamano de un puntero doble
    
    // Pedir al usuario el valor de N (dimensiones de la estructura de datos)
    cout << "Ingrese el valor de N: ";
    cin >> N;
    
    // Mostrar informacion sobre los tamanos
    cout << "\nInformacion de tamanos:" << endl;
    cout << "Tamano de un nodo: " << tamanoNodo << " bytes" << endl;
    cout << "Tamano de un puntero a nodo: " << tamanoPunteroNodo << " bytes" << endl;
    cout << "Tamano de un puntero a puntero de nodo: " << tamanoPunteroDoblePuntero << " bytes" << endl;
    
    // Reservar memoria para el primer nivel: Arreglo de punteros a punteros
    size_t tamanoArregloPrimerNivel = N * tamanoPunteroDoblePuntero;
    memoriaTotal += tamanoArregloPrimerNivel;
    
    a = new nodo **[N]; // Crear el primer nivel del arreglo
    
    // Reservar memoria para el segundo nivel: Arreglos de punteros a nodo
    size_t tamanoArregloSegundoNivel = N * tamanoPunteroNodo;
    size_t totalSegundoNivel = N * tamanoArregloSegundoNivel;
    memoriaTotal += totalSegundoNivel;
    
    for(i = 0; i < N; i++) {
        a[i] = new nodo *[N]; // Crear el segundo nivel
        for(j = 0; j < N; j++) {
            a[i][j] = NULL; // Inicializar con NULL (lista vacia)
        }      
    }
    
    // Reservar memoria para el tercer nivel: Creacion de nodos
    int totalNodosCreados = 0;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            for(k = 0; k < N; k++) {
                Aux = new nodo; // Crear un nuevo nodo
                memoriaTotal += tamanoNodo;
                totalNodosCreados++;
                
                // Asignar valores a los nodos
                Aux->x = j * k;
                Aux->y = i + k;
                
                // Enlazar el nodo a la lista en la posicion (i, j)
                Aux->s = a[i][j];
                a[i][j] = Aux;
            }
        }
    }
    
    // Mostrar las listas enlazadas y liberar memoria
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            Aux = a[i][j];
            cout << "Lista en posicion " << i << "," << j << endl;
            while(Aux != NULL) {
                cout << Aux->x << " " << Aux->y << endl;
                Aux = Aux->s;
            }
            
            // Liberar memoria de los nodos en la lista
            for(Aux = a[i][j]->s; Aux != NULL; Aux = Aux->s) {
                delete a[i][j];
                a[i][j] = Aux;
            }
            delete a[i][j]; // Eliminar el ultimo nodo de la lista
            cout << endl;
        }
        // Liberar memoria del segundo nivel
        delete[] a[i];
        cout << endl;
    }
    // Liberar memoria del primer nivel
    delete[] a;
    
    memoriaTotal += 4*tamanoEntero
    
    // Mostrar resumen del uso de memoria
    cout << "Memoria total asignada: " << memoriaTotal << " bytes" << endl;
    
    return 0;
}
