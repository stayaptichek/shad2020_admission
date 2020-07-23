#include <iostream>
#include <list>
#include <string>
#include <vector>

void list_example(){

	std::list<std::string> words;
	std::string word;

	getline(std::cin, word);

	while(word != ""){
		words.push_back(word);
		getline(std::cin, word);
	}

	std::list<std::string>::iterator p;

	for(p=words.begin(); p!=words.end(); p++){
		std::cout<<*p<<"\t";
	}
	std::cout<<std::endl;


}

void vector_example(){

	std::vector<std::string> words;
	std::string word;

	getline(std::cin, word);

	while(word != ""){
		words.push_back(word);
		getline(std::cin, word);
	}

	for(int i=0; i<words.size(); i++){
		std::cout<<words[i]<<"\t";
	}
	std::cout<<std::endl;


}

int main(){

	list_example();
	//vector_example();

	return 0;
}