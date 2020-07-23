//ОБХОД ГРАФА В ШИРИНУ

//Алгоритм:
//1) выбираем текущую вершину стартовой 
//2) запускаем цикл, где берем для каждой текущей вершины всех непомеченных соседей,
//   до которых расстояни = 1 и помечаем их

#include <iostream>3
#include <queue>

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
		g[v2*N + v1] = 1;

	}

	std::cout<<"Матрица смежности: \n";

	for(int i=0; i<N; i++){

		std::cout<<i<<"\t";

		for(int j=0; j<N; j++){
			std::cout<<g[i*N+j]<<" ";
		}
		std::cout<<"\n";	
	}

	int* distances = new int [N];//массив расстояний от каждой вершины до стартовой 
	for(int i=0; i<N; i++){
		distances[i]=-1;
	}
	distances[0]=0;

	std::queue <int> Q;//очередь для вершин 

	Q.push(0);

	while (!Q.empty()){

		int cur_v = Q.front();
		Q.pop();

		for(int j=0; j<N; j++){
			if(g[cur_v*N +j]==1 and distances[j]==-1){
				distances[j] = distances[cur_v] + 1;
				Q.push(j);
			}
		}	
	}

	std::cout<<"Расстояния от 0 вершины до остальных: \n";
	for(int i=0; i<N; i++){
		std::cout<<distances[i]<<" ";
	}
	std::cout<<"\n";

	return 0;
}