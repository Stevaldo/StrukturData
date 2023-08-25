#include <iostream>
#include <conio.h>

using namespace std;

struct theCell
{
	string nama;
	int nim;
	theCell *next, *prev;
};
theCell *head = NULL, *ptr, *tail = NULL, *temp;
int n = 0;

void inputData(string nama, int nim)
{
	if (head != NULL)
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		ptr = new theCell();
		temp->next = ptr;
		ptr->prev = temp;
		ptr->next = NULL;
		ptr->nama = nama;
		ptr->nim = nim;
		tail = ptr;
		n++;
	}
	else
	{
		head = new theCell();
		head->nama = nama;
		head->nim = nim;
		head->prev = NULL;
		head->next = NULL;
		tail = head;
		n++;
	}
}

void sisipData(string nama, int nim, int nodeke)
{
	if (head != NULL)
	{
		if (n > 2)
		{
			if (nodeke == 0)
			{
				ptr = new theCell();
				ptr->nama = nama;
				ptr->nim = nim;

				ptr->next = head;
				head->prev = ptr;
				ptr->prev = NULL;
				head = ptr;
				n++;
			}
			else if (nodeke > 0 && nodeke < n)
			{
				ptr = new theCell();
				ptr->nama = nama;
				ptr->nim = nim;

				temp = head;
				for (int i = 0; i < nodeke - 1; i++)
				{
					temp = temp->next;
				}

				ptr->next = temp->next;
				ptr->prev = temp;
				temp->next = ptr;
				ptr = temp->next;
				temp = temp->next->next;
				temp->prev = ptr;
				n++;
			}
			else if (nodeke == n)
			{
				temp = head;
				while (temp->next != NULL)
				{
					temp = temp->next;
				}
				ptr = new theCell();
				temp->next = ptr;
				ptr->prev = temp;
				ptr->next = NULL;
				ptr->nama = nama;
				ptr->nim = nim;
				tail = ptr;
				n++;
			}
			else
			{
				inputData(nama, nim);
			}
		}
		else
		{
			inputData(nama, nim);
		}
	}
	else
	{
		inputData(nama, nim);
	}
}
// void hapusData() coming soon brader;
void print()
{
	if (head != NULL)
	{
		ptr = head;
		while (ptr != NULL)
		{
			cout << endl;
			cout << "Nama   : " << ptr->nama << endl
				 << "NIM    : " << ptr->nim << endl
				 << "Alamat : " << ptr << endl
				 << endl;
			ptr = ptr->next;
		}
	}
}

int main()
{
	string nama;
	int nim, nodeke;
lagi:
	if (n > 2)
	{
		cout << "Masukkan Nama : ";
		cin >> nama;
		cout << "Masukkan NIM  : ";
		cin >> nim;
		cout << "Sisipkan Setelah node ke-";
		cin >> nodeke;
		sisipData(nama, nim, nodeke);
		print();
	}
	else
	{
		cout << "Masukkan Nama : ";
		cin >> nama;
		cout << "Masukkan NIM  : ";
		cin >> nim;
		inputData(nama, nim);
		print();
	}

	char pilihan;
	cout << endl;
	cout << "Buat Data Lagi 		 (1)" << endl;
	cout << "Tampilkan Head dan Tail (2)" << endl;
	cout << "Exit Program   		 (3)" << endl;
	pilihan = getch();
	cout << endl
		 << endl;
	if (pilihan == '1')
	{
		goto lagi;
	}
	else if (pilihan == '2')
	{
		cout << "Head : " << head->nama << endl;
		cout << "Tail : " << tail->nama << endl;
	}
	else if (pilihan == '3')
	{
		exit(0);
	}
	else
	{
		cout << "Inputan Tidak Valid" << endl
			 << "Harap input 1/2/3 saja" << endl
			 << "Exiting Program...";
		exit(0);
	}
	return 0;
}