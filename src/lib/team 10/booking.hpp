#include <iostream>
#include <vector>

using namespace std;

struct booking {
  string nama;
  string nohp;
  string jenis;
  int waktu;
  int pil;
  int priority;
};

class Node3Doubly {
public:
  booking data;
  Node3Doubly *next;
  Node3Doubly *prev;

  Node3Doubly(const booking &data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}

  void insert(const booking &data) {
    Node3Doubly *newNode3 = new Node3Doubly(data);
    if (!head) {
      head = tail = newNode3;
    } else {
      Node3Doubly *current = head;
      while (current && current->data.priority >= data.priority) {
        current = current->next;
      }

      if (!current) {
        tail->next = newNode3;
        newNode3->prev = tail;
        tail = newNode3;
      } else {
        newNode3->next = current;
        newNode3->prev = current->prev;
        if (current->prev) {
          current->prev->next = newNode3;
        } else {
          head = newNode3;
        }
        current->prev = newNode3;
      }
    }
  }

  void display() {
    Node3Doubly *current = head;
    int count = 1;
    while (current) {
      cout << "Data ke-" << count << endl;
      cout << "Nama: " << current->data.nama << endl;
      cout << "NO hp: " << current->data.nohp << endl;
      cout << "Jenis Mobil: " << current->data.jenis << endl;
      cout << "Lama Penyewaan (hari): " << current->data.waktu << endl;
      cout << "Priority: " << current->data.priority << endl;
      cout << endl;

      current = current->next;
      count++;
    }
  }

  ~DoublyLinkedList() {
    Node3Doubly *current = head;
    while (current) {
      Node3Doubly *temp = current;
      current = current->next;
      delete temp;
    }
  }

private:
  Node3Doubly *head;
  Node3Doubly *tail;
};

class Stack2 {
private:
  vector<booking> arr;

public:
  void push(const booking &data) { arr.push_back(data); }

  void pop() {
    if (!arr.empty()) {
      arr.pop_back();
    } else {
      cout << "Stack2 is empty." << endl;
    }
  }

  void display() {
    cout << "Stack2 Contents:" << endl;
    for (int i = 0; i < arr.size(); i++) {
      cout << "Data ke-" << i + 1 << endl;
      cout << "Nama Penyewa   : " << arr[i].nama << endl;
      cout << "No Handphone   : " << arr[i].nohp << endl;
      cout << "Jenis Mobil    : " << arr[i].jenis << endl;
      cout << "Lama sewa(hari):" << arr[i].waktu << endl;
      cout << endl;
    }
  }
};

class Node3 {
public:
  booking data;
  Node3 *next;

  Node3(const booking &data) : data(data), next(nullptr) {}
};

class CircularLinkedList {
public:
  CircularLinkedList() : head(nullptr) {}

  void push(const booking &data) {
    Node3 *newNode3 = new Node3(data);
    if (!head) {
      head = newNode3;
      head->next = head;
    } else {
      newNode3->next = head;
      Node3 *current = head;
      while (current->next != head) {
        current = current->next;
      }
      current->next = newNode3;
      head = newNode3;
    }
  }

  void pushBack(const booking &data) {
    Node3 *newNode3 = new Node3(data);
    if (!head) {
      head = newNode3;
      head->next = head;
    } else {
      Node3 *current = head;
      while (current->next != head) {
        current = current->next;
      }
      current->next = newNode3;
      newNode3->next = head;
    }
  }

  void enqueue(const booking &data) { pushBack(data); }

  void dequeue() {
    if (head) {
      Node3 *temp = head;
      if (head->next != head) {
        head = head->next;
        Node3 *current = head;
        while (current->next != temp) {
          current = current->next;
        }
        current->next = head;
      } else {
        head = nullptr;
      }
      delete temp;
    } else {
      cout << "Queue is empty." << endl;
    }
  }

  void display() {
    Node3 *current = head;
    int count = 1;
    if (head) {
      do {
        cout << "Data ke-" << count << endl;
        cout << "Nama: " << current->data.nama << endl;
        cout << "NO hp: " << current->data.nohp << endl;
        cout << "Jenis Mobil: " << current->data.jenis << endl;
        cout << "Lama Penyewaan (hari): " << current->data.waktu << endl;
        cout << endl;

        current = current->next;
        count++;
      } while (current != head);
    } else {
      cout << "The list is empty." << endl;
    }
  }

  ~CircularLinkedList() {
    if (head) {
      Node3 *current = head;
      do {
        Node3 *temp = current;
        current = current->next;
        delete temp;
      } while (current != head);
    }
  }

private:
  Node3 *head;
};

class sewa1 {
public:
  void input();
  void output();
  void display();
  void displayStack2();
  void pushToStack2(const booking &data);
  void popFromStack2();
  void enqueueToQueue(const booking &data);
  void dequeueFromQueue();

private:
  CircularLinkedList bookings;
  Stack2 Stack2;
};

void sewa1::pushToStack2(const booking &data) { Stack2.push(data); }

void sewa1::popFromStack2() { Stack2.pop(); }

void sewa1::enqueueToQueue(const booking &data) { bookings.enqueue(data); }

void sewa1::dequeueFromQueue() { bookings.dequeue(); }

void sewa1::input() {
  int jumlahInput;
  cout << "Masukkan jumlah data : ";
  cin >> jumlahInput;
  cin.ignore();

  for (int i = 0; i < jumlahInput; i++) {
    booking bo;
    cout << "Masukkan data nama    : ";
    getline(cin, bo.nama);
    cout << "Masukkan data NO hp   : ";
    getline(cin, bo.nohp);
    cout << "Masukkan Jenis Mobil  : ";
    getline(cin, bo.jenis);
    cout << "Lama Penyewaan (hari) : ";
    cin >> bo.waktu;
    cout << "Priority (1-10): ";
    cin >> bo.priority;
    cin.ignore();

    Stack2.push(bo);
    bookings.enqueue(bo);

    cout << "Data telah ditambahkan." << endl;
  }
}

void sewa1::output() {
  cout << "Stack2 Contents:" << endl;
  Stack2.display();

  cout << "Queue Contents:" << endl;
  bookings.display();
}

void sewa1::display() { bookings.display(); }

void sewa1::displayStack2() { Stack2.display(); }

void menuBooking() {
  booking bo;
  sewa1 sw;

  while (true) {
    cout << "Menu: " << endl;
    cout << "1. Input Data " << endl;
    cout << "2. Output Data " << endl;
    cout << "3. Pop Stack2" << endl;
    cout << "4. Push Stack2" << endl;
    cout << "5. Dequeue" << endl;
    cout << "6. Enqueue" << endl;
    cout << "7. Exit" << endl;

    cout << "Masukkan Pilihan: ";

    cin >> bo.pil;

    switch (bo.pil) {
    case 1:
      sw.input();
      break;
    case 2:
      sw.output();
      break;
    case 3:
      sw.popFromStack2();
      break;
    case 4:
      sw.input();
      break;
    case 5:
      sw.dequeueFromQueue();
      break;
    case 6:
      sw.input();
      break;
    case 7:
      return;
    default:
      cout << "Pilihan tidak valid." << endl;
    }
  }

}
