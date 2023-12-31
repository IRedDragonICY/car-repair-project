#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct CabangSewa {
    string namaCabang;
    string lokasiCabang;
    int* stokMobil;
    CabangSewa* next;
    CabangSewa* previous;
    CabangSewa* left;
    CabangSewa* right;

    CabangSewa() : namaCabang(""), lokasiCabang(""), stokMobil(nullptr), next(nullptr), previous(nullptr), left(nullptr), right(nullptr) {}

    CabangSewa(const CabangSewa& cabang) : namaCabang(cabang.namaCabang), lokasiCabang(cabang.lokasiCabang), next(nullptr), previous(nullptr), left(nullptr), right(nullptr) {
        stokMobil = new int[3];
        for (int i = 0; i < 3; i++) {
            stokMobil[i] = cabang.stokMobil[i];
        }
    }
};

class ManajemenSewa {
public:
    ManajemenSewa() : cabangSewaHead(nullptr), cabangSewaTail(nullptr), cabangTreeRoot(nullptr) {}

    ~ManajemenSewa() {
        while (!cabangStack.empty()) {
            deleteCabang(cabangStack.top());
            cabangStack.pop();
        }

        deleteTree(cabangTreeRoot);
    }

    void tambahCabangManual() {
        CabangSewa cabang;
        cout << "Masukkan nama cabang: ";
        cin.ignore();
        getline(cin, cabang.namaCabang);
        cout << "Masukkan lokasi cabang: ";
        getline(cin, cabang.lokasiCabang);
        cabang.stokMobil = new int[3];
        cout << "Masukkan stok mobil (Tipe A, Tipe B, Tipe C): ";
        cin >> cabang.stokMobil[0] >> cabang.stokMobil[1] >> cabang.stokMobil[2];

        
        if (!cabangSewaHead) {
            cabangSewaHead = new CabangSewa(cabang);
            cabangSewaTail = cabangSewaHead;
        } else {
            cabangSewaTail->next = new CabangSewa(cabang);
            cabangSewaTail->next->previous = cabangSewaTail;
            cabangSewaTail = cabangSewaTail->next;
        }
        tambahKePohon(cabangTreeRoot, cabang);

        cout << "Cabang baru berhasil ditambahkan." << endl;

        cabangStack.push(cabangSewaTail);
    }

    void tampilCabang() {
        cout << "Daftar Cabang Penyewaan Mobil:" << endl;
        CabangSewa* current = cabangSewaHead;
        while (current) {
            cout << "Nama Cabang: " << current->namaCabang << endl;
            cout << "Lokasi: " << current->lokasiCabang << endl;
            cout << "Stok Mobil (Tipe A, Tipe B, Tipe C): ";
            for (int j = 0; j < 3; j++) {
                cout << current->stokMobil[j];
                if (j < 2) {
                    cout << ", ";
                }
            }
            cout << " unit" << endl;
            cout << "---------------------------" << endl;
            current = current->next;
        }
    }

    void hapusCabang(string namaCabang) {
        if (!cabangSewaHead) {
            cout << "Daftar cabang kosong." << endl;
            return;
        }

        CabangSewa* current = cabangSewaHead;
        while (current && current->namaCabang != namaCabang) {
            current = current->next;
        }

        if (current) {
            cabangQueue.push(current);

            if (current->previous) {
                current->previous->next = current->next;
            } else {
                cabangSewaHead = current->next;
            }

            if (current->next) {
                current->next->previous = current->previous;
            } else {
                cabangSewaTail = current->previous;
            }

            hapusDariPohon(cabangTreeRoot, current->namaCabang);

            cout << "Cabang berhasil dihapus." << endl;
        } else {
            cout << "Cabang dengan nama " << namaCabang << " tidak ditemukan." << endl;
        }
    }

    void batalHapusCabang() {
        if (cabangQueue.empty()) {
            cout << "Tidak ada operasi penghapusan yang dapat dibatalkan." << endl;
            return;
        }

        CabangSewa* cabang = cabangQueue.front();
        cabangQueue.pop();

        if (!cabangSewaHead) {
            cabangSewaHead = cabang;
            cabangSewaTail = cabangSewaHead;
        } else {
            cabangSewaTail->next = cabang;
            cabangSewaTail->next->previous = cabangSewaTail;
            cabangSewaTail = cabangSewaTail->next;
        }

        tambahKePohon(cabangTreeRoot, *cabang);

        cout << "Operasi penghapusan dibatalkan." << endl;
    }

