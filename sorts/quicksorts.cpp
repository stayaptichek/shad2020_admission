#include <iostream>


void input_array(double *array, int array_size){

	for(int i=0; i<array_size; i++){
		std::cin>>array[i];
	}
}

void print_array(double *array, int array_size)
{
	for(int i=0; i<array_size; i++){
		std::cout<<array[i]<<" ";
	}
	std::cout<<std::endl;

}

/*
Сортировка слиянием

сортирующее действие - после ухода в рекурсию
сложность O(n log n)
память O(n)

*/

void merge_sort(double *array, int array_size)
{

	if(array_size<=1){//base case of recursion 
		return;
	}

	int middle = array_size/2;
	double* left = array;
	double* right = array + middle;

	merge_sort(left, middle);
	merge_sort(right, array_size-middle);//pointer + number = shifted pointer 

	//Merge these two sorted parts
	double* buffer = new double [array_size];

	int left_current=0;
	int right_current=0; 
	int buffer_current=0;

	while(left_current<middle and right_current<array_size-middle){
		{
			if (left[left_current] <= right[right_current] ){
				//taking from left part
				buffer[buffer_current] = left[left_current];
				left_current++;
				buffer_current++;
			}
			else{
				//taking from right part
				buffer[buffer_current] = right[right_current];
				right_current++;
				buffer_current++;
			}
		}

	}

	while(left_current < middle){//copying left elements from the left size if there is left something
		buffer[buffer_current] = left[left_current];
		left_current++;
		buffer_current++;
	}

	while(right_current < array_size-middle){//copying right elements from the right size if there is left something
		buffer[buffer_current] = right[right_current];
		right_current++;
		buffer_current++;
	}

	for(int i=0; i<array_size; i++){
		array[i] = buffer[i];
	}

	delete[] buffer;

}

/*
Сортировка Тони Хоара

сортирующее действие - до ухода в рекурсию 

Худшая сложность O(n^2) - если каждый раз выбирается наименьший элемент
W(nlogn) - средняя вероятностная сложность


*/



const int MAX_ARRAY_SIZE = 100000;

 int main()
 {

	int array_size;
	std::cout<<"Enter size of array: ";
	std::cin>>array_size;

	if(array_size<0 or array_size>MAX_ARRAY_SIZE){
		std::cerr<<"Your array size is unacceptable!";
		return 1;
	}

	double *array = new double [array_size];

	input_array(array,array_size);
	merge_sort(array,array_size);
	print_array(array,array_size);

	delete[] array;
 	return 0;
 }