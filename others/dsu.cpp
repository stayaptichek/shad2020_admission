/*
DSU (Disjoint-Set-Snion) - система неперескающихся множеств

базовый интерфейс программы строится с помощью трёх операций:
1) добавляет элемент x, помещая его в множество, состоящее из него одного
2) объединяет два указанных множества по элементам x,y
3) возвращает, в каком множестве находится указанный элемент 

Утверждается, что каждая из трех операций может быть реализована за O(1) операций

Построение эфективнйо структуры данных строится на том, чтобы хранить каждое множество в виде дерева,
корень деререва - его представитель 
Создаём массив parent и для каждого элемента храним ссылку на его предка (предок для лидера - он сам)

*/

#include <iostream>

void make_set(int v, int* parent, int* size){//создаем множество из одного элемента

	parent[v] = v;
	size[v]=1;
}

int find_set(int v, int* parent){

	if(parent[v]==v){
		return v;
	}

	return parent[v]=find_set(parent[v], parent);//позволяет добиться O(log n) для одного прохода 
}

void union_sets (int v, int w, int* parent, int* size){

	int v_lead;
	int w_lead;

	v_lead = find_set(v, parent);
	w_lead = find_set(w, parent);

	if(v_lead != w_lead){

		if(size[v_lead]<size[w_lead]){

			parent[v_lead] = w_lead;
			size[w_lead] = size[w_lead] + size[v_lead];

		}
	}
}

int main(){

	int N; 
	std::cin>>N;

	int* parent = new int [N];
	int* rank = new int [N];

	for(int i=0; i<N; i++){
		parent[i]=i%10;
		std::cout<<parent[i]<<" ";
	}

	std::cout<<"\n";

	std::cout<<find_set(13, parent)<<"\n";

	union_sets(2,3,parent);


	for(int i=0; i<N; i++){
		std::cout<<parent[i]<<" ";
	}
	return 0;
}