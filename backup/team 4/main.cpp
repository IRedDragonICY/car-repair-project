#include "Deskripsi/ddaihatsu.h"
#include "Deskripsi/dhonda.h"
#include "Deskripsi/dsuzuki.h"
#include "Deskripsi/dtoyota.h"
#include "tree.h"
#include "avl.h"
#include <iostream> // utk fungsi dasar spt i/o cin, cout
#include <string> // brs definisi dan deklarasi dfungsi2, class yg dibutuhkan
#include <vector> // utk save and kelola elemen uk dinamis
//maksimal elemen yg bisa diinput
#define max 5 
using namespace std;

class Mobil{
public :
string merk, jenis, harga;
// bool isAvailable;

Mobil(string m, string j, string h) : merk(m), jenis(j), harga(h) {
  // this->merk = merk;
  // this->jenis = jenis;
  // this->harga = harga;
  // this->isAvailable = true;
  }
};
// class Customer {
// public:  
//     int id;
//     string nama;
//     int noTelp;
//     int mobilId;
//     int harga;
//     int diskon;
//     int priority

//     Customer(int id, string nama, int noTelp, int mobilId, int harga, int diskon, int priority) {     
//     this->id = id;
//     this->nama = nama;
//     this->noTelp = noTelp;
//     this->mobilId = mobilId;
//     this->harga = harga;
//     this->diskon = diskon;
//     this->priority = priority;
//   }
// };
//ll
class Node{
public :
  Mobil mobil;
  Node* next;
  Node* prev;

Node(Mobil mobil) : mobil(mobil), next(nullptr){}
};

class RentalList{
public:
  Node* head;
  void add(Mobil mobil);
  void daftarmobil(string merk);
  Node* find(string merk);
  void prosesPengembalian();
  RentalList() : head(nullptr){}
};

void RentalList::add(Mobil mobil){
  Node* new_node = new Node(mobil);
  new_node->next = head;
  head->prev = new_node;
  head = new_node;
}

Node* RentalList::find(string merk){
  Node* current = head;
  while(current != nullptr){
      if(current->mobil.merk == merk){
      return current;
    }
    current = current->next;
  }
  return nullptr;
}

void RentalList::daftarmobil(string merk){
  Node* current = head;
  while(current != nullptr){
    if(current->mobil.merk == merk){
      cout << "Merk : " << current->mobil.merk << endl;
      cout << "Jenis : " << current->mobil.jenis << endl;
      cout << "Harga : " << current->mobil.harga << endl;
      current = current->next;
    }
  }
}

void RentalList::prosesPengembalian(){
  string merk;
  cout << "Masukkan merk mobil yang ingin dikembalikan : ";
  cin >> merk;
  Node* node = find(merk);
  if(node != nullptr){
    cout << "Mobil " << node->mobil.merk << " berhasil dikembalikan" << endl;
    node->mobil.harga = "Rp.";
    node->mobil.jenis = " ";
    node->mobil.merk = " ";
    delete node;
  } else {
    cout << "Mobil tidak ditemukan" << endl;
  }
}

class sewa {
public:
  void regis();
  void login();
  void menu(sewa objSewa);
  void tipe();
  void push();
  void pop();
  void print();
  void tambahMobil(string merk, string jenis, string harga, sewa objSewa);
  void hapusMobil(string merk, string jenis, string harga, sewa objSewa);
  void enQueue();
  void deQueue();
  void tampil();

private:
  int x, pil, n, data, krj,dt;
  int item;
  string username, pass, nama, alamat, no, pilmerk, jenis, merk, merkbaru, harga;
  string tmp, queue;
  vector<Mobil> daftarmobil;
  int top=-1, Stack[max];
  int front=-1, rear=-1;
  bool isempty() 
  {
    if (top == -1)
      return true;
    else
      return false;
  }

  string toyota[5] = {"\tAvanza          |    Rp300.000     |",
                      "\tFortuner        |    Rp450.000     |",
                      "\tKijang Inova    |    Rp350.000     |",
                      "\tAlphard         |    Rp800.000     |",
                      "\tRush            |    Rp350.000     |"};

