#include <iostream>
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
		cout <<"Data : " << baru->dat << " | Alamat : " << baru << " | Root" << endl;
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
					cout << "Alamat Parent : " << baru->parent << " | Data : " << baru->dat << " | Alamat : " << baru << " | Left" << endl;
				}
				ptrCell = ptrCell->kiri;
			}else{ // Jika Data baru lebih besar / sama dengan root maka masukkan ke Kanan
				// Jika kanan Kosong maka masukkan data kekanan
				baru->parent = ptrCell;
				if(ptrCell->kanan == NULL){
					ptrCell->kanan = baru;
					cout << "Alamat Parent : " << baru->parent << " | Data : " << baru->dat << " | Alamat : " << baru << " | Right" << endl;
				}
				ptrCell = ptrCell->kanan;
			}
		}
	}	
}

int main(){	
	int size = 20;
	int a[size] = {12,35,41,23,22,10,99,21,50,40,39,48,24,11,66,51,55,44,33,22};
	
	for(int i=0;i<size;i++)
	input(a[i]);
	
	return 0;
	system("pause");
}