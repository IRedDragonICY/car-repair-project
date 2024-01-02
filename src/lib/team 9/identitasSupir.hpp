#include <iostream>
#include <string>

using namespace std;

class Supir {
public:
    string nama;
    string alamat;
    int usia;

    void inputBiodata() {
        cin.ignore();

        cout << "Masukkan Nama Supir: ";
        getline(cin, nama);

        cout << "Masukkan Alamat Supir: ";
        getline(cin, alamat);

        cout << "Masukkan Usia Supir: ";
        cin >> usia;
    }

    void tampilkanBiodata() {
        cout << "\nBiodata Supir\n";
        cout << "Nama: " << nama << endl;
        cout << "Alamat: " << alamat << endl;
        cout << "Usia: " << usia << " tahun" << endl;
    }
};

void menuIdentitasSupir() {
    const int jumlahSupir = 3;
    Supir supir[jumlahSupir];

    for (int i = 0; i < jumlahSupir; ++i) {
        cout << "Masukkan biodata Supir ke-" << i + 1 << endl;
        supir[i].inputBiodata();
    }

    cout << "\nData Biodata Supir:\n";
    for (int i = 0; i < jumlahSupir; ++i) {
        cout << "\nBiodata Supir ke-" << i + 1 << endl;
        supir[i].tampilkanBiodata();
    }

}
