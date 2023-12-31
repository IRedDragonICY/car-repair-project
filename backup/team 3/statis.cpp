#include <fstream>
#include <iostream>
using namespace std;

class laporanKeuangan {
private:
  string mobil, noPlat;
  int penghasilan, modal;
  int jumlahHari;
  string deskripsi;
  string namaPeminjam;

public:
  laporanKeuangan(string peminjam, string mobil, string plat, int penghasilan,
                  int modal, int hari, string desc)
      : namaPeminjam(peminjam), mobil(mobil), noPlat(plat),
        penghasilan(penghasilan), modal(modal), jumlahHari(hari),
        deskripsi(desc) {}

  void cetak() {
    cout << "Customer    : " << namaPeminjam << endl;
    cout << "Merek mobil : " << mobil << endl;
    cout << "Nomor plat  : " << noPlat << endl;
    cout << "Jumlah hari : " << jumlahHari << endl;
    cout << "Modal       : " << modal << endl;
    cout << "Keuntungan  : " << penghasilan << endl;
    cout << "Deskripsi   : " << deskripsi << endl << endl;
  }

  void simpanKeFile(ofstream &file) {
    file << "Customer    : " << namaPeminjam << endl;
    file << "Merek mobil : " << mobil << endl;
    file << "Nomor plat  : " << noPlat << endl;
    file << "Jumlah hari : " << jumlahHari << endl;
    file << "Modal       : " << modal << endl;
    file << "Keuntungan  : " << penghasilan << endl;
    file << "Deskripsi   : " << deskripsi << endl << endl;
  }
};

int main() {
  ofstream outputFile("laporan.txt");

  laporanKeuangan x[3] = {
      laporanKeuangan("Rafi", "Avanza", "AB 5771 XC", 1000000, 100000000, 10,
                      "Avanza, warna putih, di Jakarta"),
      laporanKeuangan("Fathur", "Kaslan", "AB 1289 DK", 1250000, 300000000, 7,
                      "Kaslan, warna hitam, di Jogja"),
      laporanKeuangan("Raka", "Porsche", "AB 6942 MK", 19200000, 215000000, 15,
                      "Porsche, warna merah, di Palembang")};

  for (int i = 0; i < 3; i++) {
    x[i].cetak();
    x[i].simpanKeFile(outputFile);
  }

  outputFile.close();

  cout << "Data telah disimpan ke dalam laporan.txt" << endl;

  return 0;
}
