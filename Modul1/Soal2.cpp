#include <iostream>
#include <string>
using namespace std;

struct Kendaraan {
    string platNomor;
    string jenis;
    string namaPemilik;
    string alamat;
    string kota;
};

int main() {
    Kendaraan kendaraan;
    
    kendaraan.platNomor = "DA1234MK";
    kendaraan.jenis = "RUSH";
    kendaraan.namaPemilik = "Andika Hartanto";
    kendaraan.alamat = "Jl. Kayu Tangi 1";
    kendaraan.kota = "Banjarmasin";
    
    cout << "a. Plat Nomor Kendaraan : " << kendaraan.platNomor << endl;
    cout << "b. Jenis Kendaraan      : " << kendaraan.jenis << endl;
    cout << "c. Nama Pemilik         : " << kendaraan.namaPemilik << endl;
    cout << "d. Alamat               : " << kendaraan.alamat << endl;
    cout << "e. Kota                 : " << kendaraan.kota << endl;
    
    return 0;
}
