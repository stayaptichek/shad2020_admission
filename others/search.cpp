/*
линейный поиск в массиве
O(1) - скорость доступа по индексу

                      проверяем, есть элемент в массиве, или нет
                     /
 два варианта поиска:
                     \
                      находим индекс элемента
*/



#include <iostream>
using namespace std;

int lin_search(int A[], int N, int x);
int bin_search_left(int A[], int N, int x);
int bin_search_find(int A[], int N, int x);

int main(){

	int N=10;
	int A[] = {1,3,3,7,7,7,7,9,10,10};
	int x;

	cin>>x;
	cout<<"index of x is: "<<lin_search(A,N,x)<<endl;
	cout<<"left boundary of x is: "<<bin_search_left(A,N,x)<<endl;
	cout<<"index of x is: "<<bin_search_find(A,N,x)<<endl;
	

	return 0;

}

int lin_search(int A[], int N, int x){//сложность O(N)

	int index = -1;

	for(int i=0; i<N; i++){

		if(A[i]==x){
			index = i;
		}
	}

	return index;
}

int bin_search_left(int A[], int N, int x){//сложность O(logN) 

	int left = -1;
	int right = N;

	while(right - left >1 ){
		int middle = (left + right)/2;

		if(A[middle]<x){
			left = middle;//левая граница всегда строго левее x
		}

		else{
			right = middle;
		}
	}

	return left; 
}

int bin_search_find(int A[], int N, int x){

	int left = bin_search_left(A,N,x);
	int left_plus_one = left + 1;

	if(left_plus_one < N and A[left_plus_one]==x){
		return left_plus_one;
	}

	else{
		return -1;//x не найден
	}

}



