#include <iostream>
using namespace std;

struct theCell{
	int dat;
	struct theCell *kanan,*kiri;
};

struct theCell *rootCell = NULL , *ptrCell , *baru;

void preOrderTrav(struct theCell *travCell){
	// V:
	cout << travCell->dat << " | ";
	// R:
	if(travCell->kanan != NULL)
	preOrderTrav(travCell->kanan);
	// L:
	if(travCell->kiri != NULL)
	preOrderTrav(travCell->kiri);
}

void postOrderTrav(struct theCell *travCell){
	// R:
	if(travCell->kanan != NULL)
	postOrderTrav(travCell->kanan);
	// L:
	if(travCell->kiri != NULL)
	postOrderTrav(travCell->kiri);
	// V:
	cout << travCell->dat << " | ";
}

void inOrderTrav(struct theCell *travCell){
	// R:
	if(travCell->kanan != NULL)
	inOrderTrav(travCell->kanan);
	
	// V:
	cout << travCell->dat << " | ";
	// L:
	if(travCell->kiri != NULL)
	inOrderTrav(travCell->kiri);
}
	
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
			// Left to Right = > , Right to Left = <
			if(baru->dat > ptrCell->dat){ // Kekanan
				// Jika kanan Kosong maka masukkan data kekanan
				if(ptrCell->kanan == NULL){
					ptrCell->kanan = baru;
					cout << baru->dat << " ditempatkan sebagai RIGHT!!" << endl;
				}
				ptrCell = ptrCell->kanan;
			}else{ 
				// Kekiri
				// Jika Kiri Kosong maka masukkan data kekiri
				if(ptrCell->kiri == NULL){
					ptrCell->kiri = baru;
					cout << baru->dat << " ditempatkan sebagai LEFT!!" << endl;
				}
				ptrCell = ptrCell->kiri;
			}
		}
		
	}	
}

int main(){
	input(50);
	input(25);	
		input(75);
			input(10);
				input(35);
					input(60);
						input(85);
							input(5);
								input(15);
									input(30);
	cout <<  endl << "Pre-Order Traversal (Right to Left): ";
	preOrderTrav(rootCell);

	cout << endl <<  "Post-Order Traversal (Right to Left) ";
	postOrderTrav(rootCell);
	
	cout <<  endl << "In-Order Traversal (Right to Left) ";
	inOrderTrav(rootCell);	
}
