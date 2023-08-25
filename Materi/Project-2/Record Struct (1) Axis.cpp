#include <iostream>
using namespace std;

struct axis{
	float x , x2 ,y ,y2;
}axis;

int main(){
	float mid_x , mid_y;
	cout << "Masukkan Nilai X1 : ";
	cin >> axis.x;
	cout << endl << "Masukkan Nilai X2 : ";
	cin >> axis.x2;
	cout << endl << "Masukkan Nilai Y : ";
	cin >> axis.y;
	cout << endl << "Masukkan Nilai Y2 : ";
	cin >> axis.y2;
	cout << "\n";
	
	mid_x = (axis.x+axis.x2)/2;
	mid_y = (axis.y+axis.y2)/2;
	cout << "Nilai Midpoint(x,y) adalah (" << mid_x << ',' << mid_y << ')' << endl;
}