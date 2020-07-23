#include <iostream>

using namespace std;

unsigned long int fib_recursive(int n)
{
	if(n==0 or n==1){
		return n;
	}

	else{
		return fib_recursive(n-1) + fib_recursive(n-2);
	}



}
unsigned long int fib_dynamic(int n)
{
	unsigned long int result;
	unsigned long int* fib = new unsigned long int [n+1];
	fib[0] = 0;
	fib[1] = 1;

	for(int i=2; i<n+1; i++){
		fib[i] = fib[i-1]+fib[i-2];
	}

	result = fib[n];

	delete[] fib;
	return result;
}

int main()
{

	for(int n=0; n<60; n++){
		cout<<n<<"\t"<<fib_dynamic(n)<<"\n";
	}
	for(int n=0; n<60; n++){
		cout<<n<<"\t"<<fib_recursive(n)<<"\n";
	}

	return 0;

}