#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Insert into BST
Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum value node
Node* Findminimum(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Delete from BST
Node* deleteNode(Node* root, int val) {
    if (root == nullptr) return root;

    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        // Case 1: If there is no child
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        // Case 2: if there is one child
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        Node* temp = Findminimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder Traversal (sorted order)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of elements to be inserted into the BST: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Enter number of elements to be deleted from BST: ";
    cin >> n;
    cout << "Enter elements to delete: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = deleteNode(root, val);
    }

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
