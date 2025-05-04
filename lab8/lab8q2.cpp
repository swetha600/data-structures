#include <stdio.h>
#include <stdlib.h>

class BinaryTree {
private:
    struct Node {
        char data;
        Node *left, *right;
        Node(char val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node *root;

public:
    BinaryTree();
    void insert(char val);
    void preorder();
    void inorder();
    void postorder();
    bool search(char val);

private:
    Node* insert(Node* node, char val);
    void preorder(Node* node);
    void inorder(Node* node);
    void postorder(Node* node);
    bool search(Node* node, char val);
};

int main() {
    BinaryTree tree;
    int choice;
    char val;
    
    while (true) {
        printf("\nMenu:\n");
        printf("1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &val);
                tree.insert(val);
                break;
            case 2:
                printf("Preorder: ");
                tree.preorder();
                break;
            case 3:
                printf("Inorder: ");
                tree.inorder();
                break;
            case 4:
                printf("Postorder: ");
                tree.postorder();
                break;
            case 5:
                printf("Enter character to search: ");
                scanf(" %c", &val);
                printf(tree.search(val) ? "Character found!\n" : "Character not found.\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice, try again!\n");
        }
    }
}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::Node* BinaryTree::insert(Node* node, char val) {
    if (!node) return new Node(val);
    if (val < node->data) node->left = insert(node->left, val);
    else node->right = insert(node->right, val);
    return node;
}

void BinaryTree::insert(char val) {
    root = insert(root, val);
}

void BinaryTree::preorder(Node* node) {
    if (node) {
        printf("%c ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void BinaryTree::preorder() {
    preorder(root);
    printf("\n");
}

void BinaryTree::inorder(Node* node) {
    if (node) {
        inorder(node->left);
        printf("%c ", node->data);
        inorder(node->right);
    }
}

void BinaryTree::inorder() {
    inorder(root);
    printf("\n");
}

void BinaryTree::postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        printf("%c ", node->data);
    }
}

void BinaryTree::postorder() {
    postorder(root);
    printf("\n");
}

bool BinaryTree::search(Node* node, char val) {
    if (!node) return false;
    if (node->data == val) return true;
    return val < node->data ? search(node->left, val) : search(node->right, val);
}

bool BinaryTree::search(char val) {
    return search(root, val);
}
