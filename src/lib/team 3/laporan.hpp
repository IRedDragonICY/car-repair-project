#include "array.hpp"
#include "linklist.hpp"
#include "statis.hpp"
#include "doublyLinkList.hpp"
void menuLaporan(){
    int pilih;
    cout << "Menu" << endl;
    cout << "1. statis" << endl;
    cout << "2. Laporan (Array)" << endl;
    cout << "3. Laporan (Linked List)" << endl;
    cout << "4. Laporan (doubly linked list)" << endl;
    cout << "Pilih menu: ";
    cin >> pilih;
    switch (pilih) {
    case 1:
        menuLaporanStatis();
        break;
    case 2:
        menuLaporanArray();
        break;
    case 3:
        menuLaporanLinkedlist();
        break;
    case 4:
        menuLaporanDoublyLinkedList();
        break;
    default:
        cout << "Pilihan tidak valid." << endl;
        break;
    }
}