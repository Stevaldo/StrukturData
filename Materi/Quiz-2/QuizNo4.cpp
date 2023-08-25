#include <iostream>
#include <iomanip>
using namespace std;

// Stack
struct Node{
	int data;
	struct Node *next;
};

struct Node *top = NULL;
struct Node *ptrCell = NULL;

// Binary tree
struct theCell{
	int dat;
	struct theCell *kiri , *kanan , *parent;
};

struct theCell *ptrCellBinary , *rootCell = NULL , *baru;

void inputBinaryTree(int data){
	baru =  new theCell;
	baru->dat = data;
	baru->kanan = NULL;
	baru->kiri = NULL;
	
	if(rootCell == NULL){
		rootCell = baru;
		rootCell->parent = NULL;
	}else{
		ptrCellBinary = rootCell;
		
		while(ptrCellBinary != baru){
			
			// Implementasi Left to Right Order
			if(ptrCellBinary->dat > baru->dat){ // Jika Data baru lebih kecil dari Root maka Masukkan ke Kiri
				// Jika Kiri Kosong maka masukkan data kekiri
				baru->parent = ptrCellBinary;
				if(ptrCellBinary->kiri == NULL){
					ptrCellBinary->kiri = baru;
				}
				ptrCellBinary = ptrCellBinary->kiri;
			}else{ // Jika Data baru lebih besar / sama dengan root maka masukkan ke Kanan
				// Jika kanan Kosong maka masukkan data kekanan
				baru->parent = ptrCellBinary;
				if(ptrCellBinary->kanan == NULL){
					ptrCellBinary->kanan = baru;
				}
				ptrCellBinary = ptrCellBinary->kanan;
			}
		}
	}	
}

int pop(){
	if(top!=NULL){
		int getData;
		getData = top->data;
		ptrCell = top;
		top = top->next;
		free(ptrCell);
		return getData;
	}else{
		return 0;
	}
}

void push(int data){
	// Jika top tidak kosong
	if(top != NULL){
		// Jika data top lebih kecil dari Data baru
		if(top->data < data){
			// Push data baru seperti biasa
			ptrCell = new Node;
			ptrCell->data = data;
			ptrCell->next = top;
			top = ptrCell;
			cout << "Data " << data << " berhasil dimasukan kedalam Stack" << endl;
		}else{
			// Jika data top lebih besar dari Data baru
			// Keluarkan data pada top terlebih dahulu
			int x = pop();
			// Masukan data baru
			ptrCell = new Node;
			ptrCell->data = data;
			ptrCell->next = top;
			top = ptrCell;
			// Masukan data yang tadi dikeluarkan pada top kedalam Binary Tree
			inputBinaryTree(x);
			cout << "Data " << data << " berhasil dimasukan kedalam stack, tetapi Data " << x << " akan dipindahkan ke Binary Tree" << endl;
		}
	}else{
	    ptrCell = new Node;
		ptrCell->data = data;
		ptrCell->next = top;
		top = ptrCell;
		cout << "Data " << data << " berhasil dimasukan kedalam Stack" << endl;
	}

}

void preOrderTrav(struct theCell *travCell){
	// V:
	cout << travCell->dat << " | ";
	// L:
	if(travCell->kiri != NULL)
	preOrderTrav(travCell->kiri);
	// R:
	if(travCell->kanan != NULL)
	preOrderTrav(travCell->kanan);
}

int main(){	
	// Inisialisasi Data
	int size = 20;
	int a[size] = {12,35,41,23,22,10,99,21,50,40,39,48,24,11,66,51,55,44,33,22};
	cout << "Data awal : [ ";
	for(int i=0;i<size;i++)
	cout << a[i] << ' ';
	cout << ']' << endl << endl;
	
	// Push Data diatas kedalam stack sesuai dengan method push()
	cout << "Saring Data sesuai dengan metode yang diberikan : " << endl;
	for(int i=0;i<size;i++){
	  push(a[i]);
	}
	cout << endl << endl;
	
	// pop data yang tersisa pada stack kemudian susun kedalam binary tree
	cout << "Pindahkan data yang berhasil diupdate kedalam stack kedalam binary tree" << endl;
	while(top != NULL){
		int z =	pop();
		cout << z << " | ";
		inputBinaryTree(z);
	}
	cout << endl << endl;
	
	// Menyusun data yang telah di Masukan ke Binary tree secara preOrder (left to right)
	cout << "Gabungkan Semua data yang ada didalam Binary Tree secara Left to Right dan ubah kedalam preOrderTraversal !!" << endl;
	
	preOrderTrav(rootCell);
	
	return 0;
}