#include <iostream>
using namespace std;

struct theCell{
    int data;
    struct theCell *next,*prev;
};

theCell *head = NULL , *tail = NULL , *ptr , *temp;
int n; // Jumlah Data

void sisipNode(int inputData ,int nodeke){
    if(head != NULL){
            if(nodeke == 0){
                temp = head;
                ptr = new theCell();
                ptr->next = temp;
                ptr->data = inputData;
                temp->prev = ptr;
                head = ptr;
                head->prev = tail;
                tail->next = head;
                n++;
            }else if(nodeke > 0 && nodeke < n){
                temp = head;
                for(int i=0;i<nodeke-1;i++){
                    temp = temp->next;
                }
                ptr = new theCell();
                ptr->next = temp->next;
                temp->next = ptr;
                ptr->prev = temp;
                temp = ptr->next;
                temp->prev = ptr;
                ptr->data = inputData;
                n++;
            }else if(nodeke == n){
                ptr = tail;
                ptr->next = new theCell();
                ptr = ptr->next;
                ptr->data = inputData;
                ptr->prev = tail;
                tail = ptr;
                head->prev = tail;
                tail->next = head;
                n++;
            }else{
                cout << "Data hanya ada " << n << endl;
            }
        
    }else{
        cout << "Buatlah Head terlebih Dahulu" << endl;
    }
}

void hapusNode(int nodeke){
    if(head != NULL){
        if(nodeke == 1){
            temp = head;
            ptr = temp->next;
            head = ptr;
            head->prev = tail;
            free(temp);
            n--;
        }else if(nodeke > 1 && nodeke < n){
            temp = head;
            for(int i=0;i<nodeke-2;i++){
                temp = temp->next;
            }
            ptr = temp->next;
            temp->next = ptr->next;
            ptr->next->prev = temp;
            free(ptr);
            n--;
        }else if(nodeke == n){
            temp = head;
            for(int i=0;i<nodeke-2;i++){
                temp = temp->next;
            }
            ptr = temp->next;
            tail = temp;
            temp->next = head;
            free(ptr);
            n--;
        }else{
            cout << "Node ke-" << nodeke << " tidak ditemukan!!" << endl;
        }
    }else{
        cout << "Tidak ada node yang tersisa :(" << endl;
    }
}
void printNode(){
    if(head != NULL){
        ptr = head;
        for(int i=0;i<n;i++){
            cout <<"Prev : " << ptr->prev << "\tAlamat : " << ptr << "\t\tData : " << ptr->data << "\tNext : "  << ptr->next << endl;
            ptr = ptr->next;
        }
    }
}

void searchData(){
    if(head != NULL){
        int search;
        bool result = false;
        cout << "Masukkan Data yang ingin dicari : "; cin >> search;
        ptr = head;
        for(int i=0;i<n;i++){
           if(search == ptr){
             result = true;
             goto cetak;
           }
           ptr = ptr->next;
        }

        cetak:

        if(result == true){
            cout <<"Prev : " << ptr->prev << "\tAlamat : " << ptr << "\t\tData : " << ptr->data << "\tNext : "  << ptr->next << endl;
        }else{
            cout << "Data tidak ditemukan" << endl;
        }
    }else{
        cout << "Buat Head terlebih dahulu" << endl;
    }
}

int main(){
// Nomor 1
    for(int i=10;i<13;i++){
    if(head == NULL){
        head = new theCell();
        ptr = head;
    }else{
        ptr->next = new theCell();
        temp = ptr->next;
        temp->prev = ptr;
        ptr = temp;
    }
    ptr->data = i;
    tail = ptr;

    tail->next = head;
    head->prev = tail;
    n++;
    }

    // Nomor 2 a,b,c
    sisipNode(1,0);
    sisipNode(2,1);
    sisipNode(3,2);
    printNode();
    searchData();
    return 0;
}