#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
    string data;
    node *next;
};

node *kepala = NULL;
node *ptr = NULL;
node *temp;
int jumlahData = 5;

void inputData()
{
    string input;
    int dataNext;
    cout << "Masukkan Data: ";
    cin >> input;

    cout << "Input setelah data ke-? ";
    cin >> dataNext;

    if (dataNext == 0)
    {
        ptr = new node;
        ptr->next = kepala;
        ptr->data = input;
        kepala = ptr;
        jumlahData++;
    }
    else if (dataNext > 0 && dataNext <= jumlahData)
    {
        temp = kepala;
        for (int i = 0; i < dataNext - 1; i++)
        {
            temp = temp->next;
        }
        ptr = new node;
        ptr->next = temp->next;
        temp->next = ptr;
        ptr->data = input;
        jumlahData++;
    }
}

void hapusData()
{
    int dataHapus;
    cout << "Hapus Setelah data ke-";
    cin >> dataHapus;
    if (dataHapus == 0)
    {
        ptr = kepala;
        kepala = ptr->next;
        jumlahData--;
    }
    else if (dataHapus > 0 && dataHapus <= jumlahData)
    {
        ptr = kepala;
        for (int i = 0; i < dataHapus - 1; i++)
        {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        jumlahData--;
    }
}

void cetakData()
{
    cout << endl;
    if (kepala != NULL)
    {
        ptr = kepala;
        for (int y = 0; y < jumlahData; y++)
        {
            cout << "Data " << y + 1 << " = " << ptr->data << "\t" << ptr << endl;
            ptr = ptr->next;
        }
    }
}

void tampilkanMenu()
{
    system("cls");
    char input;
    cout << endl
         << "Hapus Data (1) / Input Data (2)" << endl;
    cout << "Input : ";
    cin >> input;

    if (input == '1')
    {
        cetakData();
        hapusData();
        cetakData();
        cout << "Lanjut??";
        getch();
        tampilkanMenu();
    }
    else if (input == '2')
    {
        cetakData();
        inputData();
        cetakData();
        cout << "Lanjut??";
        getch();
        tampilkanMenu();
    }
}
int main()
{
    string nama[5] = {"Nobita",
                      "Shizuka",
                      "Suneo",
                      "Giant",
                      "Doraemon"};
    for (int i = 0; i < jumlahData; i++)
    {
        if (kepala != NULL)
        {
            ptr->next = new node;
            ptr = ptr->next;
        }
        else
        {
            kepala = new node;
            ptr = kepala;
        }
        ptr->data = nama[i];
    }
    cetakData();
    cout << "Lanjut??";
    getch();
    tampilkanMenu();
    return 0;
}