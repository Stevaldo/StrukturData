#include <iostream>
using namespace std;

struct theCell{
	int dat;
	struct theCell *kiri , *kanan;
};

struct theCell *ptrCell, *rootCell = NULL , *baru;

void input(int data){
	baru =  new theCell;
	baru->dat = data;
	baru->kanan = NULL;
	baru->kiri = NULL;
	
	if(rootCell == NULL){
		rootCell = baru;
		cout << baru->dat << " ditempatkan sebagai ROOT!!" << endl;
	}else{
		ptrCell = rootCell;

		while(ptrCell != baru){
			
			if(ptrCell->dat > baru->dat){ // Kekiri
				// Jika Kiri Kosong maka masukkan data kekiri
				if(ptrCell->kiri == NULL){
					ptrCell->kiri = baru;
					cout << baru->dat << " ditempatkan sebagai LEFT!!" << endl;
				}
				ptrCell = ptrCell->kiri;
			}else{ // Kekanan
				// Jika kanan Kosong maka masukkan data kekanan
				if(ptrCell->kanan == NULL){
					ptrCell->kanan = baru;
					cout << baru->dat << " ditempatkan sebagai RIGHT!!" << endl;
				}
				ptrCell = ptrCell->kanan;
			}
		}
	}	
}

int main(){	
	for(int i=0;i<3;i++)
	input(rand());

	return 0;
}