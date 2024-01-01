#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class laporanKeuangan
{
private:
    string mobil, noPlat;
    int penghasilan, modal;
    int jumlahHari;
    string deskripsi;
    string namaPeminjam;
    static int totalKeuntungan; // Menyimpan total keuntungan dari semua laporan

public:
    laporanKeuangan(string peminjam, string mobil, string plat, int penghasilan,
                    int modal, int hari, string desc)
        : namaPeminjam(peminjam), mobil(mobil), noPlat(plat),
          penghasilan(penghasilan), modal(modal), jumlahHari(hari),
          deskripsi(desc)
    {
        totalKeuntungan += penghasilan; // Tambahkan keuntungan ke totalKeuntungan
    }

    void cetak()
    {
        cout << "Customer    : " << namaPeminjam << endl;
        cout << "Merek mobil : " << mobil << endl;
        cout << "Nomor plat  : " << noPlat << endl;
        cout << "Jumlah hari : " << jumlahHari << endl;
        cout << "Modal       : " << modal << endl;
        cout << "Keuntungan  : " << penghasilan << endl;
        cout << "Deskripsi   : " << deskripsi << endl
             << endl;
    }

    void simpanKeFile(ofstream &file) const
    {
        file << "Customer    : " << namaPeminjam << endl;
        file << "Merek mobil : " << mobil << endl;
        file << "Nomor plat  : " << noPlat << endl;
        file << "Jumlah hari : " << jumlahHari << endl;
        file << "Modal       : " << modal << endl;
        file << "Keuntungan  : " << penghasilan << endl;
        file << "Deskripsi   : " << deskripsi << endl
             << endl;
    }

    static int getTotalKeuntungan() { return totalKeuntungan; }
};

// Inisialisasi variabel statik
int laporanKeuangan::totalKeuntungan = 0;

void tambahData(vector<laporanKeuangan> &laporan, ofstream &outputFile)
{
    string peminjam, mobil, plat, desc;
    int penghasilan, modal, hari;

    cout << "Masukkan Nama Peminjam: ";
    cin.ignore();
    getline(cin, peminjam);
    cout << "Masukkan Merek Mobil: ";
    getline(cin, mobil);
    cout << "Masukkan Nomor Plat: ";
    getline(cin, plat);
    cout << "Masukkan Penghasilan: ";
    cin >> penghasilan;
    cout << "Masukkan Modal: ";
    cin >> modal;
    cout << "Masukkan Jumlah Hari: ";
    cin >> hari;
    cout << "Masukkan Deskripsi: ";
    cin.ignore();
    getline(cin, desc);

    laporan.emplace_back(peminjam, mobil, plat, penghasilan, modal, hari, desc);

    // Update the file immediately when data is added
    laporan.back().simpanKeFile(outputFile);
}

void hapusData(vector<laporanKeuangan> &laporan, ofstream &outputFile)
{
    int index;
    cout << "Masukkan indeks data yang ingin dihapus: ";
    cin >> index;

    if (index >= 0 && index < laporan.size())
    {
        laporan.erase(laporan.begin() + index);
        cout << "Data berhasil dihapus." << endl;

        // Reopen the file and write the updated data
        outputFile.close();
        outputFile.open("laporan.txt");
        for (const laporanKeuangan &item : laporan)
        {
            item.simpanKeFile(outputFile);
        }
        outputFile.close();
    }
    else
    {
        cout << "Indeks tidak valid." << endl;
    }
}

void menuLaporanArray(){
        vector<laporanKeuangan> laporan;
    ofstream outputFile("laporan.txt", ios::app); // Open for appending

    // Load data from the file (if it exists)
    ifstream inputFile("laporan.txt");
    if (inputFile.is_open())
    {
        string line;
        string peminjam, mobil, plat, desc;
        int penghasilan, modal, hari;
        while (getline(inputFile, line))
        {
            if (line.find("Customer") != string::npos)
            {
                peminjam = line.substr(line.find(": ") + 2);
                getline(inputFile, line); // Read the next line for "Merek mobil"
                mobil = line.substr(line.find(": ") + 2);
                getline(inputFile, line); // Read the next line for "Nomor plat"
                plat = line.substr(line.find(": ") + 2);
                getline(inputFile, line); // Read the next line for "Jumlah hari"
                hari = stoi(line.substr(line.find(": ") + 2));
                getline(inputFile, line); // Read the next line for "Modal"
                modal = stoi(line.substr(line.find(": ") + 2));
                getline(inputFile, line); // Read the next line for "Keuntungan"
                penghasilan = stoi(line.substr(line.find(": ") + 2));
                getline(inputFile, line); // Read the next line for "Deskripsi"
                desc = line.substr(line.find(": ") + 2);
                laporan.emplace_back(peminjam, mobil, plat, penghasilan, modal, hari, desc);
            }
        }
        inputFile.close();
    }

    int choice;
    do
    {
        cout << "Menu:" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Cetak Data" << endl;
        cout << "4. Output Ukuran Array" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tambahData(laporan, outputFile);
            break;
        case 2:
            hapusData(laporan, outputFile);
            break;
        case 3:
            for (laporanKeuangan &laporanItem : laporan)
            {
                laporanItem.cetak();
            }
            break;
        case 4:
            cout << "Ukuran Array: " << laporan.size() << endl;
            break;
        case 0:
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (choice != 0);

    outputFile.close(); // Close the file

    cout << "Data telah disimpan ke dalam laporan.txt" << endl;

    // Menampilkan total keuntungan dari semua laporan
    cout << "Total Keuntungan: " << laporanKeuangan::getTotalKeuntungan() << endl;

}
