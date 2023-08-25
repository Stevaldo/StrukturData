#include <iostream>
#define size 20
using namespace std;

struct theCell{
	int dat;
	struct theCell *kiri , *kanan , *parent;
};

struct theCell *ptrCell, *rootCell = NULL , *baru;

void input(int data){
	baru =  new theCell;
	baru->dat = data;
	baru->kanan = NULL;
	baru->kiri = NULL;
	
	if(rootCell == NULL){
		rootCell = baru;
		rootCell->parent = NULL;
	}else{
		ptrCell = rootCell;
		
		while(ptrCell != baru){
			
			// Implementasi Left to Right Order
			if(ptrCell->dat > baru->dat){ // Jika Data baru lebih kecil dari Root maka Masukkan ke Kiri
				// Jika Kiri Kosong maka masukkan data kekiri
				baru->parent = ptrCell;
				if(ptrCell->kiri == NULL){
					ptrCell->kiri = baru;
				}
				ptrCell = ptrCell->kiri;
			}else{ // Jika Data baru lebih besar / sama dengan root maka masukkan ke Kanan
				// Jika kanan Kosong maka masukkan data kekanan
				baru->parent = ptrCell;
				if(ptrCell->kanan == NULL){
					ptrCell->kanan = baru;
				}
				ptrCell = ptrCell->kanan;
			}
		}
	}	
}

// Stack
int pool[size] , poolSize = 0;

void push(int data){
	if(poolSize > size){
		cout << "Stack Full" << endl;
	}else{
		pool[poolSize] = data;
		poolSize++;
	}
}


int pop(){
	if(poolSize != 0){
		int value = pool[poolSize-1];
		poolSize--;
		return value;
	}else{
		cout << "Stack is Empty!!" << endl;
	}
}

void postOrderTrav(struct theCell *travCell){
	// L:
	if(travCell->kiri != NULL)
	postOrderTrav(travCell->kiri);
	// R:
	if(travCell->kanan != NULL)
	postOrderTrav(travCell->kanan);
	// V: Push kedalam Stack
	push(travCell->dat);
}

int main(){	
	// Susun Secara left to Right
	int a[size] = {12,35,41,23,22,10,99,21,50,40,39,48,24,11,66,51,55,44,33,22};
	
	for(int i=0;i<size;i++)
	input(a[i]);
	
	// PostOrder Binary tree Traversal sekaligus Push kedalam Stack
	postOrderTrav(rootCell);
	
	// Pop Stack sekaligus cetak ke Layar
	cout << "Stack 20 = Data paling akhir sedangkan Stack 1 = Data paling awal" << endl;
	cout << "First in Last Out" << endl << endl;
	for(int i=size;i>0;i--){
		cout << "Stack ke-" << i << " : " << pop() << " Berhasil di POP" << endl;	
	}
	
	
	return 0;
	system("pause");
}