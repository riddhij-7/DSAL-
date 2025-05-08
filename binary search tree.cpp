#include<iostream>
using namespace std;

struct node {
    int data;
    node* left = NULL;
    node* right = NULL;
};

class bst {
public:
    node* root;

    bst() {
        root = NULL;
    }

    void create(node*& root) {
        int total, data;
        cout << "Enter the total number of elements: ";
        cin >> total;
        for (int i = 0; i < total; i++) {
            cout << "Enter number " << i + 1 << ": ";
            cin >> data;
            insert(root, data);
        }
    }

    void insert(node*& root, int data) {
        if (root == NULL) {
            root = new node;
            root->data = data;
        } else if (data < root->data) {
            insert(root->left, data);
        } else if (data > root->data) {
            insert(root->right, data);
        }
    }

    void display(node* root) {
        if (root == NULL)
            return;
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }

    node* search(node* root, int key) {
        if (root == NULL) {
            cout << "Value " << key << " not found in tree!" << endl;
            return NULL;
        } else if (root->data == key) {
            cout << "Value " << key << " found in tree!" << endl;
            return root;
        } else if (key < root->data) {
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }

    int findmin(node* root) {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        while (root->left != NULL)
            root = root->left;
        cout << "Minimum value is: " << root->data << endl;
        return root->data;
    }

    int findmax(node* root) {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        while (root->right != NULL)
            root = root->right;
        cout << "Maximum value is: " << root->data << endl;
        return root->data;
    }

    int height(node* root) {
        if (root == NULL)
            return -1;
        int heightLeft = height(root->left);
        int heightRight = height(root->right);
        return max(heightLeft, heightRight) + 1;
    }

    void mirror(node* root) {
        if (root == NULL)
            return;
        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
    }
};

int main() {
    bst b;
    int choice, value, data;
    do {
        cout << "\nBINARY SEARCH TREE OPERATIONS";
        cout << "\n1. Create";
        cout << "\n2. Insert";
        cout << "\n3. Find Minimum";
        cout << "\n4. Find Maximum";
        cout << "\n5. Display";
        cout << "\n6. Search for Node";
        cout << "\n7. Height of the Tree";
        cout << "\n8. Mirror of Tree";
        cout << "\n9. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                b.create(b.root);
                break;
            case 2:
                cout << "Enter the value to insert: ";
                cin >> data;
                b.insert(b.root, data);
                break;
            case 3:
                b.findmin(b.root);
                break;
            case 4:
                b.findmax(b.root);
                break;
            case 5:
                cout << "BST Inorder Traversal: ";
                b.display(b.root);
                cout << endl;
                break;
            case 6:
                cout << "Enter the value to be searched: ";
                cin >> value;
                b.search(b.root, value);
                break;
            case 7:
                cout << "Height of the tree: " << b.height(b.root) << endl;
                break;
            case 8:
                b.mirror(b.root);
                cout << "BST after mirroring (inorder): ";
                b.display(b.root);
                cout << endl;
                break;
            case 9:
                cout << "Thank you!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
