#include <iostream>
using namespace std;

int main(){
	// Array
//	int test[10] = {};
//	for(int i=0;i<10;i++){
//		cout << "Bilangan " << i << " : ";
//		cin >> test[i];
//	}
//	
//	cout << endl;
//	for(int i=0;i<10;i++){
//		cout << "Array[" << i << "] = " << test[i] << endl;
//	}

	//Latihan 1
//		int test[5] , data , temp;
//	for(int i=0;i<5;i++){
//		cout << "Bilangan " << i << " : ";
//		cin >> test[i];
//	}
//	
//	cout << endl << "Masukkan data yang ingin diganti : "; cin >> temp;
//	cout << "Masukkan data baru : "; cin >> data;
//	
//	for(int i=0;i<5;i++){
//		if(temp == test[i]){
//			test[i] = data;
//		}
//	}
//
//	for(int i=0;i<5;i++){
//		cout << "Array[" << i << "] = " << test[i] << endl;
//	}
	
	
	// Array 2D
//	int test[3][3] = {{10,20,30}, {33,44,55} , {66,77,88}};
//	
//	for(int i=0;i<3;i++){
//		for(int n=0;n<3;n++){
//			cout << "Array[" << i << "][" << n << "] : " << test[i][n] << endl;
//		}	
//	}


	//Latihan 2
//	int test [3][3] = {};
//	int baris , kolom , temp;
//	for(int i=0;i<3;i++){
//		for(int n=0;n<3;n++){
//			cout << "Array[" << i << "][" << n << "] : ";cin>>test[i][n];
//		}	
//	}
//	
//	cout << endl << "Data pada Array baris ke-"; cin >> baris;
//	cout << "Data pada Array Kolom ke-"; cin >> kolom;
//	
//	for(int i=0;i<3;i++){
//		for(int n=0;n<3;n++){
//			if(test[baris][kolom] == test[i][n]){
//				cout << "Perubahan data pada ARRAY baris ke-1 dan ARRAY kolom ke-2 adalah :";
//				cin>>test[baris][kolom];	
//				break;
//			}
//		}
//	}
//	
//	for(int i=0;i<3;i++){
//		for(int n=0;n<3;n++){
//			cout << "Array[" << i << "][" << n << "] : " << test[i][n] << endl;
//		}	
//	}

	// Array 3D
	int test[3][2][4] = {
		{
			{10,20,30,40},
			{50,60,70,80}
		},
		{
			{11,22,33,44},
			{55,66,77,88}
		},
		{
			{12,13,14,15},
			{21,31,42,51}
		}
	};
	

	
	for(int x=0;x<3;x++){
	cout <<  "Tabel ke " << x+1 << endl;
		for(int y=0;y<2;y++){
			for(int z=0;z<4;z++){
				cout << test[x][y][z] << " ";
			}
				cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}