  string suzuki[5] = {"\tErtiga          |    Rp350.000     |",
                      "\tBaleno          |    Rp400.000     |",
                      "\tKarimun         |    Rp250.000     |",
                      "\tIgnis           |    Rp300.000     |"};
  string honda[5] = {"\tBrio             |    Rp200.000     |",
                     "\tHR-V             |    Rp550.000     |",
                     "\tMobilio          |    Rp325.000     |",
                     "\tCivic            |    Rp660.000     | ",
                     "\tJazz             |    Rp250.000     |"};
  string daihatsu[5] = {"\tXenia         |    Rp400.000     |",
                        "\tAyla          |    Rp340.000     |",
                        "\tSigra         |    Rp325.000     |",
                        "\tRocky         |    Rp360.000     |"};
};

void sewa::tambahMobil(string merk, string jenis, string harga, sewa objSewa){
    Mobil mobil(merk, jenis, harga);
  	objSewa.daftarmobil.push_back(mobil);
    cout<<endl;
    cout<<"Daftar mobil : "<<endl;
  for(int i=0; i<daftarmobil.size(); i++){
    cout<<"Merek : "<<"i + daftarmobil[i].merk"<<", Jenis : "<<"i + daftarmobil[i].jenis"<<", Harga : "<<"i + daftarmobil[i].harga"<<endl;
  }
}

void sewa::regis() {
  cout << "================================" << endl;
  cout << "|  \t\tRegistrasi Akun\t\t   |" << endl;
  cout << "================================" << endl;
  cout << "Nama   : ";
  cin >> nama;
  cout << endl;
  cout << "Username : ";
  cin >> username;
  cout << endl;
  cout << "No.Hp  : ";
  cin >> no;
  cout << endl;
  cout << "Alamat : ";
  cin >> alamat;

  cout << "\n------------------------------------" << endl;
  cout << "\nDaftar akun berhasil!" << endl;
  cout << "\n------------------------------------" << endl;
}

void sewa::login() {
a:
  cout << "==============================================" << endl;
  cout << "| Silakan login ke akun Anda terlebih dahulu |" << endl;
  cout << "==============================================" << endl;
  cout << "Username : ";
  cin >> username;
  cout << endl;
  cout << "Password : ";
  cin >> pass;
  cout << endl;

  if (username == "Fauza" && pass == "230") {
    cout << "\n------------------------------------------------" << endl;
    cout << "\t\t\nAnda berhasil login\n" << endl;
    cout << "-------------------------------------------------\n" << endl;
  } else if (username == "Adhel" && pass == "266") {
    cout << "\n------------------------------------------------" << endl;
    cout << "\t\t\nAnda berhasil login\n" << endl;
    cout << "-------------------------------------------------\n" << endl;
  } else if (username == "Jingga" && pass == "267") {
    cout << "\n------------------------------------------------" << endl;
    cout << "\t\tAnda berhasil login\n" << endl;
    cout << "-------------------------------------------------\n" << endl;
  } else {
    cout << "\n------------------------------------------------" << endl;
    cout << "\t\t\nUsername atau password yang Anda masukkan salah!" << endl;
    cout << "-------------------------------------------------\n" << endl;
    goto a;
  }
}

void sewa::tipe() {
  cout << endl;
  cout << "==============================================" << endl;
  cout << "||          D A F T A R   M E R E K         ||" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "||                 T O Y O T A              ||" << endl;
  cout << "--------------------------------- ------------" << endl;
  cout << "| KODE |    JENIS MOBIL   |  HARGA SEWA/HARI |" << endl;
  for (int i = 0; i <= 4; i++) {
    cout << "| " << i + 1200 << " |" << toyota[i] << endl;
  }

  cout << "----------------------------------------------" << endl;
  cout << "||                 S U Z U K I              ||" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "| KODE |    JENIS MOBIL   |  HARGA SEWA/HARI |" << endl;
  for (int i = 0; i <= 3; i++) {
    cout << "| " << i + 1511 << " |" << suzuki[i] << endl;
  }

  cout << "----------------------------------------------" << endl;
  cout << "||                  H O N D A               ||" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "| KODE |    JENIS MOBIL   |  HARGA SEWA/HARI |" << endl;
  for (int i = 0; i <= 4; i++) {
    cout << "| " << i + 1301 << " |" << honda[i] << endl;
  }

  cout << "----------------------------------------------" << endl;
  cout << "||              D A I H A T S U             ||" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "| KODE |    JENIS MOBIL   |  HARGA SEWA/HARI |" << endl;
  for (int i = 0; i <= 3; i++) {
    cout << "| " << i + 1240 << " |" << daihatsu[i] << endl;
  }
}

