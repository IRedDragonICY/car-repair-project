#include <iostream>
using namespace std;

// deklarasi class
class Header {
public:
  string header[1] = {"Silahkan Laporkan Kerusakan Anda"}; // array statis
  string name[1]; // array dinamis
};

// menampilkan array statis dan dinamis
void displayArray() {
  Header head;
  for (int i = 0; i < 1; i++) {
    cout << "Masukkan Nama Anda : ";
    cin >> head.name[i];
    cout << "Halo, " << head.name[i] << endl;
  }
  for (int i = 0; i < 1; i++) {
    cout << head.header[i] << endl;
  }
}

// inisialisasi Node2
struct Node2 {
  int data, priority;
  Node2* next;
  Node2* prev;
  string dataTelp;
  string dataIDCar;

  // Constructor yang digunakan untuk doubly linked list
  Node2(int d, int p) : data(d), priority(p), next(nullptr), prev(nullptr) {}

  // Constructor yang digunakan untuk single linked list
  Node2(string d) : dataTelp(d), next(nullptr) {}

  // Constructor yang digunakan untuk doubly linked list dengan dataIDCar
  Node2(string idCar, bool isCarId) : dataIDCar(idCar), next(nullptr), prev(nullptr) {}
};

// single linked list untuk memasukkan nomor telepon
Node2* head = nullptr;

void insertTelp(Node2*& head, string newdata) {
  Node2* newNode2 = new Node2(newdata);
  if (head == nullptr) {
    head = newNode2;
  } else {
    Node2* last = head;
    while (last->next != nullptr) {
      last = last->next;
    }
    last->next = newNode2;
  }
}

void displayTelp(Node2* head) {
  Node2* ptr = head;
  while (ptr != nullptr) {
    cout << ptr->dataTelp << " ";
    ptr = ptr->next;
  }
  cout << endl;
}

// doubly linked list untuk memasukkan id mobil
Node2* head2 = nullptr;

void insertCarID(Node2*& head2, string newdata) {
  Node2* newNode2 = new Node2(newdata, true);
  if (head2 == nullptr) {
    head2 = newNode2;
  } else {
    Node2* last = head2;
    while (last->next != nullptr) {
      last = last->next;
    }
    last->next = newNode2;
    newNode2->prev = last;
  }
}

void displayCarID(Node2* head2) {
  Node2* ptr = head2;
  while (ptr != nullptr) {
    cout << ptr->dataIDCar << " ";
    ptr = ptr->next;
  }
  cout << endl;
}

// Stack1 dengan array untuk memasukkan nama penyewa
const int maks = 10;

class Stack1 {
public:
  Stack1() : banyak(0) {}

  bool isFull() {
    return banyak == maks;
  }

  bool isEmpty() {
    return banyak == 0;
  }

  void pushUserName(string UserName) {
    if (isFull()) {
      cout << " Stack1 penuh";
    } else {
      userName[banyak] = UserName;
      banyak++;
    }
  }

  void cetak() {
    for (int i = 0; i < banyak; i++) {
      cout << userName[i] << " ";
    }
    cout << endl;
  }

private:
  string userName[maks];
  int banyak;
};

//Queue1 dengan Array Circular
class Queue1 {
public:
  Queue1() : depan(0), belakang(-1), banyak(0) {}

  bool penuh() {
    return banyak == maks;
  }

  bool kosong() {
    return banyak == 0;
  }

  void enQueue1(char name) {
    if (penuh()) {
      cout << "Queue1 penuh";
    } else {
      belakang = (belakang + 1) % maks;
      A[belakang] = name;
      banyak++;
    }
  }

  char deQueue1() {
    if (kosong()) {
      cout << "Queue1 kosong";
      return '\0';
    } else {
      char name = A[depan];
      depan = (depan + 1) % maks;
      banyak--;
      return name;
    }
  }

  void cetak() {
    for (int i = depan, j = 0; j < banyak; j++) {
      cout << A[(i + j) % maks] << " ";
    }
    cout << endl;
  }

private:
  char A[maks];
  int depan, belakang, banyak;
};

//Antrian Berprioritas Menggunakan Doubly Linked List
void push(Node2*& head, int data, int priority) {
  Node2* newNode2 = new Node2(data, priority);
  if (head == nullptr || head->priority > priority) {
    newNode2->next = head;
    if (head != nullptr) {
      head->prev = newNode2;
    }
    head = newNode2;
  } else {
    Node2* temp = head;
    while (temp->next != nullptr && temp->next->priority <= priority) {
      temp = temp->next;
    }
    newNode2->next = temp->next;
    if (temp->next != nullptr) {
      temp->next->prev = newNode2;
    }
    temp->next = newNode2;
    newNode2->prev = temp;
  }
}

int pop(Node2*& head) {
  if (head == nullptr) {
    return -1; // atau kode lain yang menunjukkan bahwa list kosong
  }
  Node2* temp = head;
  int data = temp->data;
  head = head->next;
  if (head != nullptr) {
    head->prev = nullptr;
  }
  delete temp;
  return data;
}

void display(Node2* head) {
  Node2* temp = head;
  while (temp != nullptr) {
    cout << temp->data << "--> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

void menuLaporanKerusakan() {
  // fungsi dan variabel yang dibutuhkan
  displayArray();
  string dataTelp;
  string dataIDCar;
  string UserName;
  Stack1 Stack1UserNames;
  Queue1 Queue1UserNames;

  // deklarasi single linked list
  cout << "Masukkan nomor telepon : ";
  cin >> dataTelp;
  insertTelp(head, dataTelp);

  // deklarasi double linked list
  cout << "Masukkan nomor mobil : ";
  cin >> dataIDCar;
  insertCarID(head2, dataIDCar);

  // menampilkan isi laporan
  cout << "Nomor telepon anda : ";
  displayTelp(head);
  cout << "Nomor mobil anda  : ";
  displayCarID(head2);

}
