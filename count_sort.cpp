#include <iostream>
using namespace std;

void count_sort(int A[], int N);
void generate_random_array(int A[], int N, int M);
void print_array(int A[], int N);

int main(){

	int N=10;
	int A[N];

	generate_random_array(A,N,10);
	count_sort(A, N);
	print_array(A,N);


	return 0;

}

void count_sort(int A[], int N){//сложность O(N+M)

	//я обязан знать диапазон сортируемых чисел 
	int F[10] = {0};
	for(int i=0; i<N; i++){
		F[A[i]]++;
	}
	int i=0;

	for(int x=0; x<10; x++){
		for(int k=0; k<F[x]; k++){
			A[i]=x;
			i++;
		}
	}

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



