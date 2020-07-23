//Двумернео динамическое программирование 

//Требуется узнать количество путей из левого верхнего угла (1,1) в клетку (m,n)
//Герой истори - муравей

//K_[i,j} - количество путей из (1,1) в (i,j)
//K_{i,j} = K_{i,j-1} + K_{i-1,j}
//гранич.усл.: K_{i,1} = 1, K_{1,j}=1

#include <iostream>

using namespace std;

unsigned long int ant_recursive(int n, int m)//решаем рекурсивно
{
	if(n==1 or m==1){
		return 1;
	}

	else{
		return ant_recursive(n,m-1) + ant_recursive(n-1,m);
	}



}
  int ant_dynamic(int n, int m)//решаем динамически 
{
	  int result;
	  int* ant_loc = new int[(n+1)*(m+1)];
	
	for(int i=2; i<n+1; i++){
		ant_loc[i*(m+1)+1]=1;
	}

	for(int j=2; j<m+1; j++){
		ant_loc[(m+1) + j]=1;
	}

	for(int i=2; i<n+1; i++){
		for(int j=2; j<m+1; j++){
			ant_loc[i*(m+1)+j] = ant_loc[(i-1)*(m+1)+j] + ant_loc[i*(m+1)+j-1];
		}
	}

	result = ant_loc[n*(m+1)+m];

	delete[] ant_loc;
	return result;
}

int main()
{

	int n, m;

	cout<<"Введите значения (n,m): "<<endl;

	cin>>n>>m;

	for(int i=1; i<n+1; i++){
		for(int j=1; j<m+1; j++){
			cout<<ant_dynamic(i,j)<<"\t";
		}
		cout<<endl;
	}

	cout<<endl;

	for(int i=1; i<n+1; i++){
		for(int j=1; j<m+1; j++){
			cout<<ant_recursive(i,j)<<"\t";
		}
		cout<<endl;
	}


	return 0;

}