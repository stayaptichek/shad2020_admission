#include <iostream>

int func(int* a, int N){

	int number_zeros = 0;
	int ones = 0;
	int len = 0;
	int max_len = 0;

	for(int i=0; i<N; i++){

		if(a[i]==1){
			number_zeros=0;
			ones++;
			len++;
		}

		if(a[i]==0){

			number_zeros++;

			if(number_zeros == 1){
				len = ones;
				ones = 0;
			}

			if(number_zeros >1){
				len = 0;
				ones = 0;
			}
		}

		if(len > max_len){
			max_len = len;
		}
	}

	if(max_len==N){
		return max_len-1;
	}

	return max_len;

}

int main(){

	int N;
	N=10;

	int* a = new int [N];

	for(int i=0; i<N; i++){
		std::cin>>a[i];
	}


	std::cout<<"\n"<<func(a,N)<<"\n";


	return 0;

}


