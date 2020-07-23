//Однносвязный список
#include <iostream>


struct list{

	int data;
	list* pointer;
};


void bypass(list* start_node){


	while(start_node){
		std::cout<<start_node->data<<" ";
		start_node=start_node->pointer;
	}

}

int main(){

	int N;
	N=10;
	list* start_node = new list;
	list* temp = start_node;

	for(int i=0; i<N; i++){

		temp->data = i;
		temp->pointer = new list;
		temp=temp->pointer;
	}

	temp->pointer = nullptr;
	bypass(start_node);

	delete temp;
	delete start_node;

	return 0;
}

