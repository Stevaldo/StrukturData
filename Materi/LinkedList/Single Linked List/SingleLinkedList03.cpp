#include <iostream>
using namespace std;

struct theCell{
	char dat[10];
	struct theCell *berikut;
};

int main(){
	int i;
	char masukan[10];
	struct theCell *kepala = NULL;
	struct theCell *ptrCell = NULL;
	
	cout << "Masukkan Jumlah data yang ingin di-input : ";
	cin >> i;
	
	for(int x=0;x<i;x++){
			cout << "Input data: ";
			cin >> masukan;
			if(strlen(masukan)<=10){
				if(kepala != NULL){
					ptrCell -> berikut = (struct theCell *) malloc(sizeof(struct theCell));
					ptrCell = ptrCell->berikut;
				}else{
					kepala = (struct theCell *) malloc(sizeof(struct theCell));
					ptrCell = kepala;
				}
				strcpy(ptrCell->dat,masukan);
				ptrCell->berikut = NULL;
				cout << "Data disimpan di Alamat : " << ptrCell << endl << endl;
			}else{
				cout << "Tidak boleh lebih dari 10 Karakter" << endl << endl;
			}	
	}
	cout << endl;

	
	if(kepala != NULL){
		cout << "cell : {Alamat}\t\t{ Data\t| Cell berikut]" << endl;
		
		ptrCell = kepala;
		
		do{
			int i = 0;
			cout << "cell : {" << ptrCell <<"}\t"<< ptrCell->dat <<"\t|" <<ptrCell->berikut << ']' <<  endl;
			ptrCell = ptrCell->berikut;
			i++;
		}while(ptrCell != NULL);
	}else{
		cout << "Data tidak ada";
	}
	cout << endl << endl;
	return 0;
	
}