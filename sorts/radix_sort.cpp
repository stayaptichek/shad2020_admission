//упорядочиванием по разрядам в двоичной системы от меньших разрядов к большим 
//сложность O(M*N), где N - число элементов в массиве, M - система счисления 

#include <iostream>

using namespace std;

void radix_sort(int A[], int N);
void generate_random_array(int A[], int N, int M);
void print_array(int A[], int N);

int main(){


	int N=10;
	int A[N];

	generate_random_array(A,N,10);
	radix_sort(A, N);
	print_array(A,N);



	return 0;

}


void radix_sort_step(int A[], int N){

	int *a0 = new int [N];
	int *a1 = new int [N];
	int radix = 0;
	int a0_size = 0;
	int a1_size = 0;

	for(int i=0; i<N; i++){

		if((A[i] & (1<< radix))==0){//1<<radix - сдвиг на radix битов числа 1 в дв. предст.
			a0[a0_size] = A[i];
			a0_size++;

		}
		else{
			a1[a1_size] = A[i];	
			a1_size++;
		}
	}

	for(int i=0; i<a0_size; i++){
		A[i] = a0[i];
	}

	for(int i=0; i<a1_size; i++){
		A[a0_size + i] = a1[i];
	}

	delete [] a0;
	delete [] a1;

}	


void generate_random_array(int A[], int N, int M){

	for(int i=0; i<N; i++){
		A[i] = rand()%M;
		cout<<A[i]<<"\t";
	}
	cout<<endl;
}



void print_array(int A[], int N){

	for(int i=0; i<N; i++){
		cout<<A[i]<<"\t";
	}

}