#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "Enter the number of elements in the BST: ";
    cin >> n;

    cout << "Enter the elements:\n";

    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "In-order traversal of the BST: ";
    inOrderTraversal(root);

    return 0;
}

