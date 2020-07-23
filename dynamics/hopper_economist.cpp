//Динамическое программирование 

//Кузнечику, который находится в точке 1, за один шаг пожно прыгать на 1м или на 2м. 
//За нахождение в каждой точке i кузнечик должен платить стоимость p_i 
//Требуется посчитать минимальную стоимость, которую кузнечику придется заплатить, чтобы попасть из точки 1 в точку n

#include <iostream>

using namespace std;



int min_cost(int n, int price[]){

	int cost[n+1];
	int result;

	cost[1] = price[1];
	cost[2] = price[2];

	for(int i=3; i<=n; i++){

		cost[i] = min(cost[i-1], cost[i-2]) + price[i];

	}

	cout<<"Min cost path reversed = ["<<n<<" ";
	int current = n;
	while(current!=1){
		if(cost[current-1]==cost[current]-price[current]){
			current = current -1;
		}

		else{
			if(cost[current-2]==cost[current]-price[current]){
				current = current -2;
			}

			else{

				throw -1;//I should never achieve this line!

			}
		}

		cout<<current<<" ";
	}
	cout<<"]"<<endl;

	result = cost[n];

	return result;

}

int main(){

	int n;
	cout<<"Hooper economist wants to go from point 1 to point n. Enter n: "<<endl;
	cin>>n;

	if(n>100){
		cout<<"Your number is too big! maximum is 100! "<<endl;
		return -1;
	}

	int price [101];

	cout<<"Enter prices of visiting point (from point 1 to point n)"<<endl;
	for(int i=1; i<n+1; i++){
		cin>>price[i];
	}
	int res = min_cost(n, price);
	cout<<"Min cost of achieveing point n from point 1 is "<<res<<endl;


}



