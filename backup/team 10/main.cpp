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

class NodeDoubly {
public:
  booking data;
  NodeDoubly *next;
  NodeDoubly *prev;

  NodeDoubly(const booking &data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}

  void insert(const booking &data) {
    NodeDoubly *newNode = new NodeDoubly(data);
    if (!head) {
      head = tail = newNode;
    } else {
      NodeDoubly *current = head;
      while (current && current->data.priority >= data.priority) {
        current = current->next;
      }

      if (!current) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
      } else {
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev) {
          current->prev->next = newNode;
        } else {
          head = newNode;
        }
        current->prev = newNode;
      }
    }
  }

  void display() {
    NodeDoubly *current = head;
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
    NodeDoubly *current = head;
    while (current) {
      NodeDoubly *temp = current;
      current = current->next;
      delete temp;
    }
  }

private:
  NodeDoubly *head;
  NodeDoubly *tail;
};

class Stack {
private:
  vector<booking> arr;

public:
  void push(const booking &data) { arr.push_back(data); }

  void pop() {
    if (!arr.empty()) {
      arr.pop_back();
    } else {
      cout << "Stack is empty." << endl;
    }
  }

  void display() {
    cout << "Stack Contents:" << endl;
    for (int i = 0; i < arr.size(); i++) {
      cout << "Data ke-" << i + 1 << endl;
      cout << "Nama Penyewa   : " << arr[i].nama << endl;
      cout << "No Handphone   : " << arr[i].nohp << endl;
      cout << "Jenis Mobil    : " << arr[i].jenis << endl;
      cout << "Lama Sewa(hari):" << arr[i].waktu << endl;
      cout << endl;
    }
  }
};

class Node {
public:
  booking data;
  Node *next;

  Node(const booking &data) : data(data), next(nullptr) {}
};

class CircularLinkedList {
public:
  CircularLinkedList() : head(nullptr) {}

  void push(const booking &data) {
    Node *newNode = new Node(data);
    if (!head) {
      head = newNode;
      head->next = head;
    } else {
      newNode->next = head;
      Node *current = head;
      while (current->next != head) {
        current = current->next;
      }
      current->next = newNode;
      head = newNode;
    }
  }

  void pushBack(const booking &data) {
    Node *newNode = new Node(data);
    if (!head) {
      head = newNode;
      head->next = head;
    } else {
      Node *current = head;
      while (current->next != head) {
        current = current->next;
      }
      current->next = newNode;
      newNode->next = head;
    }
  }

  void enqueue(const booking &data) { pushBack(data); }

  void dequeue() {
    if (head) {
      Node *temp = head;
      if (head->next != head) {
        head = head->next;
        Node *current = head;
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
    Node *current = head;
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
      Node *current = head;
      do {
        Node *temp = current;
        current = current->next;
        delete temp;
      } while (current != head);
    }
  }

private:
  Node *head;
};

class sewa {
public:
  void input();
  void output();
  void display();
  void displayStack();
  void pushToStack(const booking &data);
  void popFromStack();
  void enqueueToQueue(const booking &data);
  void dequeueFromQueue();

private:
  CircularLinkedList bookings;
  Stack stack;
};

void sewa::pushToStack(const booking &data) { stack.push(data); }

void sewa::popFromStack() { stack.pop(); }

void sewa::enqueueToQueue(const booking &data) { bookings.enqueue(data); }

void sewa::dequeueFromQueue() { bookings.dequeue(); }

void sewa::input() {
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

    stack.push(bo);
    bookings.enqueue(bo);

    cout << "Data telah ditambahkan." << endl;
  }
}

void sewa::output() {
  cout << "Stack Contents:" << endl;
  stack.display();

  cout << "Queue Contents:" << endl;
  bookings.display();
}

void sewa::display() { bookings.display(); }

void sewa::displayStack() { stack.display(); }

int main() {
  booking bo;
  sewa sw;

  while (true) {
    cout << "Menu: " << endl;
    cout << "1. Input Data " << endl;
    cout << "2. Output Data " << endl;
    cout << "3. Pop Stack" << endl;
    cout << "4. Push Stack" << endl;
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
      sw.popFromStack();
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
      return 0; // Exit the program
    default:
      cout << "Pilihan tidak valid." << endl;
    }
  }

  return 0;
}