void sewa::menu(sewa objSewa) {
  BinaryTree BinTree;
  avlTree avl;
a:
  cout << endl;
  cout << "=====================================" << endl;
  cout << "|            M  E  N  U             |" << endl;
  cout << "-------------------------------------" << endl;
  cout << "| 1. Tipe Mobil                     |" << endl;
  cout << "| 2. Deskripsi Mobil                |" << endl;
  cout << "| 3. Tambah Mobil                   |" << endl;
  cout << "| 4. Pengembalian Mobil             |" << endl;
  cout << "| 5. Push                           |" << endl;
  cout << "| 6. Pop                            |" << endl;
  cout << "| 7. enQueue                        |" << endl;
  cout << "| 8. deQueue                        |" << endl;
  cout << "| 9. Display                        |" << endl;
  cout << "| 10. Tree                          |" << endl;
  cout << "| 11. Avl Tree                      |" << endl;
  cout << "| 0. Exit                           |" << endl;
  cout << "=====================================" << endl;

  cout << "Masukkan pilihan : ";
  cin >> pil;

  if (pil == 1) {
    tipe();
    goto a;
  }

  else if (pil == 2) {
    cout << "Pilih Merek : ";
    cin >> pilmerk;
    if (pilmerk == "toyota") {
      cout << "--------------------------------------------" << endl;
      cout << "||                T O Y O T A             ||" << endl;
      cout << "--------------------------------- ----------" << endl;
      cout << "| NO |    JENIS MOBIL   |  HARGA SEWA/HARI |" << endl;
      for (int i = 0; i <= 4; i++) {
        cout << "| " << i + 1 << " |" << toyota[i] << endl;
      }
      cout << "============================================" << endl;
      empat();
      goto a;
    }

    else if (pilmerk == "suzuki") {
      cout << "--------------------------------------------" << endl;
      cout << "||                S U Z U K I             ||" << endl;
      cout << "--------------------------------------------" << endl;
      cout << "| NO |    JENIS MOBIL   |  HARGA SEWA/HARI |" << endl;
      for (int i = 0; i <= 3; i++) {
        cout << "| " << i + 1 << " |" << suzuki[i] << endl;
      }
      cout << "=============================================" << endl;
      tiga();
      goto a;
    }

    else if (pilmerk == "honda") {
      cout << "-------------------------------------------" << endl;
      cout << "||                H O N D A              ||" << endl;
      cout << "-------------------------------------------" << endl;
      cout << "| NO  |    JENIS MOBIL  | HARGA SEWA/HARI |" << endl;
      for (int i = 0; i <= 4; i++) {
        cout << " | " << i + 1 << "  |" << honda[i] << endl;
      }
      cout << "============================================" << endl;
      satu();
      goto a;
    }

    else if (pilmerk == "daihatsu") {
      cout << "--------------------------------------------" << endl;
      cout << "||              D A I H A T S U           ||" << endl;
      cout << "--------------------------------------------" << endl;
      cout << "| NO |    JENIS MOBIL   |  HARGA SEWA/HARI |" << endl;
      for (int i = 0; i <= 3; i++) {
        cout << "| " << i + 1 << " |" << daihatsu[i] << endl;
      }
      cout << "============================================" << endl;
      dua();
      goto a;
    }
  }
  	
  	else if(pil == 3){
      cout<<"Tambah Mobil Baru"<<endl;
      cout<<"Merk : ";
      cin>>merkbaru;
      cout<<"Jenis Mobil : ";
      cin>>jenis;
      cout<<"Harga : ";
      cin>>harga;
  		tambahMobil(merkbaru, jenis, harga, objSewa);
      for(const Mobil& mobil : daftarmobil){
         cout<<"Merek : "<<"i + mobil.merk"<<", Jenis : "<<"i + mobil.jenis"<<", Harga : "<<"i + mobil.harga"<<endl;
      }
      tipe();
  		goto a;
	  }

      else if(pil == 4){
        cout<<"Pengembalian Mobil"<<endl;
        cout<<"Merek : ";
        cin>>merkbaru;
        cout<<"Jenis Mobil : ";
        cin>>jenis;
        cout<<"Harga : ";
        cin>>harga;
        goto a;
      }

      else if (pil == 5){
        push();
        goto a;
      }
      else if (pil == 6){
        pop();
        goto a;
      }
      else if (pil == 7){
        enQueue();
      }
      else if (pil == 8){
        deQueue();
      }
      else if (pil == 9){
        tampil();
      }      
      else if (pil==10){
        u:
        cout << "==========================================" << endl;
        cout << "||      BINARY TREE / POHON BINER       ||" << endl;
        cout << "==========================================" << endl;
        cout << "|| 1. Insert Data                       ||" << endl;
        cout << "|| 2. InOrder                           ||" << endl;
        cout << "|| 3. PostOrder                         ||" << endl;
        cout << "|| 4. PreOrder                          ||" << endl;
        cout << "|| 5. Exit                              ||" << endl;
        cout << "==========================================" << endl;
        cout << "Masukan Pilihan anda : ";
        cin >> krj;
        if (krj == 1) {
          cout << "Masukkan Banyaknya Data : ";
          cin >> dt;
          for (int i = 0; i < dt; i++) {
            cout << "Data ke " << i + 1 << ": ";
            cin >> tmp;
            BinTree.insert_data(tmp);
          }
          goto u;
          cout << endl;
        } 
        else if (krj == 2) {
          cout << endl;
          cout << "InOrder : ";
          BinTree.cetak_inorder();
          cout << endl;
          goto u;
          cout << endl;
        } 
        else if (krj == 3) {
          cout << endl;
          cout << "PostOrder : ";
          BinTree.cetak_postorder();
          cout << endl;
          goto u;
        } 
        else if (krj == 4) {
          cout << endl;
          cout << "PreOrder : ";
          BinTree.cetak_preorder();
          cout << endl;
          goto u;
        } 
        else if (krj == 5) {
          goto u;
        }

        else {
          cout << "Pilihan tidak tersedia!" << endl;
          goto a;
        }
        }
        else if(pil==11){
          m:
          cout<<endl;
          cout << "==========================================" << endl;
          cout << "|| ----IMPLEMENTASI POHON SETIMBANG---- ||" << endl;
          cout << "==========================================" << endl;
          cout << "|| 1. Masukkan elemen ke dalam pohon	  ||" << endl;
          cout << "|| 2. Tampilkan Pohon Setimbang         ||" << endl;
          cout << "|| 3. InOrder traversal                 ||" << endl;
          cout << "|| 4. PreOrder traversal                ||" << endl;
          cout << "|| 5. PostOrder traversal               ||" << endl;
          cout << "|| 6. Keluar                            ||" << endl;
          cout << "==========================================" << endl;
          cout << "\nMasukkan pilihan: ";
          cin >> krj;
          if (krj == 1) {
            cout << "Masukkan elemen : ";
            cin >> item;
            root = avl.insert(root, item);
            goto m;
            cout<<endl;
          } 
          else if (krj == 2) {
            if (root == NULL) {
              cout << "Pohon kosong!!" << endl;
              // continue;
            }
            cout << "Pohon Setimbang: ";
            avl.display(root,1);
            goto m;
              cout<<endl;
          } 
          else if (krj == 3) 
          {
            cout << "Inorder Traversal: ";
            avl.inorder(root);
            goto m;
            cout << endl;
          } 
          else if (krj == 4) 
          {
            cout << "Preorder Traversal: ";
            avl.preorder(root);
            goto m;
            cout << endl;
          } 
          else if (krj == 5) 
          {
            cout << "Postorder Traversal: ";
            avl.postorder(root);
            goto m;
            cout << endl;
          } 
          else if (krj == 6) {
            goto a;
          }
          else {
          cout << "Pilihan tidak tersedia" << endl;
          goto m;
        }
        }
         else if (pil == 0){
          exit(0);
        }
  }

