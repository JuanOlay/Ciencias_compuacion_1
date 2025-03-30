#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Ingrese el valor de N: ";
    cin >> N;

    int May;
    cout << "Ingrese el primer valor: ";
    cin >> May;

    for (int K = 2; K <= N; ++K) {
        int Dato;
        cout << "Ingrese el siguiente valor: ";
        cin >> Dato;

        if (Dato > May) {
            May = Dato;
        }
    }

    cout << "El valor máximo es: " << May << endl;

    return 0;
}