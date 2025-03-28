#include <iostream>
# include <cstdlib>
#include <time.h>       /* time */
#include <windows.h>  // Para QueryPerformanceCounter

using namespace std;

void intercambio(int a[], int min, int i) {
    int temp = a[min];
    a[min] = a[i];
    a[i] = temp;
}

void seleccion(int a[], int N){
	int i, j, min;
	for(i=0;i<N;i++){
		min = i;
		for(j=i+1;j<=N;j++){
			if(a[j]<a[min]) min =j;
		}
		intercambio (a,min, i);
	}
}



void imprimir_arreglo(int a[], int N){
	for(int i=0;i<N;i++)
	cout<<a[i]<<" ";
cout<<endl;
	
}

void llenar(int a[],int N){
	srand (time(NULL));
	for(int i=0;i<N;i++){
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
    
    // Inicializar contadores de tiemp
    QueryPerformanceFrequency(&frecuencia);
    QueryPerformanceCounter(&inicio);

    seleccion(a, N);

    QueryPerformanceCounter(&fin);

    double tiempo = static_cast<double>(fin.QuadPart - inicio.QuadPart) / frecuencia.QuadPart;

    cout << "Arreglo ordenado:" << endl;
    imprimir_arreglo(a, N);


    cout << "Tiempo de ejecucion: " << tiempo * 1000 << " milisegundos" << endl;

    delete[] a;
    return 0;
}
