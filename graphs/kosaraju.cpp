//АЛГОРИТМ ПОИСКА ОБЛАСТЕЙ СИЛЬНОЙ СВЯЗАННОСТИ В ОРИЕНТИРОВАННОМ ГРАФЕ
//Не доделан(((((

//Компонентами сильной связности орграфа называются его максимальные по включению сильно связные подграфы. 
//Областью сильной связности называется множество вершин компоненты сильной связности.

//Алгорритм заключается в:
//1)применении обхода в глубину (dfs) начиная со всех непомеченных вершин (записываем в стек все пройденные вершины)
//2) запускаем алгоритм обхода в глубину (dfs) по порядку для всех вершин из стека
//3) получаем множества 

#include <iostream>
#include<stack>

void dfs(int vertex, int* g, int* used, int N, std::stack<int> * S, int param){

	used[vertex]=1;
	//if(param==0){
	//std::cout<<vertex<<" ";
	//}

	for(int i=0; i<N; i++){

		if(param==1){

			if(g[vertex*N + i]==1 and used[i]==0){

				(*S).push(i);
				dfs(i, g, used, N, S, 1);
			}

		}

		else{
			if(g[i*N + vertex]==1 and used[i]==0){

				std::cout<<i<<"!";
				(*S).pop();
				dfs(i, g, used, N, S, 0);
			
			}
		}
	}

	//if(param==0 and (*S).top()==vertex){
	//	(*S).pop();
	//}

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
			S.push(i);
			dfs(i, g, used, N, &S, 1);
		}
	}

	for(int i=0; i<N; i++){
		used[i]=0;
	}

	for(int i=0; i<N; i++){

		//std::cout<<"Элемент стэка: "<<S.top()<<";";
		if(used[i]==0){

		int temp = S.top();
		std::cout<<S.top()<<" ";
		S.pop();
		dfs(temp, g, used, N, &S, 0);

		}

	}
	

	while(!S.empty()){
		std::cout<<S.top()<<" ";
		S.pop();
	}
	

	return 0;

	delete[] used;
	delete[] g;
}