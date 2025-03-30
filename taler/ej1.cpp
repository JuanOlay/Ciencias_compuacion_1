#include <iostream>
using namespace std;

int main() {
    int N, *a;  // Variable para el tamaño del arreglo y un puntero para almacenarlo
    long long totalMemoria = 0;  // Variable para acumular la memoria usada
    
    cout << "Ingrese el valor de N: ";
    cin >> N;  // Pedimos al usuario un numero N
    
    // Tamaño de un entero en bytes; aqui se calcula exactamente el tamano de N aunque podriamos calcular simplemente el tamaño de una variable int ya que pesan siempre lo mismo en c++
    size_t tamanoEntero = sizeof(N);
    
    // Tamaño de un arreglo de N enteros
    size_t tamanoArreglo = N * tamanoEntero;
    
    
    // Bucle que se repite N veces
    for(int i = 0; i < N; i++) {
        // Reservamos memoria para un arreglo de N enteros
        a = new int[N];
        
        // Sumamos la memoria asignada a la variable total
        totalMemoria += tamanoArreglo;
        
        // Llenamos el arreglo con valores y los mostramos en pantalla
        for(int j = 0; j < N; j++) {
            a[j] = j * i;  // Asignamos un valor al elemento
            cout << a[j] << " ";
        }
        cout << endl;
        
        // Liberamos la memoria asignada
        delete [] a;
    }
    
    // Le sumamos a el total memoria la cantidad de memoria de cada una de las variables utilizadas(i , j, N)
    totalMemoria += 3*tamanoEntero;
    
    // Mostramos la cantidad total de memoria utilizada
    cout << "Memoria total asignada durante la ejecucion: " << totalMemoria << " bytes" << endl;
    
    return 0;
}
