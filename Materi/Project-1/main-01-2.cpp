#include <iostream>
using namespace std;

int main(){
	// Test 1
	int no[] = {10,11,12};
	int *ptr = no;
	
	cout << ptr << endl;
	cout << ptr+1 << endl;
	cout << *ptr << endl;
	cout << *(ptr + 1) << endl;
	cout << *ptr + 1 <<endl;
	
	
	// Test 2
	int V=10;
	int *pV = &V;
	int no[100];
	
	cout << sizeof(V) << endl;
	cout << sizeof(pV) << endl;
	cout <<sizeof(no) << endl;
	cout << sizeof(no[1]) << endl;	
	cout << "Ukuran Array = " << sizeof(no)/sizeof(no[0]) << endl;
	
	
	return 0;
}