/*
	Куча -  это специализированная структура данных типа дерево, 
	которая удовлетворяет свойству кучи: если B является узлом-потомком узла A, то ключ(A) \geq ключ(B)
	(либо всегда наоборот ключ(A) \leq ключ(B) )

	Двоичная куча или пирамида  — такое двоичное подвешенное дерево, для которого выполнены следующие три условия:
	а) Значение в любой вершине не больше (если куча для минимума), чем значения её потомков.
	б) На i-ом слое 2^i вершин, кроме последнего. Слои нумеруются с нуля.
	в) Последний слой заполнен слева направо 

	Для дальнейших рассуждений необходимо определить две операции, которые
	применяются, когда какой-то элемент в куче меняется

	1] siftDown (просеивание вниз) применяется, если элемент кучи увеличивается:

	пусть i-й элемент увеличился, тогда если он до сих пор \leq обеих его потомков, то ничего не делаем
	если же он стал больше какого-то из потомков, то меняем его с минимальным из потомков местами и вызываем 
	функцию siftDown от этого потомка 

	сложность O(log n)

	2] siftUp (просеивание вверх) применяется, если элемент кучи уменьшается: 

	пусть i-й элемент уменьшился, тогда если он до сих пор \geq своего предка, то ничего не делаем
	если же он стал меньше предка, то мы меняем местами его и отца и далем то же самую процедуру для отца

	сложность O(log n)


	ЗАДАЧА: по заданному массиву A построить кучу.

	Можно организовать построение кучи естественным путем: 
	поместим A[0] в корень (считаем, что его потомки это +\inf), дальше будем добавлять последовательно элементы 
	A[1], A[2], ... в кучу и применять к каждому добавленному siftUp
	Сложность этой программы O(n*log n), так как нужно добавить n-1 элемент и к каждому применить siftUp

	Попробуем построить кучу за O(n) 

	для n/d вершин применим siftDown
	тогда сложность будет O(n)

	Далее реализуем сортировку кучей (heapSort)
	Она работает за O(n log n) всегда и не требует доп памяти
	

*/

#include <iostream>
#include <cmath>

void siftDown (int i, int n, int* heap){

	while(2*i+1<n){

		int left_son = heap[2*i + 1];
		int right_son = heap[2*i + 2];

		if(heap[i]<left_son and heap[i]<right_son){
			break;
		}

		if(left_son<right_son){
			heap[2*i+1] = heap[i];
			heap[i] = left_son;
			i=2*i+1;
		}

		else{
			heap[2*i+2] = heap[i];
			heap[i] = right_son;
			i=2*i+2;
		}

	}
} 

void siftUp(int i, int n, int* heap){

	while(heap[i]<heap[(i-1)/2]){
		int temp = heap[(i-1)/2];
		heap[(i-1)/2] = heap[i];
		heap[i] = temp;

		i = (i-1)/2; 
	}
}

void buildHeap(int* heap, int n){

	for(int i=n/2; i>=0; i--){//цикл бежит за O(n)

		siftDown(i, n, heap);//функция работает за O(log n)

	}
}

int extractMin(int* heap, int* n){

	int min = heap[0];

	heap[0]=heap[(*n)-1];
	(*n) = (*n)-1;

	siftDown(0,*n,heap);

	return min;

}

void printHeap(int* heap, int n){

	std::cout<<"Куча: \n";

	for (int i = 0; i < log(n)+1; i++) {
        for(int j = 0; j < pow(2, i) && j + pow(2, i) < n + 1; j++) {
            std::cout << (heap[j + (int)pow(2, i) - 1]) << " ";
        }
        std::cout << std::endl;
    }
}

void heapSort(int* heap, int* n){

	int size = *n;

	for(int i=0; i<size; i++){
		int min = extractMin(heap, n); 
		//std::cout<<" "<<*n<<" ";
		heap[*n]=min;
	}

}



int main(){

	int N = 10000;//больше этого числа куча быть не может
	int n;//реальый размер кучи

	std::cout<<"Введите размер кучи "<<std::endl;
	std::cin>>n;

	int* heap = new int[N];

	for(int i=0; i<N; i++){
		heap[i]=rand()%1000;
	}

	buildHeap(heap, n);

	printHeap(heap, n);
	int size = n;//сохраним размерчик
	
	heapSort(heap, &n);

	for(int i=0; i<size/2; i++){
		int temp = heap[i];
		heap[i] = heap[size-i-1];
		heap[size-i-1] = temp;
	}

	std::cout<<"Отсортированный массив: ";

	for(int i=0; i<size; i++){
		std::cout<<heap[i]<<" ";
	}

	return 0;

}