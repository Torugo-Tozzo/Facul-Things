#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void printTree(Node* node, int level) {
  if (node == nullptr) return;

  // Imprime o valor do nó atual
  for (int i = 0; i < level; i++) std::cout << "        ";
  std::cout << node->data << std::endl;

  // Imprime os nós filhos
  printTree(node->left, level + 1);
  printTree(node->right, level + 1);
}

int main() {
    Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    insert(root, 9);
    insert(root, 10);
    insert(root, 11);
    insert(root, 12);
    insert(root, 13);

    inorder(root);
    std::cout << "------------------" << std::endl;

    printTree(root,0);

    return 0;
}
