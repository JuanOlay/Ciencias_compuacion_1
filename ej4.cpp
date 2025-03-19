#include <cstdlib>
#include <iostream>
using namespace std;

struct nodo {
    int x, y;
    nodo *sig;
};

int main(int argc, char **argv) {
    nodo **arr, *Aux;
    int N, tam, j, i;

    // Solicitar valores de N y tam
    cout << "Escriba el valor de N: ";
    cin >> N;
    cout << "Escriba el valor de tam: ";
    cin >> tam;

    // Crear un arreglo de punteros a nodo
    arr = new nodo *[N];

    // Inicializar cada elemento del arreglo a NULL
    for (i = 0; i < N; i++) {
        arr[i] = NULL;
    }

    // Llenar cada lista enlazada
    for (i = 0; i < N; i++) {
        for (j = 1; j <= tam; j++) {
            Aux = new nodo; // Crear un nuevo nodo
            Aux->x = j;     // Asignar valor a x
            Aux->y = N + i * j; // Asignar valor a y
            Aux->sig = arr[i];  // Enlazar el nuevo nodo a la lista
            arr[i] = Aux;      // Actualizar el puntero de la lista
        }
    }

    // Mostrar las listas enlazadas
    for (i = 0; i < N; i++) {
        Aux = arr[i];
        cout << "Lista " << i << ":" << endl;
        while (Aux != NULL) {
            cout << Aux->x << " " << Aux->y << " " << Aux -> sig << endl;
            Aux = Aux->sig;
        }
    }

    // Liberar la memoria de las listas enlazadas
    for (i = 0; i < N; i++) {
        Aux = arr[i];
        while (Aux != NULL) {
            nodo *temp = Aux; // Guardar el nodo actual
            Aux = Aux->sig;   // Mover al siguiente nodo
            delete temp;      // Liberar el nodo actual
        }
    }

    // Liberar el arreglo de punteros
    delete[] arr;

    system("PAUSE");
    return EXIT_SUCCESS;
}