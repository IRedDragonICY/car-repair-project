#include "lib/team 1/pengembalian.hpp"
#include "lib/team 2/auth.hpp"
#include "lib/team 2/pembayaran.hpp"
#include "lib/team 3/laporan.hpp"
#include "lib/team 4/deskripsi.hpp"
#include "lib/team 5/faq.hpp"
#include "lib/team 6/voucher.hpp"
#include <map>

void menu(userAuthentication& auth) {
    while (true){
        string pilih;
        cout << "Halo, " << auth.userTampil << "!" << endl;
        cout << "Menu" << endl;
        cout << "1. deskripsi mobil" << endl;
        cout << "2. laporan keuangan" << endl;
        cout << "3. pengembalian mobil" << endl;
        cout << "4. voucher" << endl;
        cout << "5. pembayaran" << endl;
        cout << "0. Logout" << endl;
        cout << "Untuk melakukan F.A.Q, silahkan tulis /?" << endl;
        cout << "Pilih menu: ";
        cin >> pilih;

        std::map<string, std::function<void()>> cases {
            {"0", [&]() { auth.logout(); }},
            {"1", [&]() { menuDeskripsiMobil(); }},
            {"2", [&]() { menuLaporan(); }},
            {"3", [&]() { menuPengembalian(); }},
            {"4", [&]() { menuVoucher(); }},
            {"5", [&]() { menuPembayaran(); }},
            {"/?", [&]() { menuFAQ(); }}
        };

        if (cases.count(pilih) > 0) {
            cases[pilih]();
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }
}
int main() {
    userAuthentication auth;
	while (true) {
        auth.handleUser();

        if (auth.getLoggedIn()) {
            menu(auth);
        }
	}
    return 0;
}