#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include "avl.h"

int height(Node *node) {
  if (node == nullptr)
    return 0;
  return node->height;
}

int getBalance(Node *node) {
  if (node == nullptr)
    return 0;
  return height(node->left) - height(node->right);
}

Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;

  // Rotação
  x->right = y;
  y->left = T2;

  // Atualização das alturas
  y->height = std::max(height(y->left), height(y->right)) + 1;
  x->height = std::max(height(x->left), height(x->right)) + 1;

  // Retorna o novo raiz
  return x;
}

Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;

  // Rotação
  y->left = x;
  x->right = T2;

  // Atualização das alturas
  x->height = std::max(height(x->left), height(x->right)) + 1;
  y->height = std::max(height(y->left), height(y->right)) + 1;

  // Retorna o novo raiz
  return y;
}

Node *insertAVL(Node *node, int value) {
  // Inserção normal de um nó em uma árvore binária de busca
  if (node == nullptr) {
    node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
  } else if (value < node->value)
    node->left = insertAVL(node->left, value);
  else if (value > node->value)
    node->right = insertAVL(node->right, value);
  else
    return node;

  // Atualização da altura do nó atual
  node->height = 1 + std::max(height(node->left), height(node->right));

  // Calcula o fator de balanceamento deste nó ancestral para verificar se a
  // árvore está desbalanceada
  int balance = getBalance(node);

  // Se a árvore estiver desbalanceada, precisamos realizar uma rotação
  if (balance > 1 && value < node->left->value) {
    // Rotação simples à direita
    return rightRotate(node);
  }
  if (balance < -1 && value > node->right->value) {
    // Rotação simples à esquerda
    return leftRotate(node);
  }
  if (balance > 1 && value > node->left->value) {
    // Rotação dupla à direita
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  if (balance < -1 && value < node->right->value) {
    // Rotação dupla à esquerda
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  // Se a árvore não estiver desbalanceada, retornamos o nó atual
  return node;
}

// Em-ordem
void inorder(Node *root) {
  if (root == nullptr)
    return;
  inorder(root->left);
  std::cout << root->value << " ";
  inorder(root->right);
}

// Pré-ordem
void preorder(Node *root) {
  if (root == nullptr)
    return;
  std::cout << root->value << " ";
  preorder(root->left);
  preorder(root->right);
}

// Pós-ordem
void postorder(Node *root) {
  if (root == nullptr)
    return;
  postorder(root->left);
  postorder(root->right);
  std::cout << root->value << " ";
}

Node* minValueNode(Node* node) {
  Node* current = node;

  /* loop para encontrar o menor valor em
     uma subarvore */
  while (current->left != nullptr) {
    current = current->left;
  }
  return current;
}

Node* deleteNode(Node* root, int value) {
  // Passo 1: Realiza a exclusão normal de um nó em uma árvore binária de busca
if (root == nullptr) return root;
if (value < root->value) {
root->left = deleteNode(root->left, value);
} else if (value > root->value) {
root->right = deleteNode(root->right, value);
} else {
// Node com um ou zero filhos
if (root->left == nullptr || root->right == nullptr) {
Node* temp = root->left ? root->left : root->right;
  // Caso sem filhos
  if (temp == nullptr) {
    temp = root;
    root = nullptr;
  } else {
    // Caso com um filho
    *root = *temp;
  }
  delete temp;
} else {
  // Node com dois filhos: obtém o sucessor in-order
  Node* temp = minValueNode(root->right);

  // Copia o valor do sucessor para o nó atual
  root->value = temp->value;

  // Exclui o sucessor
  root->right = deleteNode(root->right, temp->value);
}
}

// Passo 2: Se a árvore só tem um nó, então retorna
if (root == nullptr) return root;

// Passo 3: Atualiza a altura deste nó ancestral
root->height = 1 + std::max(height(root->left), height(root->right));

// Passo 4: Verifica se a árvore está desbalanceada
int balance = getBalance(root);

// Se a árvore estiver desbalanceada, precisamos realizar uma rotação
if (balance > 1 && getBalance(root->left) >= 0) {
return rightRotate(root);
}
if (balance > 1 && getBalance(root->left) < 0) {
root->left = leftRotate(root->left);
return rightRotate(root);
}
if (balance < -1 && getBalance(root->right) <= 0) {
return leftRotate(root);
}
if (balance < -1 && getBalance(root->right) > 0) {
root->right = rightRotate(root->right);
return leftRotate(root);
}

// Se a árvore não estiver desbalanceada, retornamos o nó atual
return root;
}

void freeTree(Node* node) {
  if (node == nullptr) return;
  
  // Desaloca primeiro os nós filhos
  freeTree(node->left);
  freeTree(node->right);
  
  // Desaloca o nó atual
  delete node;
}

void printTree(Node* node, int level) {
  if (node == nullptr) return;

  // Imprime o valor do nó atual
  for (int i = 0; i < level; i++) std::cout << "        ";
  std::cout << node->value << std::endl;

  // Imprime os nós filhos
  printTree(node->left, level + 1);
  printTree(node->right, level + 1);
}
