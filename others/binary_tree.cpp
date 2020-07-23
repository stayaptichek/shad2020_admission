#include <iostream>
using namespace std;

struct Node{//структура вершины

	int Data;
	Node* LeftNode;
	Node* RightNode;
	Node* ParrentNode;

};

Node* getFreeNode(int aData, Node* aParrentNode){//Создаем вершину по значению и указателю на предок

	Node* temp = new Node;
	temp->Data = aData;
	temp->LeftNode = nullptr;
	temp->RightNode = nullptr;
	temp->ParrentNode = aParrentNode;

	return temp;

}

void insertNode(int aData, Node* root){//Вставка вершины с значением aData в дерево с корнем root

	while(root){

		if(aData > root->Data){

			if(root->RightNode == nullptr){
				root->RightNode =  getFreeNode(aData, root);
				return;
			}

			else{
				root = root->RightNode;
				continue;
			}
		}

		else{

			if(root->LeftNode == nullptr){
				root->LeftNode =  getFreeNode(aData, root);
				return;
			}

			else{
				root = root->LeftNode;
				continue;
			}

		}
	}

}

Node* getNodeByValue(int aData, Node* root){//получить указатель на вершину по значению


	while(root){
		if(root->Data<aData){
			root = root->RightNode;
			continue;
		}

		if(root->Data>aData){
			root = root->LeftNode;
			continue;
		}

		else{
			return root;
		}

	} 
	return nullptr;
}

Node* findMaxNode(Node* root){//ищем максимум по дереву

	while(root->RightNode){
		root = root->RightNode;
	}

	return root;
}

void removeNodeByPtr(Node* target){

	if(target->RightNode and target->LeftNode){//если есть два потомука, то находим max левого поддерева, кладем его значение в target и удаляем max
		
		Node* max = findMaxNode(target->LeftNode);
		target->Data = max->Data;
		removeNodeByPtr(max);
		return;
	}

	else if(target->RightNode){
			if((target->ParrentNode)->LeftNode == target){
				(target->ParrentNode)->LeftNode = target->RightNode;
			}

			else{
				(target->ParrentNode)->RightNode = target->RightNode;
			}
	}

	else if(target->LeftNode){
			if((target->ParrentNode)->LeftNode == target){
				(target->ParrentNode)->LeftNode = target->LeftNode;
			}

			else{
				(target->ParrentNode)->RightNode = target->LeftNode;
			}
	}
	else{
		if((target->ParrentNode)->LeftNode == target){
			(target->ParrentNode)->LeftNode = nullptr;
		}
		else{
			(target->ParrentNode)->RightNode = nullptr;
		}
	}

}

void removeNodeByValue(int aData, Node* root){//Удаление вершины по значению

	Node* temp = getNodeByValue(aData, root);
	removeNodeByPtr(temp);
	//removeNodeByPtr(temp);
}

int main(){

	Node* node = new Node;

	node = getFreeNode(4, nullptr);
	insertNode(5, node);
	insertNode(3, node);
	insertNode(6, node);

	cout<<getNodeByValue(4, node)->Data<<"\n";
	cout<<getNodeByValue(5, node)->Data<<"\n";
	cout<<getNodeByValue(3, node)->Data<<"\n";
	cout<<getNodeByValue(6, node)->Data<<"\n";

	removeNodeByValue(6, node);
	removeNodeByValue(5, node);

	cout<<getNodeByValue(4, node)->Data<<"\n";
	cout<<getNodeByValue(5, node)->Data<<"\n";
	cout<<getNodeByValue(3, node)->Data<<"\n";
	cout<<getNodeByValue(6, node)->Data<<"\n";

	/*
	cout<<"\n node->Data "<<node->Data;
	cout<<"\n node->Data"<<(node->RightNode)->Data;
	cout<<"\n node->Data"<<((node->RightNode)->RightNode)->Data;
	cout<<"\n node->Data"<<(node->LeftNode)->Data;
	*/

	return 0;
}




