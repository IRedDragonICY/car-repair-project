#include <iostream>
using namespace std;

struct QueueNode {
  string customerName;
  int rentalDuration;
  int totalPrice;
  QueueNode *next;
};

class Queue {
private:
  QueueNode *front;
  QueueNode *rear;

public:
  Queue();
  void enqueue(string name, int duration, int price);
  void dequeue();
  void displayQueue();
  ~Queue();
};

Queue::Queue() : front(NULL), rear(NULL) {}

void Queue::enqueue(string name, int duration, int price) {
  QueueNode *newNode = new QueueNode;
  newNode->customerName = name;
  newNode->rentalDuration = duration;
  newNode->totalPrice = price;
  newNode->next = NULL;

  if (rear == NULL) {
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }

  cout << "Driver berhasil disewa.\n";
}

void Queue::dequeue() {
  if (front == NULL) {
    cout << "Antrian kosong.\n";
    return;
  }

  QueueNode *temp = front;
  front = front->next;

  if (front == NULL) {
    rear = NULL;
  }

  delete temp;
}

void Queue::displayQueue() {
  QueueNode *current = front;
  cout << "=========================================\n";
  cout << "|          Antrian Pemesanan            |\n";
  cout << "=========================================\n";
  while (current != NULL) {
    cout << "Nama Customer : " << current->customerName << endl;
    cout << "Durasi Sewa   : " << current->rentalDuration << " jam\n";
    cout << "Total Harga   : Rp. " << current->totalPrice << endl << endl;
    current = current->next;
  }
}

Queue::~Queue() {
  while (front != NULL) {
    QueueNode *temp = front;
    front = front->next;
    delete temp;
  }
}

struct Employee {
  string nama;
  int usia, pengalaman;
};

class Driver {
private:
  int pilih, n, sewa, maxDrivers, numDrivers;
  string tambah;
  Employee *listDrivers;
  string username, pass;

public:
  void sewaDriver();
  Queue rentalQueue;
  string role;
  Driver() {
    maxDrivers = 5;
    numDrivers = 3;
    listDrivers = new Employee[numDrivers];
    listDrivers[0].nama = "Yahdi Septian";
    listDrivers[0].usia = 38;
    listDrivers[0].pengalaman = 10;
    listDrivers[1].nama = "Asep Murja";
    listDrivers[1].usia = 34;
    listDrivers[1].pengalaman = 5;
    listDrivers[2].nama = "Rian Turen";
    listDrivers[2].usia = 29;
    listDrivers[2].pengalaman = 2;
  }
  void supir();
  void tampil();
  void tambahData();
  void hapus();
  void login();
  ~Driver() { delete[] listDrivers; }
};

void Driver::sewaDriver() {
  string customerName;
  int rentalDuration, totalPrice;

  cout << "=========================================\n";
  cout << "|            Sewa Driver                |\n";
  cout << "=========================================\n";
  cout << "Nama Customer : ";
  cin >> customerName;
  cout << "Durasi Sewa (jam) : ";
  cin >> rentalDuration;

  // Hitung total harga (misalnya, Rp. 30.000 per jam)
  totalPrice = rentalDuration * 30000;

  rentalQueue.enqueue(customerName, rentalDuration, totalPrice);
}

void Driver::supir() {
  cout << "=========================================" << endl;
  cout << "|              Data Driver              |" << endl;
  cout << "=========================================" << endl;
  for (int i = 0; i < numDrivers; i++) {
    cout << "--------------- Driver " << i + 1 << " ----------------" << endl;
    cout << "Nama Driver : " << listDrivers[i].nama << endl;
    cout << "Usia Driver : " << listDrivers[i].usia << " tahun" << endl;
    cout << "Pengalaman  : " << listDrivers[i].pengalaman << "th" << endl;
  }
}

void Driver::tambahData() {
  if (numDrivers < maxDrivers) {
    Employee *newDriver = new Employee[numDrivers + 1];
    for (int i = 0; i < numDrivers; i++) {
      newDriver[i].nama = listDrivers[i].nama;
      newDriver[i].usia = listDrivers[i].usia;
      newDriver[i].pengalaman = listDrivers[i].pengalaman;
    }

    cout << "+------------------------------------+" << endl;
    cout << "| MENU : [1] TAMBAH DATA DRIVER BARU |" << endl;
    cout << "|------------------------------------|" << endl;
    cout << "  Nama       : ";
    cin >> newDriver[numDrivers].nama;
    cout << "  Usia       : ";
    cin >> newDriver[numDrivers].usia;
    cout << "  Pengalaman : ";
    cin >> newDriver[numDrivers].pengalaman;

    delete[] listDrivers;
    listDrivers = newDriver;
    numDrivers++;

    cout << "\nDriver baru berhasil ditambahkan.\n";
  } else {
    cout << "Driver penuh\n";
  }
}

void Driver::hapus() {
  if (numDrivers > 0) {
    for (int i = 0; i < numDrivers - 1; i++) {
      listDrivers[i].nama = listDrivers[i + 1].nama;
      listDrivers[i].usia = listDrivers[i + 1].usia;
      listDrivers[i].pengalaman = listDrivers[i + 1].pengalaman;
    }
    numDrivers--;

    Employee *newList = new Employee[numDrivers];

    for (int i = 0; i < numDrivers; i++) {
      newList[i] = listDrivers[i];
    }

    delete[] listDrivers;
    listDrivers = newList;

    cout << "Driver berhasil dihapus.\n";
  } else {
    cout << "Tidak ada driver untuk dihapus.\n";
  }
}

