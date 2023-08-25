#include <iostream>
#include <iomanip>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

struct Node *top = NULL;
struct Node *ptrCell = NULL;

int pop(){
	if(top!=NULL){
		int getData;
		getData = top->data;
		ptrCell = top;
		top = top->next;
		free(ptrCell);
		return getData;
	}
}

void push(int data){
	ptrCell = new Node;
	ptrCell->data = data;
	ptrCell->next = top;
	top = ptrCell;
}

void print(){
	if(top!=NULL){
		cout << "Top : " << top->data << endl;
		cout << "[ {cell: Alamat   }   Data | Next] " << endl; 
		
		ptrCell = top;
		do{
			cout << "[ {cell: " << ptrCell << "} " << setiosflags(ios::right) << setw(6) << ptrCell->data << " | " << ptrCell->next << ']' << endl;
			ptrCell = ptrCell->next;
		}while(ptrCell != NULL);
		cout << endl;
	}else{
		cout << "Stack is Empty" << endl;
	}

}
int main(){
	for(int i=0;i<10;i++){
		push(rand()); // rand() = Bilangan Random
	}
	print();
	system("pause");
	system("cls");
	cout << "Pop 5x times" << endl;
	for(int i=0;i<5;i++){
		pop();
	}
	print();	
	return 0;
}