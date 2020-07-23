#include <iostream>

using namespace std;

int gcd(int a, int b){//НОД алгоритмом Евклида

	if (b==0)
		return a;

	else 
		return gcd(b, a%b);
}

/*
Hanoi solution finder 
param i: start pin number
param k: finish pin number
param n: number of disks
*/
void hanoi (int i, int k, int n){

	if (n==1){
		cout<<"Move disk 1 from pin "<<i<<" to pin "<<k<<endl;
	}

	else{
		int tmp = 6 - i - k;//temporary 
		hanoi(i, tmp, n-1);
		cout<<"Move disk "<<n<<" from pin "<<i<<" to pin "<<k<<endl;
		hanoi(tmp, k, n-1);
	}

}



void generate_binary_numbers(int digits_left_to_generate){

	static int digits_combination[100];
	static int top = 0;

	if(digits_left_to_generate==0){
		for(int i=0; i<top; i++){
			cout<<digits_combination[i];
		}
		cout<<endl;
	}

	else{
		digits_combination[top]=0;
		top++;
		generate_binary_numbers(digits_left_to_generate-1);
		top--;

		digits_combination[top]=1;
		top++;
		generate_binary_numbers(digits_left_to_generate-1);
		top--;
	}
}




int main(){

	int a,b;

	//cin>>a>>b;
	//cout<<gcd(a,b)<<endl;

	//hanoi(1,2,4);

	int n;
	cin>>n;
	generate_binary_numbers(n);



	return 0;

}





