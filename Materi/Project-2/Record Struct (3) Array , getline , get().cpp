#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

struct mahasiswa{
		string nama,prodi;
		int sks , nim;
		float ipk;
}mhs[10];
	
int main(){
	int input;
	cout << "Ingin input berapa Mahasiswa? ";(cin >> input).get();
	
	for(int i=0;i<input;i++){
	cout << "Masukkan Nama Mahasiswa  : "; getline(cin,mhs[i].nama); // getline digunakan untuk String
	cout << "Masukkan NIM Mahasiswa   : "; (cin >> mhs[i].nim).get(); // gunakan get untuk tipe data lain, apabila ada getline
	cout << "Masukkan Prodi Mahasiswa : "; getline(cin,mhs[i].prodi);
	cout << "Masukkan SKS Mahasiswa   : "; (cin >> mhs[i].sks).get();
	cout << "Masukkan IPK Mahasiswa   : "; (cin >> mhs[i].ipk).get();
	cout << endl;
	}

    cout << "Nama\t" << "||" << "NIM\t" << "||" << "Prodi\t" << "||" << "SKS\t" << "||" << "IPK\t"<<endl;
	for(int i=0;i<input;i++){
	cout << mhs[i].nama << "\t " << mhs[i].nim << "\t" << mhs[i].prodi << "\t" << mhs[i].sks << "\t" << mhs[i].ipk << endl;
	}
	
	return 0;
}