// int top=-1, Stack[MAX];
void sewa::push(){
    if(top == max-1){
        cout << ">> Stack sudah Penuh !" << endl;
    }else{
        top++;
        cout << ">> Masukan Data : ";
        cin >> Stack[top];
        cout << "Pada Index ke " << top << " "<<endl;
        cout << "Data [" << Stack[top] << "] Telah Ditambah ! " << endl;
    }
}
void sewa::pop(){
    if(top == -1){
        cout << ">> Stack Kosong !" << endl;
    }else{
        cout << "Data [" << Stack[top] << "] pada index ke " << top << " dalam Stack Diambil !" << endl;
        Stack[top--];
    }
}

void sewa::print(){
    if (top == -1) {
      cout << "          Stack : ";
      cout << "\n===========================" << endl;
      cout << "          Empty ! \n===========================" << endl;
    }
    else {
      cout << "          Stack : ";
      cout << "\n===========================" << endl;
      for (int i = top; i >= 0; i--){
        cout << "     XXXXX[ " << Stack[i] << " ]XXXXX" << endl;
      }
      cout << "===========================" << endl;
    }
}

void sewa::enQueue(){
  if(front == -1){
    front = 0;
    rear = 0;
    cout<<"masukkan data mobil : ";
    cin>>data;
    cout<<"data mobil : "<<data<<endl;
    cout<<"data mobil masuk ke dalam queue"<<endl;
  }
  else if(rear == max-1){
    cout<<"queue penuh"<<endl;
    cout<<"data mobil : "<<data<<endl;
    cout<<"data mobil masuk ke dalam queue"<<endl;
    rear = 0;
    queue[rear] = data;
    cout<<"data mobil : "<<data<<endl;
    cout<<"data mobil masuk ke dalam queue"<<endl;
    rear++;
    cout<<"data mobil : "<<data<<endl;
    cout<<"data mobil masuk ke dalam queue"<<endl;
    cout<<"data mobil : "<<data<<endl;
  }
  else{
    queue[++rear] = data;
    cout<<"data mobil : "<<data<<endl;
    cout<<"data mobil masuk ke dalam queue"<<endl;
  }
}

