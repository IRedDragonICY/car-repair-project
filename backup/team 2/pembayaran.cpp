#include <fstream>
#include <iostream>
using namespace std;

class TypeOfPayment {
public:
  void tunai(int totalAmount) {
    if (totalAmount > 0) {
      cout << "Pembayaran tunai sebesar " << totalAmount << " berhasil."
           << endl;
    } else {
      cout << "Total pembayaran tidak valid." << endl;
    }
  }

  void kartuKredit(const string &cardNumber, int totalAmount) {
    if (totalAmount > 0 && isValidCardNumber(cardNumber)) {
      cout << "Pembayaran dengan kartu kredit (" << cardNumber << ") sebesar "
           << totalAmount << " berhasil." << endl;
    } else {
      cout << "Nomor kartu kredit atau total pembayaran tidak valid." << endl;
    }
  }

  void transferBank(const string &bankAccount, int totalAmount) {
    if (totalAmount > 0 && isValidBankAccount(bankAccount)) {
      cout << "Pembayaran melalui transfer bank (" << bankAccount
           << ") sebesar " << totalAmount << " berhasil." << endl;
    } else {
      cout << "Nomor rekening bank atau total pembayaran tidak valid." << endl;
    }
  }

private:
  bool isValidCardNumber(const string &cardNumber) {
    // Implementasi validasi nomor kartu kredit
    return true; // Implementasi sesuai kebutuhan Anda
  }

  bool isValidBankAccount(const string &bankAccount) {
    // Implementasi validasi nomor rekening bank
    return true; // Implementasi sesuai kebutuhan Anda
  }
};

int main() {
  TypeOfPayment paymentProcessor;
  int pilihan;
  int totalAmount;
  string cardNumber;
  string bankAccount;

  cout << "Pilihan: " << endl;
  cout << "1. Pembayaran Tunai" << endl;
  cout << "2. Pembayaran Kartu Kredit" << endl;
  cout << "3. Pembayaran Transfer Bank" << endl;
  cout << "Pilih metode pembayaran (1/2/3): ";

  while (true) {
    cin >> pilihan;

    switch (pilihan) {
    case 1:
      cout << "Masukkan total pembayaran tunai: ";
      cin >> totalAmount;
      paymentProcessor.tunai(totalAmount);
      break;

    case 2:
      cout << "Masukkan nomor kartu kredit: ";
      cin >> cardNumber;
      cout << "Masukkan total pembayaran: ";
      cin >> totalAmount;
      paymentProcessor.kartuKredit(cardNumber, totalAmount);
      break;

    case 3:
      cout << "Masukkan nomor rekening bank: ";
      cin >> bankAccount;
      cout << "Masukkan total pembayaran: ";
      cin >> totalAmount;
      paymentProcessor.transferBank(bankAccount, totalAmount);
      break;

    default:
      cout << "Pilihan tidak valid. Pilih 1, 2, atau 3." << endl;
      break;
    }
  }

  return 0;
}
