#include <iostream>
#include <string>
using namespace std;

class UlasanRating {
public:
    string ulasan;
    int rating;

    UlasanRating(int rating, const string &ulasan) : rating(rating), ulasan(ulasan) {}
};

class TreeNode {
public:
    UlasanRating ulasanRating;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const UlasanRating &ulasanRating) : ulasanRating(ulasanRating), left(NULL), right(NULL) {}
};

class BinarySearchTree {
private:
    TreeNode* root;
public:
    BinarySearchTree() : root(NULL) {}

    void insert(const UlasanRating &ulasanRating) {
        root = insertRecursive(root, ulasanRating);
    }

    bool isEmpty() const {
        return root == NULL;
    }

    void displayUlasan() const {
        displayUlasanRecursive(root);
    }

    ~BinarySearchTree() {
        destroyTree(root);
    }

private:
    TreeNode* insertRecursive(TreeNode* node, const UlasanRating &ulasanRating) {
        if (node == NULL) {
            return new TreeNode(ulasanRating);
        }

        if (ulasanRating.rating > node->ulasanRating.rating) {
            node->left = insertRecursive(node->left, ulasanRating);
        } else {
            node->right = insertRecursive(node->right, ulasanRating);
        }

        return node;
    }
    
    void displayUlasanRecursive(TreeNode* node) const {
      if (node == NULL) {
        return;
      }

      displayUlasanRecursive(node->right);

      cout << "Rating: " << node->ulasanRating.rating << "/5" << endl;
      cout << "Ulasan: " << node->ulasanRating.ulasan << endl;

      displayUlasanRecursive(node->left);
    }


    void destroyTree(TreeNode* node) {
        if (node == NULL) {
            return;
        }

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
};

void menuUlasan() {
    BinarySearchTree ulasanTree;
    
    while (true) {
        int rating;
        string ulasan;
        cout << "Masukkan rating (1-5) atau 0 untuk selesai: ";
        cin >> rating;

        if (rating == 0) {
            break;
        }

        if (rating >= 1 && rating <= 5) {
            cin.ignore();
            cout << "Masukkan ulasan: ";
            getline(cin, ulasan);

            UlasanRating newUlasan(rating, ulasan);
            ulasanTree.insert(newUlasan);
        } else {
            cout << "Rating harus antara 1-5" << endl;
        }
    }
    //menampilkans statemen jika ulasan kosong
    if (ulasanTree.isEmpty()) {
        cout << "Pohon kosong, tidak ada ulasan yang dapat dihapus.\n";
    }

    // Menampilkan ulasan yang telah diurutkan
    cout << "\nUlasan setelah diurutkan berdasarkan rating:\n";
    ulasanTree.displayUlasan();

}