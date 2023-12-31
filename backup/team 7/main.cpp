#include <iostream>
using namespace std;

// deklarasi class
class Header {
public:
  string header[1] = {"Silahkan Laporkan Kerusakan Anda"}; // array statis
  string name[1];// array dinamis
};

// menampilkan array statis dan dinamis
void displayArray() {
  Header head;
  for (int i = 0; i < 1; i++) {
    cout << "Masukkan Nama Anda : ";
    cin >> head.name[i];
    cout << endl;
    cout << "Halo, " << head.name[i] << endl;
  }
  for (int i = 0; i < 1; i++) {
    cout << head.header[i] << endl;
  }
}

//inisialisasi node
struct Node {
  int data, priority;
  Node(int d, int p) {
      data = d;
      priority = p;
      next = prev = NULL;
    }
    string dataTelp;
    struct Node* next;
    string dataIDCar;
    struct Node* prev;
};

// single linked list untuk memasukkan nomor telepon
Node* head = nullptr;

void insertTelp(Node*& head, string newdata) {
    struct Node* newnode = new Node();
    newnode->dataTelp = newdata;
    newnode->next = nullptr;
    if (head == nullptr) {
        head = newnode;
    } else {
        struct Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newnode;
    }
}

void displayTelp(Node* head) {
    struct Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->dataTelp << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// doubly linked list untuk memasukkan id mobil
struct Node* head2 = NULL;

void insertCarID(string newdata) {
    struct Node* newnode = new Node();
    newnode->dataIDCar = newdata;
    newnode->next = NULL;
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        struct Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newnode;
        newnode->prev = last;
    }
}

void displayCarID() {
    struct Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->dataIDCar << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// stack dengan array untuk memasukkan nama penyewa
const int maks=10;

class Stack {
  public:
      Stack();
      bool isFull();
      bool isEmpty();
      void cetak();
      void pushUserName(string);
  private:
    string userName[maks];
    int banyak;
};

bool Stack::isFull() {
    return banyak == maks;
}

bool Stack::isEmpty() {
    return banyak == 0;
}

void Stack::pushUserName(string UserName) {
    int x;
    cout << "Masukkan nama anda : " <<x;
    if (isFull())
        cout << " Stack penuh";
    else {
        userName[banyak] = x;
        banyak++;
    }
}

void Stack::cetak() {
    cout << "Masukkan nama anda : ";
    for (int i = 0; i < 1; i++)
        cout << userName[i] << " ";
}

//Queue dengan Array Circular
class Queue {
public:
    Queue();
    int penuh(int);
    int kosong(int);
    void cetak();
    void enqueue(char);
    char dequeue();

private:
    char A[maks];
    int banyak;
};

void Queue::cetak() {
    cout << "\nIsi Queue : ";
    for (int i = 0; i < banyak; i++) {
        cout << A[i] << " ";
    }
}

void Queue::enqueue(char name) {
    cout << "\nElemen : " << name << " masuk antrian";
    if (penuh(banyak)) {
        cout << "queue penuh";
        cout << endl;
    } else if (A[0] == '0') {
        A[0] = name;
        banyak++;
    } else {
        for (int i = banyak; i > 0; i--) {
            A[i] = A[i - 1];
        }
        A[0] = name;
        banyak++;
    }
}

char Queue::dequeue() {
    char temp = A[--banyak];
    cout << "\nDequeue elemen --> " << temp;
    A[banyak] = '0';
    return temp;
}

//Antrian Berprioritas Menggunakan Doubly Linked List
void push (Node*& head, int data, int priority) {
  if(head == NULL){
    Node* newnode = new Node(data, priority);
    head = newnode;
    return;
  }
  Node* node = new Node(data, priority);

  Node* temp = head;
  Node* parent = NULL;
  while (temp != NULL && temp->priority < priority) {
    parent = temp;
    temp = temp->next;
  }
  if (parent == NULL) {
    node->next = head;
    head->prev = node;
    head = node;
  }
  else if (temp == NULL) {
    parent->next = node;
    node->prev = parent;
  }
  else {
    parent->next = node;
    node->prev = parent;
    node->next = temp;
    temp->prev = node;
  }
}

int pop (Node*& head) {
  if(head != NULL) {
    int curr = head -> data;
    head = head -> next;
    if (head != NULL) {
      head -> prev = NULL;
    }
  }
}

void display(Node* head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp -> data << "--> ";
    temp = temp -> next;
  }
  cout<<"NULL"<<endl;
}

int main() {
  //fungsi dan variabel yang dibutuhkan
  displayArray();
  string dataTelp;
  string dataIDCar;
  string UserName;
  
  //deklarasi single linked list
  for (int i = 0; i < 1; ++i) {
    cout << "Masukkan nomor telepon : ";
    cin >> dataTelp;
    insertTelp(head, dataTelp);
  }
  //deklarasi double linked list
  for (int i = 0; i < 1; ++i) {
      cout << "Masukkan nomor mobil : ";
      cin >> dataIDCar;
      insertCarID(dataIDCar);
  }
  
  //menampilkan isi laporan
  cout << "Nomor telepon anda : ";
  displayTelp(head);
  cout << "Nomor mobil anda  : ";
  displayCarID();

  return 0;
}
