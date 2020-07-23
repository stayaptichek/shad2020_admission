//ТОПОЛОГИЧЕСКАЯ СОРТИРОВКА

//Постановка: если ор.граф не содержит циклов (т.е. ациклич. граф), то его вершины можно пронумеровать так, что 
// любое ребро идет от вершины с меньшим номером к вершине с большми номером 


#include <iostream>
#include<stack>

void dfs(int vertex, int* g, int* used, int N, std::stack<int> * S){

	used[vertex]=1;

	for(int i=0; i<N; i++){
		if(g[vertex*N + i]==1 and used[i]==0){
			dfs(i, g, used, N, S);
		}
	}

	(*S).push(vertex);

}

int main(){

	int N,M;

	std::cin>>N;//число вершин
	std::cin>>M;//число ребер

	int* g = new int [N*N];

	for(int i=0; i<N*N; i++){
		g[i]=0;
	}

	for(int i=0; i<M; i++){//заполняем матрицу смежности

		int v1, v2;
		std::cin>>v1;
		std::cin>>v2;

		g[v1*N + v2] = 1;

	}

	std::cout<<"Матрица смежности: \n";

	for(int i=0; i<N; i++){

		std::cout<<i<<"\t";

		for(int j=0; j<N; j++){
			std::cout<<g[i*N+j]<<" ";
		}
		std::cout<<"\n";	
	}

	int* used = new int [N];

	for(int i=0; i<N; i++){
		used[i]=0;
	}

	std::stack <int> S;




	for(int i=0; i<N; i++){
		if(used[i]==0){
			dfs(i, g, used, N, &S);
		}
	}

	std::cout<<"Результат топологической сортировки: ";

	for(int i=0; i<N; i++){
		std::cout<<S.top()<<" ";
		S.pop();
	}

	std::cout<<"\n";



	return 0;

	delete[] used;
	delete[] g;
}