void sewa::deQueue(){
  if(front == -1){
    cout<<"queue kosong"<<endl;
  }
  else if(front == rear){
    cout<<"data mobil : "<<data<<endl;
    cout<<"data mobil masuk ke dalam queue"<<endl;
    front = -1;
    rear = -1;
    cout<<"data mobil : "<<data<<endl;
  }
  else{
    cout<<"data mobil : "<<data<<endl;
    cout<<"data mobil masuk ke dalam queue"<<endl;
    front++;
  } 
}

void sewa::tampil(){
  if(front == -1){
    cout<<"queue kosong"<<endl;
  }
  else{
    cout<<"data mobil : "<<data<<endl;
    cout<<"data mobil masuk ke dalam queue"<<endl;
}
}
// void tampilpesanan(priority_queue<Customer, vector<Customer>, greater<Customer>> antrian) {
//     while (!antrian.empty()) {
//         Customer c = antrian.top();
//         cout << "Nama: " << c.nama << " No. Telp: " << c.noTelp << " Mobil: " << c.mobilId << " Harga: " << c.harga << " Diskon: " << c.diskon << " Prioritas: " << c.priority << endl;
//         antrian.pop();
//     }
// }
  
int main() {
  RentalList objSewa;
  sewa x;
  x.regis();
  x.login();
  x.menu(x);
  x.tipe();
  x.push();
  x.pop();
  x.enQueue();
  x.deQueue();
  x.tampil();
  x.print();
  x.tambahMobil("toyota", "honda", "Rp300.000" ,x);
  x.tambahMobil("suzuki", "daihatsu", "Rp250000" ,x);
  // vector<Mobil> mobilList = {
  //     Mobil(1,"Toyota", "Avanza", "Rp300.000"),
  //     Mobil(2, "Suzuki", "Ertiga", "Rp350.000"),
  //     Mobil(3, "Honda", "Brio", "Rp200.000")
  // };
  // priority_queue<Customer, vector<Customer>, greater<Customer>> antrian;
  // antrian.push(Customer(1, "John", 1234567890, 2, 1000000, 50000, 1));
  // antrian.push(Customer(2, "Mike", 9876543210, 1, 1200000, 30000, 2));
  // antrian.push(Customer(3, "Lisa", 8765432109, 3, 1100000, 40000, 3));

  // cout << "Antrian Setelah Diurutkan Berdasarkan Prioritas dan Diskon:" << endl;
  // tampilPemesanan(antrian);
}
  // 
  // }














//inorder penelusuran terlebih dahulu ke sub-pohon kiri > mencetak akar > dan terakhir melakukan penelusuran ke sub-pohon kanan.
//preorder mencetak simpul akar > kemudian mencetak sub-pohonk kiri, dan terakhir melakukan penelusuran ke sub-pohon kanan.
//postorder terlebih dahulu ke sub-pohon kiri, kemudian melakukan penelusuran ke sub-pohon kanan, dan terakhir mencetak akar.