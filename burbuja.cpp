#include <iostream>
#include <cstdlib>
#include <time.h>       
#include <windows.h>  
using namespace std;

void intercambio(int a[], int j, int pos) {
    int temp = a[j];
    a[j] = a[pos];
    a[pos] = temp;
}

void burbuja(int a[], int N) {
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                intercambio(a, j, j + 1);
            }
        }
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

    burbuja(a, N);

    // Obtener tiempo final
    QueryPerformanceCounter(&fin);

    // Calcular tiempo transcurrido
    double tiempo = static_cast<double>(fin.QuadPart - inicio.QuadPart) / frecuencia.QuadPart;

    cout << "Arreglo ordenado:" << endl;
    imprimir_arreglo(a, N);

    // Mostrar tiempo de ejecucion
    cout << "Tiempo de ejecucion: " << tiempo * 1000 << " milisegundos" << endl;

    delete[] a;
    return 0;
}