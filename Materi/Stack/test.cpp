#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << setw(10) << left << "Nama"
         << setw(10) << left << "Usia"
         << setw(10) << left << "Kota" << endl;

    cout << setw(10) << left << "John"
         << setw(10) << left << 25
         << setw(10) << left << "Jakarta" << endl;

    cout << setw(10) << left << "Jane"
         << setw(10) << left << 30
         << setw(10) << left << "Surabaya" << endl;

    return 0;
}