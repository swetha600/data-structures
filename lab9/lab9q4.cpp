#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
private:
    Node* root;
    
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

public:
    ExpressionTree() : root(nullptr) {}
    
    void constructFromPostfix(const char* postfix) {
        stack<Node*> st;
        for (int i = 0; i < strlen(postfix); i++) {
            char c = postfix[i];
            Node* newNode = new Node(c);
            if (isOperator(c)) {
                if (st.size() < 2) {
                    printf("Invalid postfix expression!\n");
                    return;
                }
                newNode->right = st.top(); st.pop();
                newNode->left = st.top(); st.pop();
            }
            st.push(newNode);
        }
        if (st.size() != 1) {
            printf("Invalid postfix expression!\n");
            return;
        }
        root = st.top();
    }
    
    void preorder(Node* node) {
        if (node) {
            printf("%c ", node->data);
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            printf("%c ", node->data);
            inorder(node->right);
        }
    }
    
    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            printf("%c ", node->data);
        }
    }
    
    void printPreorder() { printf("Preorder: "); preorder(root); printf("\n"); }
    void printInorder() { printf("Inorder: "); inorder(root); printf("\n"); }
    void printPostorder() { printf("Postorder: "); postorder(root); printf("\n"); }
};

int main() {
    char postfix[100];
    ExpressionTree tree;
    int choice;
    
    do {
        printf("\n1. Enter Postfix Expression");
        printf("\n2. Construct Expression Tree");
        printf("\n3. Preorder");
        printf("\n4. Inorder");
        printf("\n5. Postorder");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                break;
            case 2:
                tree.constructFromPostfix(postfix);
                printf("Expression tree constructed.\n");
                break;
            case 3:
                tree.printPreorder();
                break;
            case 4:
                tree.printInorder();
                break;
            case 5:
                tree.printPostorder();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    
    return 0;
}
