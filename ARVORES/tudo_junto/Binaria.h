#pragma

#define true 1
#define false 0

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data);
Node* insert(Node* root, int data);
void inorder(Node* root);
void printTree(Node* node, int level);