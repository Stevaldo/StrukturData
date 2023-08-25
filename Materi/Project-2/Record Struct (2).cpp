#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main(){
	float selisih;
	
	struct dataFruit{
		string name;
		float calories;
	};
	dataFruit fruit;

	struct dataVegetable{
		string name;
		float calories;
	};
	dataVegetable vegetable;
	
	cout << "Masukkan Nama Buah : ";
	cin >> fruit.name;
	cout << "Masukkan Jumlah Kalori Buah : ";
	cin >> fruit.calories;
	
	cout << "Masukkan Nama Sayur : ";
	cin >> vegetable.name;
	cout << "Masukkan Jumlah Kalori Sayur : ";
	cin >> vegetable.calories;
	
	selisih = abs(fruit.calories+vegetable.calories);
	
	cout << "Selisih Kalori dari " << fruit.name << " dengan " << vegetable.name << " adalah " << selisih  << endl;
	return 0;
}