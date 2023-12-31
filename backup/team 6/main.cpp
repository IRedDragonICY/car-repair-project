#include <iostream>
#include <string>

using namespace std;

class RentalMobil {
private:
    string vocher[3] = {"September99", "Oktober1010", "November1111"};
    double hargaSewa;

public:
    RentalMobil() : hargaSewa(0.0) {}

    void setHargaSewa(double harga) {
        hargaSewa = harga;
    }

    double hitungDiskon() {
        if (vocher[0] == "Oktober1010") {
            return 0.1 * hargaSewa;
        }
        return 0.0;
    }

    void setVocher(int index) {
        if (index >= 0 && index < 3) {
            vocher[0] = vocher[index];
        }
    }
};

int main() {
    RentalMobil mobil;

    double hargaSewaAwal = 500000.0;

    cout << "Pilih kode voucher (0: September99, 1: Oktober1010, 2: November1111): ";
    int kodeVoucherIndex;
    cin >> kodeVoucherIndex;

    mobil.setHargaSewa(hargaSewaAwal);

    // Menggunakan diskon jika kode voucher sesuai
    if (kodeVoucherIndex >= 0 && kodeVoucherIndex < 3) {
        mobil.setVocher(kodeVoucherIndex);
        double diskon = mobil.hitungDiskon();
        cout << "Anda mendapatkan diskon 10%: Rp " << diskon << endl;
        hargaSewaAwal -= diskon;
    } else {
        cout << "Kode voucher tidak valid." << endl;
    }

    cout << "Harga sewa setelah diskon: Rp " << hargaSewaAwal << endl;

    return 0;
}
