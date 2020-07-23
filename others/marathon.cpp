#include <iostream>
#include <string>
#include <vector>
#include <set>


int main(){

	int Q;//натуральное число запросов \leq 10^6 
	std::cin>>Q;

	std::set<int> runners; // множество бегунов 
	std::vector<int> runners_distance (100000, 0);//такой вектор, что его i-й элемент равен расстоянию, который пробежал бегун под номером i
	std::vector<int> special_runners_number (42195, 0); //такой вектор, что его i-й элемент равен числу бегунов, которые пробежали \geq i метров



	for(int i=0; i<Q; i++){

		std::string s;//строка для чтения 
		std::cin>>s;

		
		if(s == "CHEER"){

			int user;
			std::cin>>user;

			if((runners.count(user)!=0) and (runners.size()==1)){
				std::cout<<"1"<<std::endl;
			}

			else{
				if(runners.count(user)==0){
					std::cout<<"0"<<std::endl;
				}

				else{

					double percentage  = (runners.size()-special_runners_number[runners_distance[user]])*1.0/(runners.size()-1);
					std::cout<<percentage<<std::endl;

				}
			}
		}

		if(s == "RUN"){

			int user;
			int page;

			std::cin>>user>>page;


			if(runners.count(user)==0){
				runners.insert(user);
				
			}

			for(int i=runners_distance[user]+1; i<=page; i++){
				special_runners_number[i]++;
			}
			runners_distance[user]=page;

		}


	}

	return 0;
	
}