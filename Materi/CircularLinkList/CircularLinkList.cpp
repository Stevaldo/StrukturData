#include <iostream>
#include <iomanip> /* Bisa mencari angka random menggunakan method rand() */
using namespace std;

struct mahasiswa{
	int data;
	mahasiswa *next , *prev;
};
mahasiswa *ptr , *head = NULL , *tail = NULL , *temp;
int n;

void addNode(int isi){
	if(head != NULL){
		temp = ptr;
		ptr->next = new mahasiswa;
		ptr = ptr->next;
		ptr->prev = temp;
		tail = ptr;
	}else{
		head = new mahasiswa;
		ptr = head;
		tail = ptr;
	}
	ptr->data = isi;
	ptr->next = head;
	head->prev = tail;
	n++;
}
/*Circular Linked List =  ptr->next terakhir menunjuk head dan head->prev menunjuk ptr->next terakhir*/
int main(){
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	if(head != NULL){
		ptr = head;
		for(int i=0;i<n;i++){
			cout << ptr->data << endl;	
			ptr = ptr->next;
		}
		ptr = tail;
		cout << "Head : " << head->data << endl;
		cout << "Tail : " << tail->data << endl;
		cout << "PTR Next : " << ptr->next->data << endl;
		cout << "PTR Prev : " << ptr->prev->data << endl;
		cout << "Head Next : " << head->next->data << endl;
		cout << "Head Prev : " << head->prev->data << endl;
	}
}