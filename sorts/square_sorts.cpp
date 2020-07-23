//Ниже представлены квадратичные сортировки, их сложность O(N^2)

#include <iostream>

using namespace std;


void insert_sort(int* A, int N);
void choice_sort(int* A, int N);
void bubble_sort(int *A, int N);

int main(){

	const int N=5;
	int A[N] = {5,4,3,2,1};

	//insert_sort(A, N);

	for(int i=0; i<N; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;

	//choice_sort(A, N);

	for(int i=0; i<N; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;

	bubble_sort(A, N);

	for(int i=0; i<N; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;

	return 0;

}

void insert_sort(int* A, int N)
{
	for(int i=1; i<N; i++){
		int j=i;
		//берем каждого за шкирку и тащим налево, сравнивая с каждым, и меняя, если необходимо
		while (j>0 & A[j-1]>A[j]){
			int temp = A[j-1];
			A[j-1] = A[j];
			A[j] = temp; 
			j--;
		}
	}

}

void choice_sort(int *A, int N)
{
	for(int i=0; i<N-1; i++){
		//каждого сравниваем с каждым, кто стоит правее его самого и меняем, если необходимо 
		//получаем на каждом шаге уже отсортрованный подмассив  
		for(int j=i+1; j<N; j++){
			if (A[i]>A[j]){
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp; 
			}
		}
	}
}

void bubble_sort(int *A, int N)
{
	for(int i=1; i<N; i++){
		//за каждый внутренни цикл самый большой элемент в оставшемся подмассиве встает в конец
		for(int j=0; j<N-i; j++){
			if (A[j]>A[j+1]){
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp; 
			}
		}
	}
}






