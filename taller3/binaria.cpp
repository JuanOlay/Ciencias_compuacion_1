#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <algorithm>

using namespace std;

int busquedaBinaria(int arr[], int izquierda, int derecha, int objetivo) {
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arr[medio] == objetivo)
            return medio;
        else if (arr[medio] < objetivo)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }
    return -1;
}

void llenarYOrdenarArreglo(int arr[], int n) {
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;
    }
    sort(arr, arr + n);
}

void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int *arr, n, objetivo;
    LARGE_INTEGER inicio, fin, frecuencia;

    cout << "Tamano del arreglo: ";
    cin >> n;

    arr = new int[n];

    llenarYOrdenarArreglo(arr, n);
    cout << "Arreglo ordenado:" << endl;
    imprimirArreglo(arr, n);

    objetivo = arr[rand() % n];
    cout << "Numero a buscar: " << objetivo << endl;

    QueryPerformanceFrequency(&frecuencia);
    QueryPerformanceCounter(&inicio);

    int resultado = busquedaBinaria(arr, 0, n - 1, objetivo);

    QueryPerformanceCounter(&fin);

    double tiempo = static_cast<double>(fin.QuadPart - inicio.QuadPart) / frecuencia.QuadPart;

    if (resultado != -1)
        cout << "Elemento encontrado en la posicion: " << resultado << endl;
    else
        cout << "Elemento no encontrado." << endl;

    cout << "Tiempo de ejecucion de la busqueda: " << tiempo * 1000 << " milisegundos" << endl;

    delete[] arr;
    return 0;
}
