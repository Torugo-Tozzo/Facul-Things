#include <iostream>
#include "Binaria.h"

#define true 1
#define false 0

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
