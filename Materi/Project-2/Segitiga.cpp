#include <iostream>
using namespace std;

struct segitiga{
	int alas , tinggi;
}segi;

int main(){
 	cout << "Masukkan Alas (cm): ";
 	cin >> segi.alas;
 	
 	cout << "Masukkan Tinggi (cm): ";
 	cin >> segi.tinggi;
	cout << "\n";
 	cout << "Luas Segitiga : " << (segi.alas * segi.tinggi)/2 <<"cm"<<endl;
 	cout << "Keliling Segitiga Sama Sisi : " << 3*segi.alas <<"cm"<<endl;
 	
 	return 0;
}