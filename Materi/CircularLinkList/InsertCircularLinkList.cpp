#include <iostream>
#include <iomanip>
using namespace std;

struct test{
	int data;
	test *next,*prev;
};

test *ptr , *head = NULL ,*tail = NULL , *temp ,*temp2;
int n;

void addNode(int isi){
	if(head != NULL){
		temp = ptr;
		ptr->next = new test;
		ptr = ptr->next;
		ptr->prev = temp;
		tail = ptr;
	}else{
		head = new test;
		ptr = head;
		tail = ptr;
	}
	ptr->data = isi;
	ptr->next = head;
	head->prev = tail;
	n++;
}

void insertNode(){
	if(head != NULL && tail != NULL){
		int isi , nodeke;
		cout << "Masukkan Angka yang ingin di-input : "; cin >> isi;
		cout << "Input setelah node ke-"; cin >> nodeke;
		
		if(nodeke == 0){
			ptr = new test;
			temp = head;
			ptr->prev = temp->prev;
			temp->prev = ptr;
			ptr->next = temp;
			ptr->data = isi;
			head = ptr;
			tail->next = head;
			n++;
		}else if(nodeke>0 && nodeke <n){
			temp = head;
			for(int i=0;i<nodeke-1;i++){
				temp = temp->next;
			}
			temp2 = head;
			for(int i=0;i<nodeke;i++){
				temp2 = temp2->next;
			}
			ptr = new test;
			ptr->next = temp2;
			ptr->prev = temp;
			temp->next = ptr;
			temp2->prev = ptr;
			ptr->data = isi;
		
			n++;
		}else if(nodeke == n){
			addNode(isi);
		}
	}else{
		cout << "Gunakan Method addNode terlebih dahulu" << endl;
	}
}

void print(){
		if(head != NULL){
		ptr = head;
		cout << endl;
		for(int i=0;i<n;i++){
			cout << ptr->data << endl;	
			ptr = ptr->next;
		}
		cout << endl;
		ptr = tail;
		cout << "Head : " << head->data << endl;
		cout << "Tail : " << tail->data << endl;
		cout << "PTR Next (Tail Next) : " << ptr->next->data << endl;
		cout << "PTR Prev (Tail Prev) : " << ptr->prev->data << endl;
		cout << "Head Next : " << head->next->data << endl;
		cout << "Head Prev : " << head->prev->data << endl << endl;
	}
}

int main(){
	// Masukkan Data agar membentuk head dan tail terlebih dahulu
		addNode(rand());
		addNode(rand());
		addNode(rand());
		
		print();
	//Sisipkan Data
		insertNode();
	
		print();
}
	
