#pragma
#include <string>

using namespace std;

// Nós da arvore
template <typename T>
struct Node {
  T value;
  int height; // altura nó
  Node *left;
  Node *right;

   Node(T value) : value(value), height(1), left(nullptr), right(nullptr) {}
};

template <typename T>
Node<T>* insert(Node<T>* node, T value);
/*
int height(Node *node);
int getBalance(Node *node);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
Node *insertAVL(Node *node, int value);
Node *insert(Node *node, string newName);

void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);
Node* minValueNode(Node* node);
Node* deleteNode(Node* root, int value);
void freeTree(Node* node);
void printTree(Node* node, int level);
*/

