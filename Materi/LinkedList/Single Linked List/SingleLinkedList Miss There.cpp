#include<iostream>
using namespace std;

struct baju{
	string jenis, ukuran;
	baju *next;
};

baju *head, *tail, *ptr, *node1, *node2, *node3;


void addhead(string jenis, string ukuran){
	head = new baju; //head=(baju*malloc(sizeof(struct(baju);
	head->jenis = jenis;
	head->ukuran = ukuran;
	head->next = NULL;
	tail = head;
	
}



void printNode(){
	ptr = head;
	
	while(ptr != NULL){	
	cout<<"Jenis baju : "<<ptr->jenis <<endl;
	cout<<"Ukuran : "<<ptr->ukuran <<endl;
	ptr=ptr->next;		
	}

}


void addlast(string jenis, string ukuran){
	node1 = new baju;
	ptr = head;
	while(ptr->next != NULL){
		ptr=ptr->next;
	}
	ptr ->next = node1;
	node1->jenis = jenis;
	node1->ukuran = ukuran;
	tail = node1;
	node1->next = NULL;
}

void addfirst(string jenis, string ukuran){
	node2 = new baju;
	node2->jenis=jenis;
	node2->ukuran=ukuran;
	node2->next = head;
	head = node2;
}
void addMiddle(string jenis,string ukuran,int nodeke){
	node3 =  new baju;
	node3->ukuran = ukuran;
	node3->jenis = jenis;
	ptr = head;
	
	for(int i=0;i<nodeke-1;i++){
		ptr=ptr->next;
	}
	node3->next = ptr->next;
	ptr->next = node3;
	node3 = ptr->next;

}
int main(){
	
	addhead("kemeja","s");
	
	addlast("polo","m");

	addfirst("daster","All size");

	addMiddle("Jaket","XL",2);
	printNode();
	cout<<endl;
	return 0;
}