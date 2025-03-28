#include <iostream>
# include <cstdlib>
#include <time.h>       /* time */

using namespace std;

void intercambio(int a[], int min, int i){
	a[i]= min;
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



imprimir_arreglo(int a[], int N){
	for(int i=0;i<N;i++)
	cout<<a[i]<<endl;
	
}

void llenar(int a[],int N){
	srand (time(NULL));
	for(int i=0;i<N;i++){
		a[i] = rand() % 100 + 1;
	}
}


int main(){
	int *a, N;
	a = new int[N];
	cout<<"tamano del arreglo";
	cin>> N;
	llenar(a,N);
	imprimir_arreglo(a,N);
	seleccion(a,N);
	imprimir_arreglo(a,N);
	
	
	delete[] a;
}
