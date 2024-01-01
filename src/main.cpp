#include "lib/team 1/pengembalian.hpp"
#include "lib/team 2/auth.hpp"
#include "lib/team 2/pembayaran.hpp"
#include "lib/team 3/laporan.hpp"
#include "lib/team 4/deskripsi.hpp"

void menu() {
    int pilih;
    cout << "Menu" << endl;
    cout << "1. deskripsi mobil" << endl;
    cout << "2. laporan keuangan" << endl;
    cout << "3. pengembalian mobil" << endl;
    cout << "4. pembayaran" << endl;
    cout << "Pilih menu: ";
    cin >> pilih;
    switch (pilih) {
    case 1:
        menuDeskripsiMobil();
        break;
    case 2:
        menuLaporan();
        break;
    case 3:
        menuPengembalian();
        break;
    case 4:
        menuPembayaran();
        break;
    default:
        cout << "Pilihan tidak valid." << endl;
        break;
    }
}

int main() {
    userAuthentication auth;
	while (true) {
		auth.handleUser();

        if (auth.getLoggedIn()) {
            menu();
        }
	}
    return 0;
}