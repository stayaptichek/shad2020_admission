//Алгоритм Левентейна вычисления расстояния между строчками 

//Расстояние Левенштейна:

//Редакционные ошибки: 1)добавление 2)удаление 3)замена

//Для определения расстояния Левенштейна необходимо двумерное динамическое программирование 

//L_{6,6}=L('string', 'master') = ?

//Пусть известны L('strin', 'master'), L('string', 'maste'), L('strin', 'maste') 

/*
           L_{i-1, k-1}, если a[i-1] = b[i-1], то есть последние символы равны (i-1 так как индексация с 0!!!)
         /
L{i,k} = 
         \
           min(L_{i-1,k}, L_{i, k-1}) + 1, если a[i-1] =/= b[i-1]
*/

#include <iostream>
#include <vector>

int levenstein_distance(std::string a, std::string b){

	std::vector<std::vector<int> > L;

	L.resize(a.length()+1);

	for(int i=0; i<=a.length(); i++){
		L[i].resize(b.length()+1);
	}

	//base cases
	for(int i=0; i<=a.length(); i++){
		L[i][0]=i;
	}

	for(int k=0; k<=b.length(); k++){
		L[0][k]=k;
	}

	//recursive cases
	for(int i=1; i<=a.length(); i++){
		for(int k=0; k<=b.length(); k++){

			if(a[i-1] == b[k-1]){
				L[i][k] = L[i-1][k-1];
			}

			else{
				L[i][k] = std::min(std::min(L[i-1][k], L[i][k-1]), L[i-1][k-1])+1;
			}
		}
	}
	return L[a.length()][b.length()];
}


int main(){

	std::string a,b;
	std::cout<<"Enter string A \n";
	std::cin>>a;
	std::cout<<"Enter string B \n";
	std::cin>>b;

	std::cout<<"Levenstein distance between A and B = "<<levenstein_distance(a,b)<<std::endl;
	return 0;

}




