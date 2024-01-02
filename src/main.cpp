#include "lib/features.hpp"
#include <map>

void menu(userAuthentication& auth) {
    while (true){
        string pilih;
        int width = 48;

        string welcomeMsg = "Selamat Datang, " + auth.userTampil;
        
        int padding = (width - welcomeMsg.length()) / 2;
        cout << "\033[1;35m" << string(padding, '-') << welcomeMsg << string(padding, '-') << "\033[0m" << endl;

        cout << "\033[1;35m| 1. Booking            | 7. Laporan Kerusakan  |\033[0m" << endl;
        cout << "\033[1;35m| 2. Cabang Sewa        | 8. Pengembalian Mobil |\033[0m" << endl;
        cout << "\033[1;35m| 3. Pilih Supir        | 9. Voucher            |\033[0m" << endl;
        cout << "\033[1;35m| 4. Deskripsi Mobil    | 10. Pembayaran        |\033[0m" << endl;
        cout << "\033[1;35m| 5. Cari Tipe Mobil    | 11. Ulasan            |\033[0m" << endl;
        cout << "\033[1;35m| 6. Laporan Keuangan   | 12. Identitas Supir   |\033[0m" << endl;
        cout << "\033[1;35m| 0. Logout             |                       |\033[0m" << endl;
        cout << "\033[1;35m-------------------------------------------------\033[0m" << endl;
        cout << "\033[1;35mMasukkan pilihan Anda: \033[0m";
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
            cout << "\033[44;37mPilihan tidak valid.\033[0m" << endl;
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