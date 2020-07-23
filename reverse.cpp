//Разворачивамем массив, {1,2,3,4,5} -> {5,4,3,2,1}, сложность O(N)


#include <iostream>
using namespace std;

int main(){


	const int N=5;
	int tmp;

	int A[N] = {1,2,3,4,5};

	for(int i=0; i<N/2; i++){
		tmp = A[N-i-1];
		A[N-1-i] = A[i];
		A[i] = tmp;
	}

	for(int i=0; i<N; i++){
		cout<<A[i]<<"\t";
	}


	return 0;
}