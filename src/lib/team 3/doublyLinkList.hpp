#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct dataLaporanDoublylinkedlist {
  string mobil, noPlat;
  int penghasilan, modal;
  int jumlahHari;
  string deskripsi;
  string namaPeminjam;
  static int totalKeuntungan;
  dataLaporanDoublylinkedlist *next;
  dataLaporanDoublylinkedlist *prev;

  dataLaporanDoublylinkedlist(string peminjam, string mobil, string plat, int penghasilan,
              int modal, int hari, string desc)
      : namaPeminjam(peminjam), mobil(mobil), noPlat(plat),
        penghasilan(penghasilan), modal(modal), jumlahHari(hari),
        deskripsi(desc), next(nullptr), prev(nullptr) {
    totalKeuntungan += penghasilan;
  }
};

int dataLaporanDoublylinkedlist::totalKeuntungan = 0;

class laporanKeuanganDoublylinkedlist {
private:
  dataLaporanDoublylinkedlist *head;
  dataLaporanDoublylinkedlist *tail;

public:
  laporanKeuanganDoublylinkedlist() : head(nullptr), tail(nullptr) {}

  void tambahData(string peminjam, string mobil, string plat, int penghasilan,
                  int modal, int hari, string desc) {
    dataLaporanDoublylinkedlist *newData =
        new dataLaporanDoublylinkedlist(peminjam, mobil, plat, penghasilan, modal, hari, desc);

    if (!head) {
      head = newData;
      tail = newData;
    } else {
      tail->next = newData;
      newData->prev = tail;
      tail = newData;
    }
  }
  void saveData() {
    ofstream ofs("laporan.txt");
    dataLaporanDoublylinkedlist *current = head;
    while (current != nullptr) {
      ofs << "Customer : " << current->namaPeminjam << endl
          << "Merek Mobil : " << current->mobil << endl
          << "Nomor Plat : " << current->noPlat << endl
          << "Jumlah Hari : " << current->jumlahHari << endl
          << "Modal : " << current->modal << endl
          << "Keuntungan : " << current->totalKeuntungan << endl
          << "Deskripsi : " << current->deskripsi << endl
          << endl;

      current = current->next;
    }
    ofs.close();
  }
  void hapusData(int index) {
    if (index < 0) {
      cout << "Indeks tidak valid." << endl;
      return;
    }

    if (index == 0) {
      dataLaporanDoublylinkedlist *temp = head;
      head = head->next;
      if (head) {
        head->prev = nullptr;
      }
      delete temp;
      return;
    }

    dataLaporanDoublylinkedlist *current = head;
    int i = 0;
    while (current && i < index - 1) {
      current = current->next;
      i++;
    }

    if (!current || !current->next) {
      cout << "Indeks tidak valid." << endl;
      return;
    }

    dataLaporanDoublylinkedlist *temp = current->next;
    current->next = temp->next;
    if (temp->next) {
      temp->next->prev = current;
    }
    delete temp;
  }

  void cetakData() {
    dataLaporanDoublylinkedlist *current = head;
    while (current) {
      cout << "Customer    : " << current->namaPeminjam << endl;
      cout << "Merek mobil : " << current->mobil << endl;
      cout << "Nomor plat  : " << current->noPlat << endl;
      cout << "Jumlah hari : " << current->jumlahHari << endl;
      cout << "Modal       : " << current->modal << endl;
      cout << "Keuntungan  : " << current->penghasilan << endl;
      cout << "Deskripsi   : " << current->deskripsi << endl << endl;

      current = current->next;
    }
  }

  int getTotalKeuntungan() { return dataLaporanDoublylinkedlist::totalKeuntungan; }
};

void menuLaporanDoublyLinkedList() {
  laporanKeuanganDoublylinkedlist laporan;
  int choice;
  ifstream inputFile("laporan.txt");
  if (inputFile.is_open()) {
    string line;
    string peminjam, mobil, plat, desc;
    int penghasilan, modal, hari;
    while (getline(inputFile, line)) {
      if (line.find("Customer") != string::npos) {
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
        laporan.tambahData(peminjam, mobil, plat, penghasilan, modal, hari,
                           desc);
      }
    }
    inputFile.close();
  }
  do {
    cout << "Menu:" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Cetak Data" << endl;
    cout << "4. Output Total Keuntungan" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> choice;
    string peminjam, mobil, plat, desc;
    int penghasilan, modal, hari;
    switch (choice) {
    case 1:

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

      laporan.tambahData(peminjam, mobil, plat, penghasilan, modal, hari, desc);
      break;

    case 2:
      int index;
      cout << "Masukkan indeks data yang ingin dihapus: ";
      cin >> index;
      laporan.hapusData(index);
      break;

    case 3:
      laporan.cetakData();
      break;

    case 4:
      cout << "Total Keuntungan: " << laporan.getTotalKeuntungan() << endl;
      break;

    case 0:
      break;

    default:
      cout << "Pilihan tidak valid." << endl;
      break;
    }
    laporan.saveData();
  } while (choice != 0);
}
