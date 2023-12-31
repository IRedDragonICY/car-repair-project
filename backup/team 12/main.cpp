      #include <iostream>
      #include <string>
      #include <vector>
      #include <stack>
      #include <queue>
      #include <algorithm>

      using namespace std;

      // Struktur Data Mobil
      struct Car {
          string brand;
          string model;
          int year;
          double price;

          // Default constructor
          Car() : year(0), price(0.0) {}

          Car(const string& brand, const string& model, int year, double price)
              : brand(brand), model(model), year(year), price(price) {}
      };

      // Class Array Statis
      const int MAX_CARS = 100;
      Car staticCars[MAX_CARS];

      // Class Array Dinamis
      vector<Car> dynamicCars;

      // Class Linked List
      class Node {
      public:
          Car car;
          Node* next;

          Node(const Car& car) : car(car), next(NULL) {}
      };

      class LinkedList {
      public:
          LinkedList() : head(NULL) {}

          void Append(const Car& car) {
              Node* newNode = new Node(car);
              if (!head) {
                  head = newNode;
              } else {
                  Node* current = head;
                  while (current->next) {
                      current = current->next;
                  }
                  current->next = newNode;
              }
          }

          void DisplayAllCars() {
              cout << "Daftar mobil dalam Linked List:" << endl;
              Node* current = head;
              while (current) {
                  DisplayCarDetails(current->car);
                  current = current->next;
              }
          }

      private:
          Node* head;

          void DisplayCarDetails(const Car& car) {
              cout << "Merek: " << car.brand
                   << " - Model: " << car.model
                   << " - Tahun: " << car.year
                   << " - Harga: $" << car.price << endl;
          }
      };

      // Class Double Linked List
      class DoubleNode {
      public:
          Car car;
          DoubleNode* previous;
          DoubleNode* next;

          DoubleNode(const Car& car) : car(car), previous(NULL), next(NULL) {}
      };

      class DoubleLinkedList {
      public:
          DoubleLinkedList() : head(NULL), tail(NULL) {}

          void Append(const Car& car) {
              DoubleNode* newNode = new DoubleNode(car);
              if (!head) {
                  head = tail = newNode;
              } else {
                  tail->next = newNode;
                  newNode->previous = tail;
                  tail = newNode;
              }
          }

          void DisplayAllCars() {
              cout << "Daftar mobil dalam Double Linked List:" << endl;
              DoubleNode* current = head;
              while (current) {
                  DisplayCarDetails(current->car);
                  current = current->next;
              }
          }

      private:
          DoubleNode* head;
          DoubleNode* tail;

          void DisplayCarDetails(const Car& car) {
              cout << "Merek: " << car.brand
                   << " - Model: " << car.model
                   << " - Tahun: " << car.year
                   << " - Harga: $" << car.price << endl;
          }
      };

      // Class Stack dengan Array
      class ArrayStack {
      public:
          ArrayStack() : top(-1) {}

          void Push(const Car& car) {
              if (top < MAX_CARS - 1) {
                  top++;
                  stackArray[top] = car;
              } else {
                  cerr << "Stack is full. Cannot push more cars." << endl;
              }
          }

          void DisplayAllCars() {
              cout << "Daftar mobil dalam Stack dengan Array:" << endl;
              for (int i = top; i >= 0; i--) {
                  DisplayCarDetails(stackArray[i]);
              }
          }

      private:
          Car stackArray[MAX_CARS];
          int top;

          void DisplayCarDetails(const Car& car) {
              cout << "Merek: " << car.brand
                   << " - Model: " << car.model
                   << " - Tahun: " << car.year
                   << " - Harga: $" << car.price << endl;
          }
      };

      // Class Queue dengan Array Circular
      class CircularArrayQueue {
      public:
          CircularArrayQueue() : front(0), rear(-1), count(0) {}

          void Enqueue(const Car& car) {
              if (count < MAX_CARS) {
                  rear = (rear + 1) % MAX_CARS;
                  queueArray[rear] = car;
                  count++;
              } else {
                  cerr << "Queue is full. Cannot enqueue more cars." << endl;
              }
          }

          void DisplayAllCars() {
              cout << "Daftar mobil dalam Queue dengan Array Circular:" << endl;
              int current = front;
              for (int i = 0; i < count; i++) {
                  DisplayCarDetails(queueArray[current]);
                  current = (current + 1) % MAX_CARS;
              }
          }

      private:
          Car queueArray[MAX_CARS];
          int front;
          int rear;
          int count;

          void DisplayCarDetails(const Car& car) {
              cout << "Merek: " << car.brand
                   << " - Model: " << car.model
                   << " - Tahun: " << car.year
                   << " - Harga: $" << car.price << endl;
          }
      };

      // Class Antrian Berprioritas dengan Double Linked List
      class PriorityDoubleNode {
      public:
          Car car;
          int priority;
          PriorityDoubleNode* previous;
          PriorityDoubleNode* next;

          PriorityDoubleNode(const Car& car, int priority) : car(car), priority(priority), previous(NULL), next(NULL) {}
      };

      class PriorityDoubleLinkedList {
      public:
          PriorityDoubleLinkedList() : head(NULL), tail(NULL) {}

          void Enqueue(const Car& car, int priority) {
              PriorityDoubleNode* newNode = new PriorityDoubleNode(car, priority);
              if (!head) {
                  head = tail = newNode;
              } else {
                  PriorityDoubleNode* current = head;
                  while (current && current->priority <= priority) {
                      current = current->next;
                  }

                  if (!current) {
                      // Insert at the end
                      tail->next = newNode;
                      newNode->previous = tail;
                      tail = newNode;
                  } else {
                      // Insert before current
                      newNode->previous = current->previous;
                      newNode->next = current;
                      if (current->previous) {
                          current->previous->next = newNode;
                      } else {
                          head = newNode;
                      }
                      current->previous = newNode;
                  }
              }
          }

          void DisplayAllCars() {
              cout << "Daftar mobil dalam Antrian Berprioritas dengan Double Linked List:" << endl;
              PriorityDoubleNode* current = head;
              while (current) {
                  DisplayCarDetails(current);
                  current = current->next;
              }
          }

      private:
          PriorityDoubleNode* head;
          PriorityDoubleNode* tail;

          void DisplayCarDetails(const PriorityDoubleNode* node) {
              cout << "Merek: " << node->car.brand
                   << " - Model: " << node->car.model
                   << " - Tahun: " << node->car.year
                   << " - Harga: $" << node->car.price
                   << " - Prioritas: " << node->priority << endl;
          }
      };

      // Class Tree
      class TreeNode {
      public:
          Car car;
          TreeNode* left; 
          TreeNode* right;

          TreeNode(const Car& car) : car(car), left(NULL), right(NULL) {}
      };

      class CarSearchTree {
      public:
          CarSearchTree() : root(NULL) {}

          void Insert(const Car& car) {
              root = InsertRec(root, car);
          }

          TreeNode* SearchCarsByBrand(const string& brand) {
              return SearchCarsByBrandRec(root, brand);
          }

          void DisplayCarDetails(TreeNode* node) {
              cout << "Merek: " << node->car.brand
                   << " - Model: " << node->car.model
                   << " - Tahun: " << node->car.year
                   << " - Harga: $" << node->car.price << endl;
          }

      private:
          TreeNode* root;

          TreeNode* InsertRec(TreeNode* root, const Car& car) {
              if (!root) {
                  return new TreeNode(car);
              }

              if (brandCompare(car.brand, root->car.brand) < 0) {
                  root->left = InsertRec(root->left, car);
              } else {
                  root->right = InsertRec(root->right, car);
              }

              return root;
          }

          TreeNode* SearchCarsByBrandRec(TreeNode* root, const string& brand) {
              if (!root || brandCompare(root->car.brand, brand) == 0) {
                  return root;
              }

              if (brandCompare(root->car.brand, brand) < 0) {
                  return SearchCarsByBrandRec(root->right, brand);
              }

              return SearchCarsByBrandRec(root->left, brand);
          }

          int brandCompare(const string& brand1, const string& brand2) {
              string brand1Lower = brand1;
              string brand2Lower = brand2;
              transform(brand1Lower.begin(), brand1Lower.end(), brand1Lower.begin(), ::tolower);
              transform(brand2Lower.begin(), brand2Lower.end(), brand2Lower.begin(), ::tolower);

              return brand1Lower.compare(brand2Lower);
          }
      };

      // Main Program
      int main() {
          LinkedList linkedList;
          DoubleLinkedList doubleLinkedList;
          ArrayStack arrayStack;
          CircularArrayQueue circularArrayQueue;
          PriorityDoubleLinkedList priorityDoubleLinkedList;
          CarSearchTree carSearchTree;

          int choice;

          do {
              cout << "\nMenu:" << endl;
              cout << "1. Tambah Mobil ke Linked List" << endl;
              cout << "2. Tambah Mobil ke Double Linked List" << endl;
              cout << "3. Tambah Mobil ke Stack dengan Array" << endl;
              cout << "4. Tambah Mobil ke Queue dengan Array Circular" << endl;
              cout << "5. Tambah Mobil ke Antrian Berprioritas dengan Double Linked List" << endl;
              cout << "6. Tambah Mobil ke Pohon (Tree)" << endl;
              cout << "7. Tampilkan Semua Mobil dari Linked List" << endl;
              cout << "8. Tampilkan Semua Mobil dari Double Linked List" << endl;
              cout << "9. Tampilkan Semua Mobil dari Stack dengan Array" << endl;
              cout << "10. Tampilkan Semua Mobil dari Queue dengan Array Circular" << endl;
              cout << "11. Tampilkan Semua Mobil dari Antrian Berprioritas dengan Double Linked List" << endl;
              cout << "12. Cari Mobil Berdasarkan Merek dari Pohon (Tree)" << endl;
              cout << "0. Keluar" << endl;

              cout << "Pilihan Anda: ";
              cin >> choice;

              switch (choice) {
                  case 1: {
                      string brand, model;
                      int year;
                      double price;

                      cout << "Masukkan merek mobil: ";
                      cin >> brand;
                      cout << "Masukkan model mobil: ";
                      cin >> model;
                      cout << "Masukkan tahun mobil: ";
                      cin >> year;
                      cout << "Masukkan harga mobil: $";
                      cin >> price;

                      Car newCar(brand, model, year, price);
                      linkedList.Append(newCar);
                      cout << "Mobil berhasil ditambahkan ke Linked List." << endl;
                      break;
                  }
                  case 2: {
                      string brand, model;
                      int year;
                      double price;

                      cout << "Masukkan merek mobil: ";
                      cin >> brand;
                      cout << "Masukkan model mobil: ";
                      cin >> model;
                      cout << "Masukkan tahun mobil: ";
                      cin >> year;
                      cout << "Masukkan harga mobil: $";
                      cin >> price;

                      Car newCar(brand, model, year, price);
                      doubleLinkedList.Append(newCar);
                      cout << "Mobil berhasil ditambahkan ke Double Linked List." << endl;
                      break;
                  }
                  case 3: {
                      string brand, model;
                      int year;
                      double price;

                      cout << "Masukkan merek mobil: ";
                      cin >> brand;
                      cout << "Masukkan model mobil: ";
                      cin >> model;
                      cout << "Masukkan tahun mobil: ";
                      cin >> year;
                      cout << "Masukkan harga mobil: $";
                      cin >> price;

                      Car newCar(brand, model, year, price);
                      arrayStack.Push(newCar);
                      cout << "Mobil berhasil ditambahkan ke Stack dengan Array." << endl;
                      break;
                  }
                  case 4: {
                      string brand, model;
                      int year;
                      double price;

                      cout << "Masukkan merek mobil: ";
                      cin >> brand;
                      cout << "Masukkan model mobil: ";
                      cin >> model;
                      cout << "Masukkan tahun mobil: ";
                      cin >> year;
                      cout << "Masukkan harga mobil: $";
                      cin >> price;

                      Car newCar(brand, model, year, price);
                      circularArrayQueue.Enqueue(newCar);
                      cout << "Mobil berhasil ditambahkan ke Queue dengan Array Circular." << endl;
                      break;
                  }
                  case 5: {
                      string brand, model;
                      int year;
                      double price;
                      int priority;

                      cout << "Masukkan merek mobil: ";
                      cin >> brand;
                      cout << "Masukkan model mobil: ";
                      cin >> model;
                      cout << "Masukkan tahun mobil: ";
                      cin >> year;
                      cout << "Masukkan harga mobil: $";
                      cin >> price;
                      cout << "Masukkan prioritas: ";
                      cin >> priority;

                      Car newCar(brand, model, year, price);
                      priorityDoubleLinkedList.Enqueue(newCar, priority);
                      cout << "Mobil berhasil ditambahkan ke Antrian Berprioritas dengan Double Linked List." << endl;
                      break;
                  }
                  case 6: {
                      string brand, model;
                      int year;
                      double price;

                      cout << "Masukkan merek mobil: ";
                      cin >> brand;
                      cout << "Masukkan model mobil: ";
                      cin >> model;
                      cout << "Masukkan tahun mobil: ";
                      cin >> year;
                      cout << "Masukkan harga mobil: $";
                      cin >> price;

                      Car newCar(brand, model, year, price);
                      carSearchTree.Insert(newCar);
                      cout << "Mobil berhasil ditambahkan ke Pohon (Tree)." << endl;
                      break;
                  }
                  case 7: {
                      linkedList.DisplayAllCars();
                      break;
                  }
                  case 8: {
                      doubleLinkedList.DisplayAllCars();
                      break;
                  }
                  case 9: {
                      arrayStack.DisplayAllCars();
                      break;
                  }
                  case 10: {
                      circularArrayQueue.DisplayAllCars();
                      break;
                  }
                  case 11: {
                      priorityDoubleLinkedList.DisplayAllCars();
                      break;
                  }
                  case 12: {
                      string brand;
                      cout << "Masukkan merek mobil yang dicari: ";
                      cin >> brand;

                      TreeNode* result = carSearchTree.SearchCarsByBrand(brand);
                      if (result) {
                          cout << "Mobil ditemukan:" << endl;
                          carSearchTree.DisplayCarDetails(result);
                      } else {
                          cout << "Mobil tidak ditemukan." << endl;
                      }
                      break;
                  }
                  case 0: {
                      cout << "Program selesai. Sampai jumpa!" << endl;
                      break;
                  }
                  default: {
                      cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                  }
              }
          } while (choice != 0);

          return 0;
      }
