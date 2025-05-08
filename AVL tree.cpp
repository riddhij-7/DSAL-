#include <iostream>
using namespace std;

class node {
public:
    string keyword;
    string meaning;
    node* left;
    node* right;
    int hght;

    node(string key, string mean) {
        keyword = key;
        meaning = mean;
        left = right = NULL;
        hght = 0;
    }
};

class tree {
public:
    node* root;

    tree() {
        root = NULL;
    }

    int height(node* t) {
        if (t == NULL)
            return 0;
        int hl = height(t->left);
        int hr = height(t->right);
        return 1 + max(hl, hr);
    }

    int bf(node* t) {
        if (t == NULL)
            return 0;
        return height(t->left) - height(t->right);
    }

    node* rotate_right(node* t) {
        node* y = t->left;
        t->left = y->right;
        y->right = t;
        return y;
    }

    node* rotate_left(node* t) {
        node* y = t->right;
        t->right = y->left;
        y->left = t;
        return y;
    }

    node* LL(node* p) {
        return rotate_right(p);
    }

    node* RR(node* p) {
        return rotate_left(p);
    }

    node* LR(node* X) {
        X->left = rotate_left(X->left);
        return rotate_right(X);
    }

    node* RL(node* X) {
        X->right = rotate_right(X->right);
        return rotate_left(X);
    }

    node* insert(node* root, string key, string mean) {
        if (root == NULL)
            return new node(key, mean);

        if (key < root->keyword) {
            root->left = insert(root->left, key, mean);
            if (bf(root) == 2) {
                if (key < root->left->keyword)
                    return LL(root);
                else
                    return LR(root);
            }
        }
        else if (key > root->keyword) {
            root->right = insert(root->right, key, mean);
            if (bf(root) == -2) {
                if (key > root->right->keyword)
                    return RR(root);
                else
                    return RL(root);
            }
        }
        else {
            cout << "Duplicate key. Insertion not allowed.\n";
        }
        return root;
    }

    void insert_word() {
        string key, mean;
        cout << "Enter word: ";
        cin >> key;
        cout << "Enter meaning: ";
        cin.ignore();
        getline(cin, mean);
        root = insert(root, key, mean);
    }

    void search(string key) {
        node* temp = root;
        while (temp != NULL) {
            if (temp->keyword == key) {
                cout << "Word found: " << temp->keyword << " --> " << temp->meaning << endl;
                return;
            }
            else if (key < temp->keyword)
                temp = temp->left;
            else
                temp = temp->right;
        }
        cout << "Word not found.\n";
    }

    void update(string key) {
        node* temp = root;
        while (temp != NULL) {
            if (temp->keyword == key) {
                cout << "Enter new meaning: ";
                cin.ignore();
                getline(cin, temp->meaning);
                cout << "Meaning updated.\n";
                return;
            }
            else if (key < temp->keyword)
                temp = temp->left;
            else
                temp = temp->right;
        }
        cout << "Word not found.\n";
    }

    node* del(node* root, string key) {
        if (root == NULL)
            return NULL;

        if (key < root->keyword)
            root->left = del(root->left, key);
        else if (key > root->keyword)
            root->right = del(root->right, key);
        else {
            if (root->left == NULL || root->right == NULL) {
                node* temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            }

            node* succ = root->right;
            while (succ->left != NULL)
                succ = succ->left;
            root->keyword = succ->keyword;
            root->meaning = succ->meaning;
            root->right = del(root->right, succ->keyword);
        }

        int balance = bf(root);
        if (balance > 1) {
            if (bf(root->left) >= 0)
                return LL(root);
            else
                return LR(root);
        }
        if (balance < -1) {
            if (bf(root->right) <= 0)
                return RR(root);
            else
                return RL(root);
        }
        return root;
    }

    void delete_word(string key) {
        root = del(root, key);
    }

    void inorder(node* p) {
        if (p != NULL) {
            inorder(p->left);
            cout << p->keyword << " --> " << p->meaning << endl;
            inorder(p->right);
        }
    }

    void display() {
        cout << "Inorder Traversal of Dictionary:\n";
        inorder(root);
    }
};

int main() {
    tree t;
    int choice;
    string key;

    do {
        cout << "\n===== AVL Dictionary Menu =====\n";
        cout << "1. Insert word\n";
        cout << "2. Search word\n";
        cout << "3. Update meaning\n";
        cout << "4. Delete word\n";
        cout << "5. Display dictionary (Inorder)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            t.insert_word();
            break;
        case 2:
            cout << "Enter word to search: ";
            cin >> key;
            t.search(key);
            break;
        case 3:
            cout << "Enter word to update meaning: ";
            cin >> key;
            t.update(key);
            break;
        case 4:
            cout << "Enter word to delete: ";
            cin >> key;
            t.delete_word(key);
            break;
        case 5:
            t.display();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
