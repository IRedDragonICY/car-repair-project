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
#include "lib/team 13/opsiCabangSewa.hpp"
#include <map>

void menu(userAuthentication& auth) {
    while (true){
        string pilih;
        cout << "Halo, " << auth.userTampil << "!" << endl;
        cout << "Menu" << endl;
        cout << "1. booking" << endl;
        cout << "2. cabang sewa" << endl;
        cout << "3. pilih supir" << endl;
        cout << "4. deskripsi mobil" << endl;
        cout << "5. cari tipe mobil" << endl;
        cout << "6. laporan keuangan" << endl;
        cout << "7. laporan kerusakan" << endl;
        cout << "8. pengembalian mobil" << endl;
        cout << "9. voucher" << endl;
        cout << "10. pembayaran" << endl;
        cout << "11. ulasan" << endl;
        cout << "12. identitas supir" << endl;
        cout << "0. Logout" << endl;
        cout << "Untuk melakukan F.A.Q, silahkan tulis /?" << endl;
        cout << "Pilih menu: ";
        cin >> pilih;

        std::map<string, std::function<void()>> cases {
            {"0", [&]() { auth.logout(); }},
            {"1", [&]() { menuBooking(); }},
            {"2", [&]() { menuOpsiCabangSewa(); }},
            {"3", [&]() { menuPilihSupir(); }},
            {"4", [&]() { menuDeskripsiMobil(); }},
            {"5", [&]() { menuCariTipeMobil(); }},
            {"6", [&]() { menuLaporanKeuangan(); }},
            {"7", [&]() { menuLaporanKerusakan(); }},
            {"8", [&]() { menuPengembalian(); }},
            {"9", [&]() { menuVoucher(); }},
            {"10", [&]() { menuPembayaran(); }},
            {"11", [&]() { menuUlasan(); }},
            {"12", [&]() { menuIdentitasSupir(); }},
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