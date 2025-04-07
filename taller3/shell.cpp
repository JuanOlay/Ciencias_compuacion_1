#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;


void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void llenarArreglo(int arr[], int n) {
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

int main() {
    int *arr, n;
    LARGE_INTEGER inicio, fin, frecuencia;

    cout << "Tamano del arreglo: ";
    cin >> n;

    arr = new int[n];

    llenarArreglo(arr, n);
    cout << "Arreglo original:" << endl;
    imprimirArreglo(arr, n);
    

    QueryPerformanceFrequency(&frecuencia);
    QueryPerformanceCounter(&inicio);


    shellSort(arr, n);


    QueryPerformanceCounter(&fin);


    double tiempo = static_cast<double>(fin.QuadPart - inicio.QuadPart) / frecuencia.QuadPart;

    cout << "Arreglo ordenado:" << endl;
    imprimirArreglo(arr, n);


    cout << "Tiempo de ejecucion del ordenamiento: " << tiempo * 1000 << " milisegundos" << endl;

    delete[] arr;
    return 0;
}
