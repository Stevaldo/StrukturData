#include <iostream>
using namespace std;

struct theCell{
    int data;
    struct theCell *next;
};

theCell *head = NULL , *tail = NULL , *ptr , *temp;
int n; // Jumlah Data

void sisipNode(int inputData ,int nodeke){
    if(head != NULL){
            if(nodeke == 0){
                ptr = head;
                temp = new theCell();
                temp->next = ptr;
                temp->data = inputData;
                head = temp;
                n++;
            }else if(nodeke > 0 && nodeke < n){
                temp = head;
                for(int i=0;i<nodeke-1;i++){
                    temp = temp->next;
                }
                ptr = new theCell();
                ptr->next = temp->next;
                temp->next = ptr;
                ptr->data = inputData;
                n++;
            }else if(nodeke == n){
                ptr = tail;
                ptr->next = new theCell();
                ptr = ptr->next;
                ptr->data = inputData;
                tail = ptr;
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
            free(temp);
            n--;
        }else if(nodeke >1 && nodeke < n){
            temp = head;
            for(int i=0;i<nodeke-2;i++){
                temp = temp->next;
            }
            ptr = temp->next;
            temp->next = ptr->next;
            free(ptr);
            n--;
        }else if(nodeke == n){
            temp = head;
            for(int i=0;i<nodeke-2;i++){
                temp = temp->next;
            }
            ptr = temp->next;
            tail = temp;
            tail->next = NULL;
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
            cout << "Alamat : " << ptr << "\t\tData : " << ptr->data << "\tNext : "  << ptr->next << endl;
            ptr = ptr->next;
        }
    }
}

void searchData(){
    if(head != NULL){
        int search;
        bool result = false;
        cout << "Masukkan Data yang ingin dicari : ";
        cin >> search;
        ptr = head;
        for(int i=0;i<n;i++){
           if(search == ptr->data){
               result = true;
               goto print;
           } 
           ptr = ptr->next;
        }

        print:
        if(result == true){
           cout << "Alamat : " << ptr << "\t\tData : " << ptr->data << "\tNext : "  << ptr->next << endl;
        }else{
            cout << "Data tidak ditemukan" <<
        }
    
    }else{
        cout << "Tidak ada data" << endl;
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
        ptr = ptr->next;
    }
    ptr->data = i;
    tail = ptr;
    n++;
    }

  // Nomor 2 a,b,c

    sisipNode(123,0); // Sisip Data diAwal   = 0 
    sisipNode(321,1); // Sisip Data diTengah = 1/2
    sisipNode(132,n); // Sisip Data diAkhir  = n 

    
  // Nomor 2 d,e,f
    hapusNode(1); // Hapus Data diAwal   = 1 
    hapusNode(3); // Hapus Data diTengah = 1-5
    hapusNode(n); // Hapus Data diAkhir  = n 
    printNode();
    
    searchData();
    return 0;
}