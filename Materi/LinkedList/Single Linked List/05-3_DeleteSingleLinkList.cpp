#include <iostream>
using namespace std;

//Record Definition
struct TheCell
{
  int dat;
  struct TheCell *berikut;
};

struct TheCell *isiCell(int dat, struct TheCell *cellBaru, struct TheCell *kepala){
  if (kepala == NULL){
    //Mengisi Linked List dari keadaan kosong
    cellBaru = (struct TheCell *) malloc(sizeof(struct TheCell));
    cellBaru->dat=dat;
    
	//Tentukan Link selanjutnya pada simpul/node baru di tentukan sebagai NULL
    cellBaru->berikut = NULL;
    return(cellBaru);
  }
  else{
    //Mengisi pada Linked List yang sudah terbentuk
    cellBaru->berikut=(struct TheCell *) malloc(sizeof(struct TheCell));
    cellBaru = cellBaru->berikut;
    
	//Isi Data
    cellBaru->dat=dat;
    
	//Tentukan Link selanjutnya pada simpul/node baru di tentukan sebagai NULL
    cellBaru->berikut = NULL;
    return(cellBaru);
  }
}

void hapusCell(struct TheCell *cellTujuan, struct TheCell *kepala){
  struct TheCell *cellCheck;
  cellCheck = kepala;
  if(cellTujuan->berikut != NULL){
    //hapus di tengah
    //loop sampai cellCheck mencapai cellTujuan
    while(cellCheck->berikut!=cellTujuan){
        cellCheck = cellCheck->berikut;
    };
      
    cellCheck->berikut = cellTujuan->berikut;
    free(cellTujuan);
  }
  else{
    //Hapus di ekor
    //loop sampai ke node sebelum ekor
    while(cellCheck->berikut->berikut!=NULL){
        cellCheck = cellCheck->berikut;
    };
    free(cellCheck->berikut);
    cellCheck->berikut = NULL;
  }  
}

void cetak(struct TheCell *cellTujuan, struct TheCell *kepala){
  //Menampilkan Isi Linked List dari awal
  if (kepala!=NULL)  //Memastikan Linked List tidak kosong, yg ditandai dengan kepala != NULL
  {
    cout<<"cell: {Alamat} [ Data | Cell berikut]"<<endl;
    //Arahkan ptrCell ke alamat yang ditunjuk oleh kepala
    cellTujuan = kepala;
    do
    {
      //Tampilkan isi Node / Simpul
      cout<<"cell: {"<<cellTujuan<<"} ["<<cellTujuan->dat<<" | "<<cellTujuan->berikut<<"]"<<endl;
      //Arahkan ptrCell ke Node/Simpul berikutnya
      cellTujuan = cellTujuan->berikut;
    }while (cellTujuan != NULL); //keluar dari loop ketika ptrCell menunjukkan alamat NULL
    cout<<endl<<endl;
  }	
}

//program utama
int main(){
  int i; 
  int nodeke;
  struct TheCell *kepala=NULL;
  struct TheCell *ptrCell=NULL;
  
  for (i=1;i<=10;i++){
    if (kepala == NULL){
      //Mengisi Linked List dari keadaan kosong
      kepala = isiCell(i*10, NULL, NULL);;
      ptrCell = kepala;
    }
    else
    {
      //Mengisi pada Linked List yang sudah terbentuk
      ptrCell = isiCell(i*10, ptrCell, kepala);
    }
  }
   
  cetak(ptrCell, kepala);
  
  cout<<"Hapus node ke: ";
  cin>>nodeke;
  cout<<endl;
  
  ptrCell = kepala;
  if (nodeke>1){
    for(i=1;i<nodeke;i++){
      ptrCell = ptrCell->berikut;
    }
    hapusCell(ptrCell, kepala);
  }
  else{
  	//Hapus di kepala
    //free(kepala);
	kepala=kepala->berikut;
  	free(ptrCell);
  }
  cetak(ptrCell, kepala);
  
  return 0;
}