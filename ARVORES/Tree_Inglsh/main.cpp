# include <iostream>
# include "avl.cpp"

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->value = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//Inserção sem balanceamento
Node* insertBI(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data <= root->value) {
        root->left = insertBI(root->left, data);
    } else {
        root->right = insertBI(root->right, data);
    }
    return root;
}

int main() {

  Node *rootAVL = nullptr;

  rootAVL = insertAVL(rootAVL, 1928);
  rootAVL = insertAVL(rootAVL, 1700);
  rootAVL = insertAVL(rootAVL, 1500);
  rootAVL = insertAVL(rootAVL, 1444);
  rootAVL = insertAVL(rootAVL, 2001);
  rootAVL = insertAVL(rootAVL, 3000);

  inorder(rootAVL);
  std::cout << "\n---------" << std::endl;
  postorder(rootAVL);
  std::cout << "\n---------" << std::endl;
  preorder(rootAVL);
  std::cout << "\n---------" << std::endl;
  
  printTree(rootAVL, 0);

  Node *root = nullptr;
    // antes do balancemento AVL
    root = insertBI(root,2);
    insertBI(root, 3);
    insertBI(root, 5);
    insertBI(root, 4);
    insertBI(root, 7);
    insertBI(root, 11);
    insertBI(root, 1);

    std::cout << root->value << std::endl;
    std::cout << root->right->value << std::endl;

    printf("\n em ordem \n");

    inorder(root);

    printf("\n pre ordem \n");

    preorder(root);

    printf("\n pos ordem \n");

    postorder(root);

    printf("\n --------- \n");

    printTree(root,0);

 return 0; 
}
