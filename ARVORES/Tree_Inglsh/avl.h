#pragma

// Nós da arvore
struct Node {
  int value;
  int height; // altura nó
  Node *left;
  Node *right;
};

int height(Node *node);
int getBalance(Node *node);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
Node *insertAVL(Node *node, int value);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);
void printTree(Node* node, int level);