void Driver::tampil() {
  int total;
  cout << "=========================================" << endl;
  cout << "Pilih driver [1/2/3] : ";
  cin >> pilih;

  switch (pilih) {
  case 1:
    cout << "[Driver : Yahdi Septian]" << endl;
    cout << "[1] Sewa /jam  : Rp. 30.000" << endl;
    cout << "[2] Sewa /hari : Rp. 150.000" << endl;
    cout << "[3] Sewa untuk keluar kota : Rp. 300.000" << endl;
    cout << "Pilih [1/2/3]  : ";
    cin >> n;
    if (n == 1) {
      cout << "[Sewa /Jam]" << endl;
      cout << "Mau berapa jam? : ";
      cin >> sewa;
      total = sewa * 30000;
      cout << "Harga sewa driver " << sewa << " jam = " << total;
    } else if (n == 2) {
      cout << "[Sewa /Hari]" << endl;
      cout << "Mau berapa hari? : ";
      cin >> sewa;
      total = sewa * 150000;
      cout << "Harga sewa driver " << sewa << " hari = " << total;
    } else {
      cout << "[Sewa Keluar Kota]" << endl;
      cout << "Mau berapa hari? : ";
      cin >> sewa;
      total = sewa * 300000;
      cout << "Harga sewa driver " << sewa << " hari = " << total;
    }
    break;
  case 2:
    cout << "[Driver : Asep Murja]" << endl;
    cout << "[1] Sewa /jam  : Rp. 20.000" << endl;
    cout << "[2] Sewa /hari : Rp. 100.000" << endl;
    cout << "[3] Sewa untuk keluar kota : Rp. 250.000" << endl;
    cout << "Pilih [1/2/3]  : ";
    cin >> n;
    if (n == 1) {
      cout << "[Sewa /Jam]" << endl;
      cout << "Mau berapa jam? : ";
      cin >> sewa;
      total = sewa * 20000;
      cout << "Harga sewa driver " << sewa << " jam = " << total;
    } else if (n == 2) {
      cout << "[Sewa /Hari]" << endl;
      cout << "Mau berapa hari? : ";
      cin >> sewa;
      total = sewa * 100000;
      cout << "Harga sewa driver " << sewa << " hari = " << total;
    } else {
      cout << "[Sewa Keluar Kota]" << endl;
      cout << "Mau berapa hari? : ";
      cin >> sewa;
      total = sewa * 200000;
      cout << "Harga sewa driver " << sewa << " hari = " << total;
    }
    break;
  case 3:
    cout << "[Driver : Rian Turen]" << endl;
    cout << "[1] Sewa /jam  : Rp. 15.000" << endl;
    cout << "[2] Sewa /hari : Rp. 80.000" << endl;
    cout << "[3] Sewa untuk keluar kota : Rp. 150.000" << endl;
    cout << "Pilih [1/2/3]  : ";
    cin >> n;
    if (n == 1) {
      cout << "[Sewa /Jam]" << endl;
      cout << "Mau berapa jam? : ";
      cin >> sewa;
      total = sewa * 15000;
      cout << "Harga sewa driver " << sewa << " jam = " << total;
    } else if (n == 2) {
      cout << "[Sewa /Hari]" << endl;
      cout << "Mau berapa hari? : ";
      cin >> sewa;
      total = sewa * 80000;
      cout << "Harga sewa driver " << sewa << " hari = " << total;
    } else {
      cout << "[Sewa Keluar Kota]" << endl;
      cout << "Mau berapa hari? : ";
      cin >> sewa;
      total = sewa * 150000;
      cout << "Harga sewa driver " << sewa << " hari = " << total;
    }
    break;
  default:
    cout << "tak terdeteksi ...";
  }
}

void Driver::login() {
  cout << "Login\n";
  cout << "Username : ";
  cin >> username;
  cout << "Password : ";
  cin >> pass;
  if (username == "pegawai" && pass == "sewa1234") {
    role = "pegawai";
  }
  cout << "Login berhasil\n";
}

int main() {
  Driver x;
  Queue y;
  char tambah;
  int pil, n;
  cout << "+------------------------+" << endl;
  cout << "| [1] LOGIN AS A PEGAWAI |" << endl;
  cout << "| [2] LOGIN AS A CUSTOMER|" << endl;
  cout << "+------------------------+" << endl;
  cout << "Masukan pilihan anda [1/2] : ";
  cin >> n;
  if (n == 1) {
    x.login();
    do {
      if (x.role == "pegawai") {
        cout << "+-------------------------------+" << endl;
        cout << "|         MENU : PEGAWAI        |" << endl;
        cout << "|-------------------------------|" << endl;
        cout << "| [1] Tambah Daftar Driver      |" << endl;
        cout << "| [2] Tampil Data Driver        |" << endl;
        cout << "| [3] Hapus Driver dr Depan     |" << endl;
        cout << "| [4] Sewa Driver               |" << endl;
        cout << "| [5] Tampilkan Antrian Pesan   |" << endl;
        cout << "| [0] Exit                      |" << endl;
        cout << "+-------------------------------+" << endl;
        cout << "Masukan pilihan anda [1/2/3/4/5] : ";
        cin >> pil;
        switch (pil) {
        case 1:
          x.tambahData();
          break;
        case 2:
          x.supir();
          break;
        case 3:
          x.hapus();
          break;
        case 4:
          x.sewaDriver();
        case 5:
          x.rentalQueue;
          y.displayQueue();
        default:
          break;
        }
      } else {
        cout << "Apakah anda mau tambah driver ? [y/n]";
        cin >> tambah;

        if (tambah == 'y') {
          x.supir();
          x.tampil();
        } else {
          cout << "oke lanjut ...";
        }
      }
    } while (pil != 0);
  } else if (n == 2) {
    x.supir();
    x.tampil();
  }
}