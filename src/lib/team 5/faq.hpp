#include <iostream>
#include <string>
using namespace std;

class PusatBantuan {
public:
    PusatBantuan() {
        InisialisasiFAQ();
    }

    void InisialisasiFAQ() {
        faq[0] = FAQ("Bagaimana cara melakukan reservasi mobil?", "Anda dapat melakukan reservasi melalui situs web kami atau menghubungi layanan pelanggan kami.");
        faq[1] = FAQ("Apa persyaratan untuk menyewa mobil?", "Anda perlu memiliki SIM yang masih berlaku, kartu kredit, dan usia minimal 21 tahun.");
        faq[2] = FAQ("Berapa harga sewa mobil per hari?", "Harga sewa mobil berbeda-beda tergantung pada jenis mobil yang Anda pilih dan durasi sewanya.");
    }

    void TampilkanMenu() {
        cout << "Selamat datang di Pusat Bantuan dan Dukungan Penyewaan Mobil" << endl;
        cout << "1. FAQ (Pertanyaan Umum)" << endl;
        cout << "2. Bantuan" << endl;
        cout << "3. Dukungan" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih salah satu opsi (1/2/3/4): ";
    }

    void TampilkanFAQ() const {
        cout << "===== FAQ (Pertanyaan Umum) =====" << endl;
        for (const FAQ& pertanyaan : faq) {
            cout << "Pertanyaan: " << pertanyaan.GetPertanyaan() << endl;
            cout << "Jawaban: " << pertanyaan.GetJawaban() << endl << endl;
        }
    }

    void TampilkanBantuan() const {
        cout << "===== Bantuan =====" << endl;
        cout << "Jika Anda memerlukan bantuan tambahan, silakan hubungi layanan pelanggan kami di nomor XXX-XXXX." << endl;
    }

    void TampilkanDukungan() const {
        cout << "===== Dukungan =====" << endl;
        cout << "Jika Anda mengalami masalah teknis saat menggunakan layanan kami, silakan kirim email ke support@sewamobil.com." << endl;
    }

private:
    class FAQ {
    public:
        FAQ() {}
        FAQ(string pertanyaan, string jawaban) : pertanyaan(pertanyaan), jawaban(jawaban) {}

        string GetPertanyaan() const {
            return pertanyaan;
        }

        string GetJawaban() const {
            return jawaban;
        }

    private:
        string pertanyaan;
        string jawaban;
    };

    FAQ faq[3]; 
};

void menuFAQ() {
    PusatBantuan pusatBantuan;

    while (true) {
        pusatBantuan.TampilkanMenu();

        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                pusatBantuan.TampilkanFAQ();
                break;
            case 2:
                pusatBantuan.TampilkanBantuan();
                break;
            case 3:
                pusatBantuan.TampilkanDukungan();
                break;
            case 4:
                cout << "Terima kasih telah menghubungi Pusat Bantuan dan Dukungan Penyewaan Mobil." << endl;
                goto exitMenuFAQ;
            default:
                cout << "Pilihan tidak valid. Silakan pilih 1, 2, 3, atau 4." << endl;
                break;
        }

        char lanjutkan;
        cout << "Apakah Anda ingin melanjutkan (y/n)? ";
        cin >> lanjutkan;

        if (lanjutkan != 'y' && lanjutkan != 'Y') {
            cout << "Terima kasih telah menghubungi Pusat Bantuan dan Dukungan Penyewaan Mobil." << endl;
            break;
        }
    }
    exitMenuFAQ:
    return;
}