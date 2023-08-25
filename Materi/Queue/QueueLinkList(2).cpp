#include <iostream>
#include <iomanip>
using namespace std;

//Record Definition
struct theCell{
	int dat;
	struct theCell *next;
	struct theCell *prev;
};

//Head sebagai fist, tail sebagai last
struct theCell *head = NULL, *tail = NULL, temp;

struct theCell dequeue(){
	struct theCell temp;
	temp.dat = head->dat;
	if (head->next == NULL){
		free(head);
		head = NULL;
		tail = NULL;
	}
	else {
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
	return temp;
}

bool isEmpty(){
	if (head == NULL)
	return true;
	else 
	return false;
}

void clear(){
	while (head!=NULL){
		dequeue(); //memanfaatkan dequeue untuk mengosongkan queue
	}
}

void tampilkan(){
	//Menampilkan Isi Linked List dari awal
	if (head!=NULL){
		cout << "Kepala : " << head << endl;
		cout << "Ekor : " << tail << endl;
		cout << "[sebelum | {cell: Alamat} Data | berikut]" << endl;
		//Arahkan tail ke alamat yang ditunjuk oleh kepala 
		tail = head;
		do{
			//Tampilkan isi Node/Simpul
			cout << "[" << setiosflags(ios::right) << setw(10) << tail->prev << " | {cell: "<<tail<<"} " << tail->dat << setiosflags(ios::right) << setw(10) << tail->next << "]" << endl;
			//Arahkan tail ke node/simpul berikutnya
			tail = tail->next;
		} while (tail != NULL); //keluar dari loop ketika ptrCell menunjukkan alamat ekor
		cout << endl << endl;
	}
	else {
		cout << "Queue Empty" << endl;
	}
}

//Program Utama
int main(){
	menu :
	int i, pilihan, data;
	
	cout << "===============================" << endl;
	cout << "1. Tambah Data ke Queue" << endl;
	cout << "2. Keluarkan Data dari Queue" << endl;
	cout << "3. Tampilkan Data Teratas Pada Queue" << endl;
	cout << "4. Bershikan Queue" << endl;
	cout << "5. Check Queue Apakah Kosong" << endl;
	cout << "6. Tampilkan Isi Queue" << endl;
	cout << "7. Keluar" << endl;
	cout << "Masukkan Pilihan : ";
	cin >> pilihan;
	
	switch(pilihan){
		case 1 : {
			cout << "Masukkan Data ke Queue : ";
			cin >> data;
			if (head==NULL){
			tail = (struct theCell *) malloc(sizeof(struct theCell));
			head = tail; 
			head->prev = NULL;
		}
		else{
			tail->next = (struct theCell *) malloc(sizeof(struct theCell));
			tail->next->prev = tail;
			tail = tail->next;
		}
		tail->dat = data;
		tail->next = NULL;
			goto menu;
			cout << endl;
		}
		case 2 : {
			dequeue();
			goto menu;
			cout << endl;
		}
		case 3 : {
			tampilkan();
			goto menu;
			cout << endl;
		}
		case 4 : {
			clear();
			goto menu;
			cout << endl;
		}
		case 5 : {
			if (isEmpty())
			cout << "Queue Kosong" << endl;
			else
			cout << "Queue Tidak Kosong" << endl;
			goto menu;
			cout << endl;
		}
		case 6 : {
			tampilkan();
			goto menu;
			cout << endl;
		}
		case 7 : {
			exit (0);
			break;
		}
		default : {
			cout << "Tolong Masukkan Angka Dengan Benar";
			break;
		}
	}
	return 0;
}