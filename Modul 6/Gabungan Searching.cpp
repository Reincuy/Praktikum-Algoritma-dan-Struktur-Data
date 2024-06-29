#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int random(int bil) {
    return rand() % bil;
}

void randomize() {
    srand(time(NULL));
}

void clrscr() {
    system("cls");
}

void sequential_searching() {
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();
    printf("Generating 100 numbers . . .\n");
    for (int i = 0; i < 100; i++) {
        data[i] = random(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\nDone.\n");

    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1) {
        printf("Data found, occurrences: %d!\n", counter);
        printf("At index: %d\n", save);
    } else {
        printf("Data not found\n");
    }
}

void binary_searching() {
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Enter the number of data: ";
    cin >> n;
    int angka[n];
    for (int i = 0; i < n; i++) {
        cout << "Number [" << i << "]: ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (angka[j] > angka[j + 1]) {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
    cout << "================================================================\n";
    cout << "Sorted data:\n";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << "\n================================================================\n";
    cout << "Enter the number to search: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah]) {
            ketemu = true;
            break;
        } else if (key < angka[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }
    if (ketemu) {
        cout << "Number found\n";
    } else {
        cout << "Number not found\n";
    }
}

void explain_difference() {
    cout << "Sequential Searching:\n";
    cout << "- Sequential search involves checking each element of the list one by one.\n";
    cout << "- It is simple and does not require the list to be sorted.\n";
    cout << "- Time complexity: O(n).\n";
    cout << "\nBinary Searching:\n";
    cout << "- Binary search involves repeatedly dividing the search interval in half.\n";
    cout << "- It requires the list to be sorted.\n";
    cout << "- Time complexity: O(log n).\n";
    cout << "\nAdvantages of Sequential Search:\n";
    cout << "- Simple and easy to implement.\n";
    cout << "- Does not require the data to be sorted.\n";
    cout << "\nDisadvantages of Sequential Search:\n";
    cout << "- Inefficient for large datasets.\n";
    cout << "- Time-consuming.\n";
    cout << "\nAdvantages of Binary Search:\n";
    cout << "- Much faster for large datasets compared to sequential search.\n";
    cout << "- Efficient for sorted data.\n";
    cout << "\nDisadvantages of Binary Search:\n";
    cout << "- Requires sorted data.\n";
    cout << "- More complex to implement compared to sequential search.\n";
}

int main() {
    int choice;
    do {
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> choice;

        switch (choice) {
            case 1:
                sequential_searching();
                break;
            case 2:
                binary_searching();
                break;
            case 3:
                explain_difference();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
