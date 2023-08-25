#include <iostream>
using namespace std;

struct theCell{
	int dat;
	struct theCell *berikut;
};

struct theCell *isiCell(int dat, struct theCell *cellBaru,struct theCell *kepala);

int main(){
	int i , temp;
	
	struct theCell *kepala = NULL;
	struct theCell *ptrCell = NULL;
	
	cout << "Masukkan Jumlah data yang ingin di-input : ";
	cin >> i;
	
	for(int x=0;x<i;x++){
				cout << "Input data " << x+1 << " : ";
 				cin >> temp;
				if(kepala != NULL){
					ptrCell = isiCell(temp,ptrCell,kepala);
				}else{
					kepala = isiCell(temp,NULL,NULL);
					ptrCell = kepala;
				}
				cout << "Data disimpan di Alamat : " << ptrCell << endl << endl;
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

struct theCell *isiCell(int dat, struct theCell *cellBaru,struct theCell *kepala){
	if(kepala == NULL){
		cellBaru = (struct theCell*)malloc(sizeof(struct theCell));
		cellBaru->dat = dat;
		
		cellBaru->berikut = NULL;
		return (cellBaru);
	}else{
		cellBaru->berikut = (struct theCell*)malloc(sizeof(struct theCell));
		cellBaru = cellBaru->berikut;
		
		cellBaru->dat=dat;
		
		cellBaru->berikut = NULL;
		return(cellBaru);
	}
}