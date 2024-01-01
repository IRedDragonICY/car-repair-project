#include<iostream>
#include<cstdlib>

using namespace std;

class BinaryTree
{
private:
  struct nodeTree
  {
    nodeTree* left;
    nodeTree* right;
    string data;
  };

  nodeTree* root;	
public:
  BinaryTree()
  {
    root = NULL;
  }
  bool isEmpty() const
  {
    return root==NULL; 
  }

  void cetak_inorder();
  void inorder(nodeTree*);
  void cetak_preorder();
  void preorder(nodeTree*);
  void cetak_postorder();
  void postorder(nodeTree*);
  void insert_data(string);
};

void BinaryTree::insert_data(string d)
{
  nodeTree* t = new nodeTree;
  nodeTree* parent;
  t->data = d;
  t->left = NULL;
  t->right = NULL;
  parent = NULL;

  if(isEmpty())
  {
    root = t;	
  }
  else
  {
    nodeTree* current;
    current = root;

    while(current)
    {
      parent = current;
      if(t->data > current->data) current = current->right;
      else current = current->left;
    }	
    if(t->data < parent->data)
      parent->left = t;
    else
      parent->right = t;
  }
}

void BinaryTree::cetak_inorder()
{
  inorder(root);
}

void BinaryTree::inorder(nodeTree* p)
{
  if(p != NULL)
  {
    if(p->left) inorder(p->left);
      cout<<" "<<p->data<<" ";
    if(p->right) inorder(p->right);
  }
  else return;
}

void BinaryTree::cetak_preorder()
{
  preorder(root);
}

void BinaryTree::preorder(nodeTree* p)
{
  if(p != NULL)
  {
    cout<<" "<<p->data<<" ";
    if(p->left) preorder(p->left);
    if(p->right) preorder(p->right);
  }
  else return;
}

void BinaryTree::cetak_postorder()
{
  postorder(root);
}

void BinaryTree::postorder(nodeTree* p)
{
  if(p != NULL)
  {
    if(p->left) postorder(p->left);
    if(p->right) postorder(p->right);
    cout<<" "<<p->data<<" ";
  }
  else return;

}
