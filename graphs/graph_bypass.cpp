#include <iostream>
#include <queue>

void print_g (int* g, int N){

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			std::cout<<g[i*N+j]<<" ";
		}
		std::cout<<std::endl;
	}
}

int main(){

	int N, M;//число вершин и число ребер 
	std::cin>>N; 
	std::cin>>M;

	//считаем, что вершины заданы числами 0,1,...

	int* g = new int [N*N];

	for(int i=0; i<N*N; i++){
		g[i]=0;
	}

	for(int i=0; i<M; i++){

		int v1, v2;
		std::cin>>v1;
		std::cin>>v2;

		g[v1*N + v2] = 1;
		g[v2*N + v1] = 1;
	}

	print_g(g, N);

	int* nodes = new int [N];
	for(int i=0; i<N; i++){
		nodes[i]=0;
	}

	std::queue <int> Q;

	Q.push(0);

	while(!Q.empty()){

		int node = Q.front();
		Q.pop();
		nodes[node]=2;

		for(int j=0; j<N; j++){
			if(nodes[j]==0 and g[node*N + j]==1){
				Q.push(j);
				nodes[j]=1;
			}
		}

		std::cout<<node<<" ";
	}
	return 0;

}