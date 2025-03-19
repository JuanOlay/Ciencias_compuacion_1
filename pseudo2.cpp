#include <iostream>

int main() {
    int N;
    std::cout << "Ingrese el valor de N: ";
    std::cin >> N;

    int Dato[N]; // Arreglo estático de tamaño N

    for (int K = 0; K < N; ++K) {
        std::cout << "Ingrese el valor de Dato[" << K + 1 << "]: ";
        std::cin >> Dato[K];
    }

    int May = Dato[0];

    for (int K = 1; K < N; ++K) {
        if (Dato[K] > May) {
            May = Dato[K];
        }
    }

    std::cout << "El valor máximo es: " << May << std::endl;

    return 0;
}