//Алгоритм Дейкстры поиска кратчайшего пути в взевешшном графе, 
//где вес ребра = расстояние между вершинами <1000;

//алгортм базируется на bfs

#include <iostream>
#include <queue>
#include <stack>

int main(){

	int N,M, vertex;

	std::cin>>N;//число вершин
	std::cin>>M;//число ребер
	std::cin>>vertex;//вершина, до которой зхотим найти расстояние


	int* g = new int [N*N];

	for(int i=0; i<N*N; i++){
		g[i]=0;
	}

	for(int i=0; i<M; i++){//заполняем матрицу смежности

		int v1, v2, weight;
		std::cin>>v1;
		std::cin>>v2;
		std::cin>>weight;

		g[v1*N + v2] = weight;
		g[v2*N + v1] = weight;

	}

	std::cout<<"Матрица расстояний: \n"; //если на (i,j) месте стоит 0, то значит вершины i,j - не соединены, 
										//	иначе - вес ребра между ними

	for(int i=0; i<N; i++){

		std::cout<<i<<"\t";

		for(int j=0; j<N; j++){
			std::cout<<g[i*N+j]<<" ";
		}
		std::cout<<"\n";	
	}

	int* distances = new int [N];//массив расстояний от каждой вершины до стартовой 
	for(int i=0; i<N; i++){
		distances[i]=1000;
	}
	distances[0]=0;

	std::queue <int> Q;//очередь для вершин 

	Q.push(0);

	while (!Q.empty()){

		int cur_v = Q.front();
		Q.pop();

		for(int j=0; j<N; j++){
			if(g[cur_v*N +j] !=0  and g[cur_v*N +j] + distances[cur_v] < distances[j]){
				distances[j] = distances[cur_v] + g[cur_v*N +j];
				Q.push(j);
			}
		}	
	}

	std::stack <int> S;
	S.push(vertex);
	int backward_dist = distances[vertex];//расстояние от vertex до 0, которое будем уменьшать 
	while(backward_dist>0){

		for(int j=0; j<N; j++){
			if(g[vertex*N + j]!=0 and backward_dist- g[vertex*N + j] == distances[j]){
				backward_dist = backward_dist- g[vertex*N + j];
				std::cout<<backward_dist<<"\n";
				S.push(j);
				vertex = j;
				break;
			}
		}
	}


	std::cout<<"Минимальные расстояния от 0 вершины до остальных: \n";
	for(int i=0; i<N; i++){
		std::cout<<distances[i]<<" ";
	}
	std::cout<<"\n";

	std::cout<<"Путь, соответствующий минимальному маршруту: \n";
	while(!S.empty()){
		 std::cout<<S.top()<<" ";
		 S.pop();
	}
	std::cout<<"\n";

	delete[] g;
	return 0;
}