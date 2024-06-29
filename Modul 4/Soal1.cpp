#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();
void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

int main() {
    menu:
    cout << "Double Linked List Non Circular (DLLNC)" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Silahkan pilih program DLLNC yang ingin dijalankan!" << endl;
    cout << "1. DLLNC dengan Head" << endl;
    cout << "2. DLLNC dengan Head dan Tail" << endl;
    cout << "3. Quit" << endl;
    cout << "Pilihan : ";
    cin >> menu;
    system("cls");

    if (menu == 1) {
        initH();
        do {
            cout << "Double Linked List Non Circular (DLLNC) (Head)" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Reset" << endl;
            cout << "7. Kembali ke Menu" << endl;
            cout << "Pilihan :";
            cin >> pilihan;
            pil = atoi(pilihan);

            switch (pil) {
            case 1:
                tambahDepanH();
                break;
            case 2:
                tambahBelakangH();
                break;
            case 3:
                tampilkanH();
                break;
            case 4:
                hapusDepanH();
                break;
            case 5:
                hapusBelakangH();
                break;
            case 6:
                clearH();
                break;
            default:
                system("cls");
                goto menu;
            }

            cout << "\nPress any key to continue" << endl;
            getch();
            system("cls");

        } while (pil < 7);
    } else if (menu == 2) {
        initHT();
        do {
            cout << "Double Linked List Non Circular (DLLNC) (Head dan Tail)" << endl;
            cout << "=======================================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Reset" << endl;
            cout << "7. Kembali ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);

            switch (pil) {
            case 1:
                tambahDepanHT();
                break;
            case 2:
                tambahBelakangHT();
                break;
            case 3:
                tampilkanHT();
                break;
            case 4:
                hapusDepanHT();
                break;
            case 5:
                hapusBelakangHT();
                break;
            case 6:
                clearHT();
                break;
            default:
                system("cls");
                goto menu;
            }

            cout << "\nPress any key to continue" << endl;
            getch();
            system("cls");

        } while (pil < 7);
    } else {
        cout << "\nTERIMA KASIH" << endl;
        cout << "Program was made by [nama] ([NIM])" << endl;
    }
}

void initH() {
    head = NULL;
}

void initHT() {
    head = NULL;
    tail = NULL;
}

int isEmptyH() {
    return head == NULL;
}

int isEmptyHT() {
    return head == NULL && tail == NULL;
}

void tambahDepanH() {
    cout << "Masukkan data : ";
    cin >> dataBaru;
    TNode *baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;
    if (isEmptyH()) {
        head = baru;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian depan.";
}

void tambahDepanHT() {
    cout << "Masukkan data : ";
    cin >> dataBaru;
    TNode *baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;
    if (isEmptyHT()) {
        head = baru;
        tail = baru;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian depan.";
}

void tambahBelakangH() {
    cout << "Masukkan data : ";
    cin >> dataBaru;
    TNode *baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;
    if (isEmptyH()) {
        head = baru;
    } else {
        TNode *bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
        baru->prev = bantu;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian belakang.";
}

void tambahBelakangHT() {
    cout << "Masukkan data : ";
    cin >> dataBaru;
    TNode *baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;
    if (isEmptyHT()) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian belakang.";
}

void hapusDepanH() {
    if (isEmptyH()) {
        cout << "Data masih kosong!" << endl;
    } else {
        TNode *hapus = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete hapus;
        cout << "Data berhasil dihapus dari depan." << endl;
    }
}

void hapusDepanHT() {
    if (isEmptyHT()) {
        cout << "Data masih kosong!" << endl;
    } else {
        TNode *hapus = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete hapus;
        cout << "Data berhasil dihapus dari depan." << endl;
    }
}

void hapusBelakangH() {
    if (isEmptyH()) {
        cout << "Data masih kosong!" << endl;
    } else {
        TNode *hapus;
        if (head->next == NULL) {
            hapus = head;
            head = NULL;
        } else {
            TNode *bantu = head;
            while (bantu->next->next != NULL) {
                bantu = bantu->next;
            }
            hapus = bantu->next;
            bantu->next = NULL;
        }
        delete hapus;
        cout << "Data berhasil dihapus dari belakang." << endl;
    }
}

void hapusBelakangHT() {
    if (isEmptyHT()) {
        cout << "Data masih kosong!" << endl;
    } else {
        TNode *hapus = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
        delete hapus;
        cout << "Data berhasil dihapus dari belakang." << endl;
    }
}

void tampilkanH() {
    if (isEmptyH()) {
        cout << "Data masih kosong!" << endl;
    } else {
        TNode *bantu = head;
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    }
}

void tampilkanHT() {
    if (isEmptyHT()) {
        cout << "Data masih kosong!" << endl;
    } else {
        TNode *bantu = head;
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    }
}

void clearH() {
    while (!isEmptyH()) {
        hapusDepanH();
    }
    cout << "Data berhasil di-reset." << endl;
}

void clearHT() {
    while (!isEmptyHT()) {
        hapusDepanHT();
    }
    cout << "Data berhasil di-reset." << endl;
}
