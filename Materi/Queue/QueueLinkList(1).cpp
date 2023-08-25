#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

//Record Definition
struct theCell {
    int dat;
    struct theCell* next;
    struct theCell* prev;
};

//Head sebagai fist, tail sebagai last
struct theCell* head = NULL;
struct theCell* tail = NULL;

struct theCell dequeue() {
    struct theCell temp;
    temp.dat = head->dat;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
    return temp;
}

bool isEmpty() {
    if (head == NULL)
        return true;
    else
        return false;
}

void clear() {
    while (head != NULL) {
        dequeue();
    }
}

void enqueue(int data) {
    struct theCell* newCell = (struct theCell*)malloc(sizeof(struct theCell));
    newCell->dat = data;
    newCell->next = NULL;
    newCell->prev = NULL;

    if (head == NULL) {
        head = newCell;
        tail = newCell;
    } else {
        newCell->prev = tail;
        tail->next = newCell;
        tail = newCell;
    }
}

void tampilkan() {
    // Menampilkan Isi Linked List dari awal
    if (head != NULL) {
        cout << "Kepala : " << head << endl;
        cout << "Ekor : " << tail << endl;
        cout << "[sebelum | {cell: Alamat} Data | berikut]" << endl;
        // Arahkan tail ke alamat yang ditunjuk oleh kepala
        tail = head;
        do {
            // Tampilkan isi Node/Simpul
            cout << "[" << setiosflags(ios::right) << setw(10) << tail->prev << " | {cell: " << tail << "} "
                 << setiosflags(ios::right) << setw(10) << tail->next << "]" << endl;
            // Arahkan tail ke node/simpul berikutnya
            tail = tail->next;
        } while (tail != NULL);  // keluar dari loop ketika ptrCell menunjukkan alamat ekor
        cout << endl << endl;
    } else {
        cout << "Queue Empty" << endl;
    }
}

// Program Utama
int main() {
    int i, bilRandom;
    for (i = 1; i <= 10; i++)
        enqueue(rand());
    tampilkan();

    while (!isEmpty()) {
        cout << "FirstEl\t\t : " << head->dat << endl;
        struct theCell temp2 = dequeue();
        cout << "Ambil Data\t : " << temp2.dat << endl;
    }
    tampilkan();

    return 0;
}
