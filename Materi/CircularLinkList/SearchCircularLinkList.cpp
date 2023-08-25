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
	//Input Data
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	//Cetak Data
	if(head != NULL){
		cout << "Head : " << head->data << endl;
		ptr = head;
		for(int i=0;i<n;i++){
			cout << ptr->data << " Alamat = " << ptr << endl;	
			ptr = ptr->next;
		}
		cout << "Tail : " << tail->data << endl;
	}
	//Cek Data
	int cari ;
	bool check = false;
	cout << "Masukkan Data yang ingin di cari: "; cin >> cari;
	if(head!=NULL){
		ptr=head;
		for(int i=0;i<n;i++){
			if(ptr->data == cari){
				cout << "Data ditemukan pada Alamat ke " << ptr << endl;
				check = true;
			}	
			ptr = ptr->next;
		}
		if(check == false){
			cout << "Data tidak ditemukan" << endl;
		}
	}
}