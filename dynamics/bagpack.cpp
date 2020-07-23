//Задача об улкадке рюкзака

//есть предметы масс и ценностей: (m_1, v_1), ..., (m_n, v_n)
//найти максимальную суммарную ценность, если рюзак расчитан максимум на K кг.


#include <iostream>
#include <vector>


double max_bagpack_value(std::vector<std::pair<int, double> > treasures, int capacity){

	std::vector<std::vector<double> > F;
	F.resize(capacity+1);

	for(int k=0; k<capacity+1; k++){
		F[k].resize(treasures.size()+1);
	}

	//base cases
	for(int k = 0; k<= capacity; k++){
		F[k][0]=0;
	}
	for(int j = 0; j<= treasures.size(); j++){
		F[0][j]=0;
	}



	//recursive case	
		for(int j=0; j<treasures.size()+1; j++){
			int weight = treasures[j-1].first;
			double value = treasures[j-1].second;
			for(int k=1; k<weight; k++){
				F[k][j] = std::max(F[k][j-1], value + F[k-weight][j-1]);
			}
		}
	

	return F[capacity][treasures.size()];


}

int main(){

	int treasures_number;
	std::cout<<"Enter number of treasures: ";
	std::cin>>treasures_number;

	std::vector<std::pair<int, double> > treasures;
	std::cout<<"Enter treasures: ";

	for(int i=0; i<treasures_number; i++){
		int weight;
		double value;
		std::cin>>weight>>value;

		treasures.push_back(std::make_pair(weight, value));

	}


	int capacity;
	std::cout<<"Enter bagpack capacity: ";
	std::cin>>capacity;

	std::cout<<max_bagpack_value(treasures,capacity);

}

