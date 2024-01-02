#include "lib/team 1/pengembalian.hpp"
#include "lib/team 2/auth.hpp"
#include "lib/team 2/pembayaran.hpp"
#include "lib/team 3/laporan.hpp"
#include "lib/team 4/deskripsi.hpp"
#include "lib/team 5/faq.hpp"
#include "lib/team 6/voucher.hpp"
#include "lib/team 7/laporanKerusakan.hpp"
#include "lib/team 8/ulasan.hpp"
#include "lib/team 9/identitasSupir.hpp"
#include "lib/team 10/booking.hpp"
#include "lib/team 11/pilihSupir.hpp"
#include "lib/team 12/cariTipeMobil.hpp"

#include <map>

void menu(userAuthentication& auth) {
    while (true){
        string pilih;
        cout << "Halo, " << auth.userTampil << "!" << endl;
        cout << "Menu" << endl;
        cout << "1. booking" << endl;
        cout << "2. pilih supir" << endl;
        cout << "3. deskripsi mobil" << endl;
        cout << "4. cari tipe mobil" << endl;
        cout << "4. laporan keuangan" << endl;
        cout << "5. laporan kerusakan" << endl;
        cout << "6. pengembalian mobil" << endl;
        cout << "7. voucher" << endl;
        cout << "8. pembayaran" << endl;
        cout << "9. ulasan" << endl;
        cout << "10. identitas supir" << endl;
        cout << "0. Logout" << endl;
        cout << "Untuk melakukan F.A.Q, silahkan tulis /?" << endl;
        cout << "Pilih menu: ";
        cin >> pilih;

        std::map<string, std::function<void()>> cases {
            {"0", [&]() { auth.logout(); }},
            {"1", [&]() { menuBooking(); }},
            {"2", [&]() { menuPilihSupir(); }},
            {"3", [&]() { menuDeskripsiMobil(); }},
            {"4", [&]() { menuCariTipeMobil(); }},
            {"5", [&]() { menuLaporanKeuangan(); }},
            {"6", [&]() { menuLaporanKerusakan(); }},
            {"7", [&]() { menuPengembalian(); }},
            {"8", [&]() { menuVoucher(); }},
            {"9", [&]() { menuPembayaran(); }},
            {"10", [&]() { menuUlasan(); }},
            {"11", [&]() { menuIdentitasSupir(); }},
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