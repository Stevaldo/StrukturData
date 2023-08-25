#include <iostream>
using namespace std;

int main(){
//	Menampilkan Alamat menggunakan Array String
	string nama[20] , *p;
	int x;
	
	p = nama;
	
	cout << "Masukkan Berapa Kolom yang ingin di-Input : ";
	cin >> x;
	
	for(int i=0;i<x;i++){
		cout << "Masukkan Value Array ke -" << i+1 << " = ";
		cin >> nama[i];
	}
	
	for(int i=0;i<x;i++){
		cout << "nama[" << i+1 << "] = " << p[i] << " dengan alamat = " << &p[i] << endl; 
	}

//  Penggantian Nilai Pointer
	int x,*ptr;
	
	x=25;
	ptr =&x;
	cout << "Nilai x = " << x << endl;
	cout << "Alamat x = " << ptr << endl;
	
	*ptr = 100;
	cout << "Nilai x = " << x << endl;
	cout << "Nilai Pointer = " << *ptr << endl;
	
	
//	Menampilkan Alamat menggunakan Array Char
	char nama[20] , *p;
	int x;
	
	p = nama;
	
	cout << "Masukkan Berapa Kolom yang ingin di-Input : ";
	cin >> x;
	
	for(int i=0;i<x;i++){
		cout << "Masukkan Character ke -" << i+1 << " = ";
		cin >> nama[i];
	}
	
	for(int i=0;i<x;i++){
   		cout << "nama[" << i+1 << "] = " << p[i]<< " dengan alamat = " << (int* )&p[i] << endl; // Memaksa Alamat menjadi Int
	}	
	
	
	return 0;
}