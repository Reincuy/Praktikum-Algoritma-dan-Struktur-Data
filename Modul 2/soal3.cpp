#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 10
using namespace std;

void INSERT();
void DELETE();
void CETAKLAYAR();
void Inisialisasi();
void RESET();

int PIL, F, R;
char PILIHAN[1], HURUF;
char Q[n];

int main() {
    Inisialisasi();
    do {
        cout << "=====" << endl;
        cout << "QUEUE" << endl;
        cout << "=====" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN: ";
        cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL) {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            default:
                cout << "TERIMA KASIH" << endl;
                break;
        }

        cout << "Press any key to continue" << endl;
        getch();
        system("cls");

    } while (PIL < 4);

    return 0;
}

void Inisialisasi() {
    F = -1;
    R = -1;
}

void INSERT() {
    if (R == n - 1) {
        cout << "Queue penuh" << endl;
    } else {
        cout << "Masukkan huruf: ";
        cin >> HURUF;
        if (F == -1) {
            F = 0;
        }
        R++;
        Q[R] = HURUF;
        cout << "Huruf " << HURUF << " dimasukkan ke dalam queue" << endl;
    }
}

void DELETE() {
    if (F == -1 || F > R) {
        cout << "Queue kosong" << endl;
    } else {
        cout << "Huruf " << Q[F] << " dihapus dari queue" << endl;
        F++;
        if (F > R) {
            Inisialisasi();
        }
    }
}

void CETAKLAYAR() {
    if (F == -1) {
        cout << "Queue kosong" << endl;
    } else {
        cout << "Isi queue: " << endl;
        for (int i = F; i <= R; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}

void RESET() {
    Inisialisasi();
    cout << "Queue telah di-reset" << endl;
}
