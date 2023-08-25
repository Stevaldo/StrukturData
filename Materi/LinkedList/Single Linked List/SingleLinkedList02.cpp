#include <iostream>
using namespace std;

struct theCell{
	int dat;
	struct theCell *berikut;
}*kepala;

int main(){
	struct theCell *ptrCell = NULL;
	
	for(int i=0;i<5;i++){
		if(kepala != NULL){
			ptrCell -> berikut = (struct theCell *) malloc(sizeof(struct theCell));
			ptrCell = ptrCell->berikut;
		}else{
			kepala = (struct theCell *) malloc(sizeof(struct theCell));
			ptrCell = kepala;
		}
		
		cout << "Masukkan Data : ";
		cin >> ptrCell->dat;
		
		ptrCell->berikut = NULL;
	}
	
	if(kepala != NULL){
		cout << "cell : {Alamat}\t\t{ Data\t| Cell berikut]" << endl;
		
		ptrCell = kepala;
		
		do{
			int i = 0;
			cout << "cell : {" << ptrCell <<"}\t"<< ptrCell->dat <<"\t|" <<ptrCell->berikut << ']' <<  endl;
			ptrCell = ptrCell->berikut;
			i++;
		}while(ptrCell != NULL);
	}
	cout << endl << endl;
}