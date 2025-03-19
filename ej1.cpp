#include <iostream>
using namespace std;

int main() {
	int N, *a;
	cin>> N;
	for(int i = 0; i < N; i++)
		{a = new int [N];
		for(int j = 0; j < N; j++)
			{a[j] = j*i;
			cout<< a[j]<< " ";
			}
			cout<< endl;
			delete []a;
		}
	
}