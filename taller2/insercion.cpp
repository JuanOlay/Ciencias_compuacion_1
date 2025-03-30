#include <iostream>
#include <cstdlib>
#include <time.h>       
#include <windows.h>  
using namespace std;

void insercion(int a[], int N) {
    int i, j, v;
    for (i = 1; i < N; i++) {
        j = i;
        v = a[i];
        while (j > 0 && a[j-1] > v) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}

void imprimir_arreglo(int a[], int N) {
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << endl;
}

void llenar(int a[], int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 100 + 1;
    }
}

int main() {
    int *a, N;
    LARGE_INTEGER inicio, fin, frecuencia;

    cout << "Tamano del arreglo: ";
    cin >> N;

    a = new int[N];

    llenar(a, N);
    cout << "Arreglo original:" << endl;
    imprimir_arreglo(a, N);
    
    // Inicializar contadores de tiempo
    QueryPerformanceFrequency(&frecuencia);
    QueryPerformanceCounter(&inicio);


    insercion(a, N);

    // Obtener tiempo final
    QueryPerformanceCounter(&fin);

    // Calcular tiempo transcurrido
    double tiempo = static_cast<double>(fin.QuadPart - inicio.QuadPart) / frecuencia.QuadPart;

    cout << "Arreglo ordenado:" << endl;
    imprimir_arreglo(a, N);

    // Mostrar tiempo de ejecucin
    cout << "Tiempo de ejecucion: " << tiempo * 1000 << " milisegundos" << endl;

    delete[] a;
    return 0;
}