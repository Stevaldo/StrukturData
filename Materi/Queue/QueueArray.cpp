#include <iostream>
#define size 3
using namespace std;

struct theCell{
	int dat;
};
theCell pool[size];
int dat_size = 0;
int first = -1;
int last = -1;

// Menyalin Elemen Pertama pada Queue
struct theCell firstEl(){ 
	struct theCell get;
	get.dat = pool[first].dat;
	return get;
}
 
// Menyalin Elemen Terakhir pada Queuea
struct theCell lastEl(){ 
	struct theCell get;
	get.dat = pool[last].dat;
	return get;
}

// Mengisi Element kedalam Queue
void enqueue(int data){ 

	if(dat_size > size-1){
		return;
	}else{
		if(first != 0){
			first++;
		}
		
		dat_size++;
		last = (first+dat_size-1)% size;
		pool[last].dat = data;
	}
}

// Mengeluarkan Element Pertama
struct theCell dequeue(){
	struct theCell get;
	get.dat = pool[first].dat;
	dat_size--;
	first = (first + 1)% size;
	return get;
}

// Mengecek apakah Queue Kosong
bool isEmpty(){
	if(dat_size == 0){
		return true;
	}else{
		return false;
	}
}

// Mengosongkan Queue
void clear(){
	while(!isEmpty()){ 
		dequeue();  
	}
	// Setting ke pengaturan Pabrik
	first = -1;
	last = -1;
	dat_size = 0;
}

// Mencetak Queue
void print(){
	if(!isEmpty()){
		for(int i=first;i<=last;i++){
			cout << "Data Queue [" << i << "]\t= " << pool[i].dat << endl;
		}
	}else{
		cout << "Queue is empty" << endl;
	}
}

int main(){
	// Mengisi Data Queue
	for(int i=0;i<5;i++)
	enqueue(rand());
	
	// Mengambil Elemen Pertama Queue
	struct theCell x = firstEl();
	cout << "First El : " << x.dat << endl << endl;
	// Mengambil Elemen Terakhir Queue
	struct theCell a = lastEl();
	cout << "Last El  : " << a.dat << endl << endl;
	print();
	
	// Mengosongkan isi Queue
	clear();
	cout <<  endl <<"After Clear" << endl;
	print();
	
	return 0;
	system("pause");
}