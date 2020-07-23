//ПОИСК ПОДСТРОКИ В СТРОКЕ 

//Если требуется найти подтроку a длины M в строке A длины N, то 
//если пользоваться НАИВНЫМ ПОИСКОМ (двигать a в A и проверять), то 
//сложность будет O(M*(N-M+1)) - ТАК НЕ ХОТИМ 

//Будем юзать динамическое программирование и построим \Pi-функцию строки

//Собственный суффикс строки -  суффикс, не совпадающий со всей строкой 
// У строки 'abc' суффиксы 'c', 'bc', но НЕ 'abc'

// \Pi - функция - максимальная длина собсвтенного суффикса, совпадающего с
//префиксом 

// \Pi('aba') = 1, \Pi('abacaba') = 3

#include <iostream>
#include <string>
#include <vector>

std::vector<int> prefix_function_kmp (std::string s){

	int n = s.length();
	std::vector<int> pi(n,0);

	for(int i=1; i<n; i++){

		int k = pi[i-1];

		while(k>0 and s[i]!=s[k]){
			k = pi[k-1];
		}

		if(s[i]==s[k]){
			k+=1;
		}
		pi[i]=k;
	}

	return pi;
}



int main(){

	std::string line;
	getline(std::cin, line);
	std::string tmp;
	getline(std::cin, tmp);
	std::string summary = tmp + '#' + line;

	std::vector<int> pi = prefix_function_kmp(summary);

	int counter=0;

	for(int i=0; i<pi.size(); i++){

		if(tmp.size() == pi[i]){
			counter++;
		}
	}

	std::cout<<"Number of cases template substring in string = "<<counter<<std::endl;

	return 0;

}

