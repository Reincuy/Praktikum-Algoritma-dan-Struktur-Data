#include <iostream>
using namespace std;

const int MAX = 100; 

struct Stack {
    int data[MAX];
    int atas;
} Tumpuk;

int kosong() {
    return (Tumpuk.atas == -1) ? 1 : 0;
}

int penuh() {
    return (Tumpuk.atas == MAX - 1) ? 1 : 0;
}

void input(int data) {
    if (penuh() == 1) {
        cout << "Tumpukan Penuh" << endl;
    } else {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack " << endl;
    }
}

void hapus() {
    if (kosong() == 1) {
        cout << "Data Kosong" << endl;
    } else {
        cout << "Data Teratas Sudah Terambil: " << Tumpuk.data[Tumpuk.atas] << endl;
        Tumpuk.atas--;
    }
}

void tampil() {
    if (kosong() == 1) {
        cout << "Tumpukan Kosong" << endl;
    } else {
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " : " << Tumpuk.data[i] << endl;
        }
    }
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !" << endl;
}

int main() {
    Tumpuk.atas = -1; 

    input(10);
    input(20);
    input(30);

    tampil();

    hapus();
    tampil();

    bersih();
    tampil();

    return 0;
}
