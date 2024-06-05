#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node *address;
typedef struct Mahasiswa{
    int NIM;
    char nama[50];
    float IPK;
} Mahasiswa;

typedef struct Node{
    Mahasiswa data;
    address next;
} Node;

address first = NULL;

// Fungsi untuk mengalokasikan memori untuk node baru
address alokasikan(int NIM, char *nama, float IPK){
    address newNode = (address)malloc(sizeof(Node));
    strcpy(newNode->data.nama, nama);
    newNode->data.NIM = NIM;
    newNode->data.IPK = IPK;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambah mahasiswa di awal linked list
void insertFirst(address p){
    p->next = first;
    first = p;
}

// Fungsi untuk menambah mahasiswa di akhir linked list
void insertLast(address p){
    if (first == NULL){
        first = p;
    } else{
        address temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}

// Fungsi untuk menghapus mahasiswa di awal linked list
void deleteFirst(){
    if (first != NULL){
        address temp = first;
        first = first->next;
        free(temp);
    }
}

// Fungsi untuk menghapus mahasiswa di akhir linked list
void deleteLast(){
    if (first == NULL){
        printf("Kosong, gabisa dihapus\n");
        return;
    }
    if (first->next == NULL){
        free(first);
        first = NULL;
        return;
    }
}

// Fungsi untuk menampilkan semua data mahasiswa
void cetak(){
    address temp = first;
    while (temp != NULL){
        printf("NIM: %d, Nama: %s, IPK: %.2f\n", temp->data.NIM, temp->data.nama, temp->data.IPK);
        temp = temp->next;
    }
}

// Lengkapi fungsi untuk memasukkan mahasiswa secara ascending berdasarkan NIM
void insertAscending(address p){
        address temp = first;
        while (temp->next->data.NIM < p->data.NIM){
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
    }

// Lengkapi fungsi untuk swap data 2 node
void swapData(address node1, address node2){
    Mahasiswa temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// Lengkapi fungsi untuk sortir linked list yang ada
void sortList(){
    address node1, node2;
    Mahasiswa temp;
    for (node1 = first; node1->next != NULL; node1 = node1->next){
        for (node2 = node1->next; node2 != NULL; node2 = node2->next){
            if (node1->data.NIM > node2->data.NIM){
                temp = node1->data;
                node1->data = node2->data;
                node2->data = temp;
            }
        }
    }
}

// Lengkapi fungsi untuk mencetak mahasiswa secara ascending berdasarkan NIM
void cetakBersamaNIM()
{
    sortList();
    cetak();
}

int main()
{
    address current;
    current = alokasikan(125, "Budi", 3.5);
    insertFirst(current);
    current = alokasikan(128, "Siti", 3.7);
    insertLast(current);
    current = alokasikan(126, "Andi", 3.8);
    insertLast(current);
    current = alokasikan(130, "Desi", 3.2);
    insertFirst(current);
    current = alokasikan(127, "Dedi", 3.9);
    insertLast(current);
    current = alokasikan(129, "Saki", 3.4);
    insertFirst(current);
    deleteLast();
    printf("Setelah dihapus satu dari belakang:\n");
    cetak();
    printf("\nSetelah data diurutkan berdasarkan NIM\n");
    cetakBersamaNIM();
    return 0;
}