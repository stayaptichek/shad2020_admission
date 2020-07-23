//ОБХОД ГРАФА В ГЛУБИНУ

//Алгоритм:
//1) выбираем текущую вершину стартовой
//2) для текущей вершины берем ее соседа и завем на ДР, сосед в свою очередь берет своего соседа и зовет на  ДР
//   и так далее
//3) если у вершины нет еще не позванного соседа, то он никого не зовет и говорит тому, кто его позвал, что он сам пойдет
//4) таким образом каждый не может пойти на ДР, пока не пойдут все его друзья!

//C помощью него ищем числок компонент связности

#include <iostream>

void dfs(int vertex, int* g, int* used, int N){

	used[vertex]=1;

	for(int i=0; i<N; i++){
		if(g[vertex*N + i]==1 and used[i]==0){
			dfs(i, g, used, N);
		}
	}

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

	int* used = new int [N];

	for(int i=0; i<N; i++){
		used[i]=0;
	}


	int N_comp=0;//число компонент связности
	for(int i=0; i<N; i++){
		if(used[i]==0){
			dfs(i, g, used, N);
			N_comp+=1;
		}
	}

	std::cout<<"Число комопнент связности равно: "<<N_comp<<"\n";
	return 0;

	delete[] used;
	delete[] g;
}

