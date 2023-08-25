#include <iostream>
#include <cstdlib> /* Library untuk free() */
#include <iomanip> /* Bisa mencari angka random menggunakan method rand() */
using namespace std;

struct mahasiswa{
	int data;
	mahasiswa *next , *prev;
};
mahasiswa *ptr , *head = NULL , *tail = NULL , *temp , *temp2;
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

void deleteNode(int nodeke){
	if(head != NULL){
		if(nodeke == 1){
			temp = head->next;
			temp->prev = head->prev;
			temp = head;
			head = temp->next;
			free(temp);
			n--;
		}else if(nodeke>1 && nodeke <n){
			ptr = head;
			for(int i=0;i<nodeke-1;i++){
				ptr = ptr->next;
			}
			temp = ptr->prev;
			temp2 = ptr->next;
			temp->next = temp2;
			temp2->prev = temp;
			free(ptr);
			n--;
		}else if(nodeke == n){
			temp=head;
			while(temp->next != tail){
				temp = temp->next;
			}
			tail = temp;
			ptr = temp->next;
			free(ptr);
			temp->next = head;
			head->prev = tail;
			n--;
		}else{
			cout << "Node ke-" << nodeke << " tidak ditemukan" << endl;
		}
	}
}
void print(){
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
		cout << "Head Prev : " << head->prev->data << endl << endl;
	}
}

/*Circular Linked List =  ptr->next terakhir menunjuk head dan head->prev menunjuk ptr->next terakhir*/
int main(){
	addNode(rand());
	addNode(rand());
	addNode(rand());
	addNode(rand());
	addNode(rand());
	addNode(rand());
	print();
	
	int nodeke;
	cout << "Delete Node ke-";  cin >> nodeke;
	deleteNode(nodeke);
	print();
}