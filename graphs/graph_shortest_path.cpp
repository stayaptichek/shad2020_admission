//Воостановление кратчайшего пути в графе
//используем обход в ширину bfs.cpp

#include <iostream>
#include <queue>
#include <stack>

int main(){

	int N,M;


	std::cout<<"Введите число вершин и ребер: \n";

	std::cin>>N;//число вершин
	std::cin>>M;//число ребер

	int* g = new int [N*N];

	for(int i=0; i<N*N; i++){
		g[i]=0;
	}

	std::cout<<"Введите ребра \n";

	for(int i=0; i<M; i++){//заполняем матрицу смежности

		int v1, v2;
		std::cin>>v1;
		std::cin>>v2;

		g[v1*N + v2] = 1;
		g[v2*N + v1] = 1;

	}


	int end_vertex;
	std::cout<<"Введите номер вершины, кратчайший путь до которой вы хотите найти: \n";
	std::cin>>end_vertex;

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

	int* parrents = new int [N];//массив предков 
	for(int i=0; i<N; i++){
		parrents[i]=-1;//считаем, что дефолтно у всех вершин предок -1
	}

	std::queue <int> Q;//очередь для вершин 

	Q.push(0);

	while (!Q.empty()){

		int cur_v = Q.front();
		Q.pop();

		for(int j=0; j<N; j++){
			if(g[cur_v*N +j]==1 and distances[j]==-1){
				distances[j] = distances[cur_v] + 1;
				parrents[j]=cur_v;
				Q.push(j);
			}
		}	
	}

	int parent;//текущая перменная для предка
	std::stack <int> S;
	S.push(end_vertex);

	parent=parrents[end_vertex];


	while (parent != -1){//Ищем кратчайший путь

		//!!! Этот путь будет кратчайшим, так как массив предков строился так, что 
		// от каждой вершины через предков можно дойти до стартовой вершины 
		// за минимальное число шагов

		S.push(parent);
		parent=parrents[parent];

	}


	std::cout<<"Кратчайший путь до вершины "<<end_vertex<<":\n";
	while(!S.empty()){
		std::cout<<S.top()<<" ";
		S.pop();
	}
	std::cout<<"\n";

	std::cout<<"Расстояния от 0 вершины до остальных: \n";
	for(int i=0; i<N; i++){
		std::cout<<distances[i]<<" ";
	}
	std::cout<<"\n";

	std::cout<<"Массив предков: \n";
	for(int i=0; i<N; i++){
		std::cout<<parrents[i]<<" ";
	}
	std::cout<<"\n";

	return 0;

	delete [] distances;
	delete [] g;
	delete [] parrents;
}