//поиск числа компонент связности графа
//1) делеам обход в глубину, начиная со стартовой вершины, до тех пор, пока это возможно, запоминая пройденные вершины 
//2) берем любую непройденную вершину и продолжаем пункт 1
//обход в глубину используем из файла bfs.cpp


#include <iostream>
#include <queue>

int is_anything_not_pointed_in_used (int* used, int N){//проверяет, есть ли среди оставшихся вершин непройденные 

	for(int i=0; i<N; i++){
		if(used[i]==0){
			return i;//возвращаем первую из непройденных вершин
		}
	}
	return -1;
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
	int* used = new int[N];//массив посещенных вершин
	for(int i=0; i<N; i++){
		distances[i]=-1;
		used[i]=0;

	}
	distances[0]=0;

	std::queue <int> Q;//очередь для вершин 

	int N_comp = 0;//число компонент связности

	while(is_anylthing_not_pointed_in_used(used, N)!=-1){//до тех пор, пока есть непройденные вершины

		Q.push(is_anylthing_not_pointed_in_used(used, N));

		while (!Q.empty()){

			int cur_v = Q.front();
			used[cur_v]=1;
			Q.pop();

			for(int j=0; j<N; j++){
				if(g[cur_v*N +j]==1 and distances[j]==-1){
					distances[j] = distances[cur_v] + 1;
					Q.push(j);
				}
			}	
		}
		N_comp++;
	}

	std::cout<<"Число комопнент связности равно: "<<N_comp<<"\n";

	return 0;

}

