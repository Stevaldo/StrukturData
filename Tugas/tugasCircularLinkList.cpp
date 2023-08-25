#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct test{
	int data;
	test *next,*prev;
};

test *ptr , *head = NULL ,*tail = NULL , *temp ,*temp2;
int n;

void addNode(){
	int node , isi;
	cout << "Masukkan Jumlah Node yang ingin dibuat : "; cin >> node;
	
	for(int i=0;i<node;i++){
	cout<< "Data Node ke-"<< i+1 <<" : "; cin >> isi;
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
}

void print(){
		if(head != NULL){
		ptr = head;
		for(int i=0;i<n;i++){
			cout << "Node ke-"<< i+1 <<"[ (cell : " << ptr <<") " << setiosflags(ios::right) << setw(6) << ptr->data
			<< " | " << ptr->next << endl;
			ptr = ptr->next;
		}
		cout << endl;
		}else{
			cout << "Data Masih Kosong" << endl;
		}
}


void deleteNode(){
	if(head != NULL){
		int nodeke;
		cout << "Hapus data Node ke-"; cin >> nodeke;
		if(nodeke == 1){
			temp = head->next;
			temp->prev = head->prev;
			temp = head;
			head = temp->next;
			free(temp);
			n--;
			print();
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
			print();
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
			print();
		}else{
			cout << "Node ke-" << nodeke << " tidak ditemukan" << endl;
		}
	}
}

void searchNode(){
	int cari ;
	bool check = false;
	cout << "Masukkan Data yang ingin di cari: "; cin >> cari;
	if(head!=NULL){
		ptr=head;
		for(int i=0;i<n;i++){
			if(ptr->data == cari){
				cout << "Data "<< cari <<" ditemukan pada Alamat ke " << ptr << endl;
				check = true;
			}	
			ptr = ptr->next;
		}
		if(check == false){
			cout << "Data tidak ditemukan" << endl;
		}
	}
}

void ubahNode(){
	if(head != NULL){
		int cari ;
		bool check = false;
		cout << "Masukkan Data yang ingin di ubah : "; cin >> cari;
		
	
		ptr=head;
		for(int i=0;i<n;i++){
			if(ptr->data == cari){
				cout << "Data "<< cari <<" ditemukan pada Alamat ke " << ptr << endl;
				check = true;
				goto next;
			}	
			ptr = ptr->next;
		}
		
		next:
		if(check == false){
			cout << "Data tidak ditemukan" << endl;
		}else{
			cout << "Masukkan Data baru : "; cin >> ptr->data;
		}
		
	}
}
int main(){
	char pilihan;
	menu:
	system("cls");
	cout << "Circular Linked List Menu" << endl;
	cout << "1. Isi Linked List" << endl;
	cout << "2. Tampilkan isi Linked List" << endl;
	cout << "3. Search Node" << endl;
	cout << "4. Hapus Data" << endl;
	cout << "5. Ubah Data" << endl;
	cout << "6. Keluar" << endl;
	cout << "Option : ";
	pilihan = getch();
	if(pilihan == '1'){
		system("cls");
		addNode();
		print();
		cout << "Press any key to continue...";
		getch();
		goto menu;
	}else if(pilihan == '2'){
		system("cls");
		print();
		cout << "Press any key to continue...";
		getch();
		goto menu;
	}else if(pilihan == '3'){
		system("cls");
		searchNode();
		cout << "Press any key to continue...";
		getch();
		goto menu;
	}else if(pilihan == '4'){
		system("cls");
		print();
		deleteNode();
		cout << "Press any key to continue...";
		getch();
		goto menu;
	}else if(pilihan == '5'){
		system("cls");
		ubahNode();
		print();
		cout << "Press any key to continue...";
		getch();
		goto menu;
	}else if(pilihan == '6'){
		cout << "Keluar dari program...";
		exit(0);
	}else{
		system("cls");
		cout << "Inputan tidak valid harap masukkan angka 1-6 saja" << endl;
		goto menu;
	}
}
	