    void tampilkanAntrianPrioritas() {
        cout << "Cabang yang terhapus:" << endl;
        queue<CabangSewa*> tempQueue = cabangQueue;
        while (!tempQueue.empty()) {
            CabangSewa* cabang = tempQueue.front();
            cout << cabang->namaCabang << " - ";
            tempQueue.pop();
        }
        cout << endl;
    }

    void tampilkanPohon() {
        cout << "Urutan Cabang:" << endl;
        preorderTraversal(cabangTreeRoot);
        cout << endl;
    }

private:2
    CabangSewa* cabangSewaHead;
    CabangSewa* cabangSewaTail;
    stack<CabangSewa*> cabangStack;
    queue<CabangSewa*> cabangQueue;
    CabangSewa* cabangTreeRoot;

    void tambahKePohon(CabangSewa*& root, const CabangSewa& cabang) {
        if (!root) {
            root = new CabangSewa(cabang);
        } else {
            if (cabang.namaCabang < root->namaCabang) {
                tambahKePohon(root->left, cabang);
            } else {
                tambahKePohon(root->right, cabang);
            }
        }
    }

    void hapusDariPohon(CabangSewa*& root, const string& namaCabang) {
        if (!root) {
            return;
        }

        if (namaCabang < root->namaCabang) {
            hapusDariPohon(root->left, namaCabang);
        } else if (namaCabang > root->namaCabang) {
            hapusDariPohon(root->right, namaCabang);
        } else {

            if (!root->left) {
                CabangSewa* temp = root->right;
                delete root;
                root = temp;
            } else if (!root->right) {
                CabangSewa* temp = root->left;
                delete root;
                root = temp;
            } else {

                CabangSewa* temp = cariCabangMinimum(root->right);
                root->namaCabang = temp->namaCabang;
                root->lokasiCabang = temp->lokasiCabang;
                root->stokMobil[0] = temp->stokMobil[0];
                root->stokMobil[1] = temp->stokMobil[1];
                root->stokMobil[2] = temp->stokMobil[2];
                hapusDariPohon(root->right, temp->namaCabang);
            }
        }
    }

    CabangSewa* cariCabangMinimum(CabangSewa* root) {
        CabangSewa* current = root;
        while (current->left) {
            current = current->left;
        }
        return current;
    }

    void deleteTree(CabangSewa* root) {
        if (root) {
            deleteTree(root->left);
            deleteTree(root->right);
            deleteCabang(root);
        }
    }

    void preorderTraversal(CabangSewa* root) {
        if (root) {
            cout << root->namaCabang << " - ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

    void deleteCabang(CabangSewa* cabang) {
        if (!cabang) {
            return;
        }

        delete[] cabang->stokMobil;
        delete cabang;
    }
};

int main() {
    ManajemenSewa manajemenSewa;

    int pilihan;

    do {
        cout << "Menu:\n";
        cout << "1. Tampilkan Cabang\n";
        cout << "2. Tambah Cabang\n";
        cout << "3. Hapus Cabang\n";
        cout << "4. Batal Hapus Cabang\n";
        cout << "5. Cabang yang terhapus\n";
        cout << "6. Tampilkan Urutan Cabang\n";
        cout << "7. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                manajemenSewa.tampilCabang();
                break;
            case 2:
                manajemenSewa.tambahCabangManual();
                break;
            case 3:
                {
                    cin.ignore();
                    string namaCabang;
                    cout << "Masukkan nama cabang yang ingin dihapus: ";
                    getline(cin, namaCabang);
                    manajemenSewa.hapusCabang(namaCabang);
                }
                break;
            case 4:
                manajemenSewa.batalHapusCabang();
                break;
            case 5:
                manajemenSewa.tampilkanAntrianPrioritas();
                break;
            case 6:
                manajemenSewa.tampilkanPohon();
                break;
            case 7:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 7);

    return 0;
}
