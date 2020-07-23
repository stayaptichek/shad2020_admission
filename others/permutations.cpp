//строим все перестановки 

#include <iostream>

using namespace std;



void permutations(int number,  int current, int buffer[], bool used[]){

	if(current == number){
		for(int i=0; i<number; i++){
			cout<<buffer[i]<<"\t";
		}
		cout<<endl;
	}

	else{

		for(int variant = 0; variant < number; variant++){

			if(not used[variant]){//cutting the recusrsive tree
				buffer[current]=variant;
				used[variant]=true;//чтобы в последующих ветках не использовалось 
				permutations(number, current + 1, buffer, used);
				used[variant]=false;//в других ветках может быть 
			}
		}
	}
}

int main(){

	int n;
	cin>>n;
	int buffer[n];
	bool used[n];

	for(int i=0; i<n; i++){
		used[i]=false;
	}

	if(n>20){
		cout<<"Your number is too big"<<endl;
		return 1;
	}

	else if (n<=0){
		cout<<"You number is negative"<<endl;
		return 1;
	}

	permutations(n, 0, buffer, used);

	return 0;

}
