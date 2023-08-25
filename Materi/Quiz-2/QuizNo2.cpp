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
		rootCell->parent = NULL;
	}else{
		ptrCell = rootCell;
		
		while(ptrCell != baru){
			
			// Ubah < untuk Right Order , > untuk Left Order
			if(ptrCell->dat < baru->dat){ 
				baru->parent = ptrCell;
				if(ptrCell->kiri == NULL){
					ptrCell->kiri = baru;
				}
				ptrCell = ptrCell->kiri;
			}else{ 
				baru->parent = ptrCell;
				if(ptrCell->kanan == NULL){
					ptrCell->kanan = baru;
				}
				ptrCell = ptrCell->kanan;
			}
		}
	}	
}

void postOrderTrav(struct theCell *travCell){
	// L:
	if(travCell->kiri != NULL)
	postOrderTrav(travCell->kiri);
	// R:
	if(travCell->kanan != NULL)
	postOrderTrav(travCell->kanan);
	// V:
	cout << travCell->dat << " | ";
}

int main(){	
	// Inisialisasi Data
	int size = 20;
	int a[size] = {12,35,41,23,22,10,99,21,50,40,39,48,24,11,66,51,55,44,33,22};
	
	// Memasukan Data kedalam Binary Tree
	for(int i=0;i<size;i++)
	input(a[i]);
	
	// Susun dan Cetak data dalam bentuk Post Order Traversal
	cout << "Post Order Traversal (Left to Right) : " << endl;
	postOrderTrav(rootCell);
	
	return 0;
	system("pause");
}