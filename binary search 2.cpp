#include <iostream>
#include <string>
using namespace std;

// Node structure
class Node {
public:
    string keyword, meaning;
    Node* left;
    Node* right;

    Node(string k, string m) {
        keyword = k;
        meaning = m;
        left = right = nullptr;
    }
};

// Dictionary class using BST
class Dictionary {
private:
    Node* root;

    Node* insert(Node* root, string keyword, string meaning) {
        if (root == nullptr)
            return new Node(keyword, meaning);
        if (keyword < root->keyword)
            root->left = insert(root->left, keyword, meaning);
        else if (keyword > root->keyword)
            root->right = insert(root->right, keyword, meaning);
        else
            cout << "Keyword already exists.\n";
        return root;
    }

    Node* findMin(Node* root) {
        while (root->left != nullptr)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, string keyword) {
        if (root == nullptr)
            return root;
        if (keyword < root->keyword)
            root->left = deleteNode(root->left, keyword);
        else if (keyword > root->keyword)
            root->right = deleteNode(root->right, keyword);
        else {
            // node with one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // node with two children
            Node* temp = findMin(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->keyword);
        }
        return root;
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->keyword << " : " << root->meaning << endl;
            inorder(root->right);
        }
    }

    void reverseInorder(Node* root) {
        if (root != nullptr) {
            reverseInorder(root->right);
            cout << root->keyword << " : " << root->meaning << endl;
            reverseInorder(root->left);
        }
    }

    int search(Node* root, string keyword, int& comparisons) {
        if (root == nullptr)
            return 0;

        comparisons++;
        if (keyword == root->keyword)
            return 1;
        else if (keyword < root->keyword)
            return search(root->left, keyword, comparisons);
        else
            return search(root->right, keyword, comparisons);
    }

    int height(Node* root) {
        if (root == nullptr)
            return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    void update(Node* root, string keyword, string newMeaning) {
        if (root == nullptr)
            return;

        if (keyword == root->keyword) {
            root->meaning = newMeaning;
            cout << "Updated successfully.\n";
        }
        else if (keyword < root->keyword)
            update(root->left, keyword, newMeaning);
        else
            update(root->right, keyword, newMeaning);
    }

public:
    Dictionary() {
        root = nullptr;
    }

    void add(string keyword, string meaning) {
        root = insert(root, keyword, meaning);
    }

    void remove(string keyword) {
        root = deleteNode(root, keyword);
    }

    void displayAscending() {
        cout << "\nDictionary in Ascending Order:\n";
        inorder(root);
    }

    void displayDescending() {
        cout << "\nDictionary in Descending Order:\n";
        reverseInorder(root);
    }

    void updateMeaning(string keyword, string newMeaning) {
        update(root, keyword, newMeaning);
    }

    void findKeyword(string keyword) {
        int comparisons = 0;
        if (search(root, keyword, comparisons))
            cout << "Keyword found in " << comparisons << " comparisons.\n";
        else
            cout << "Keyword not found.\n";
    }

    void maxComparisons() {
        int h = height(root);
        cout << "Maximum comparisons required to find any keyword: " << h << endl;
    }
};

// Main function
int main() {
    Dictionary dict;
    int choice;
    string keyword, meaning;

    do {
        cout << "\n--- Dictionary Menu ---\n";
        cout << "1. Add keyword\n";
        cout << "2. Delete keyword\n";
        cout << "3. Update meaning\n";
        cout << "4. Display (Ascending)\n";
        cout << "5. Display (Descending)\n";
        cout << "6. Find a keyword\n";
        cout << "7. Max comparisons required\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                getline(cin, keyword);
                cout << "Enter meaning: ";
                getline(cin, meaning);
                dict.add(keyword, meaning);
                break;
            case 2:
                cout << "Enter keyword to delete: ";
                getline(cin, keyword);
                dict.remove(keyword);
                break;
            case 3:
                cout << "Enter keyword to update: ";
                getline(cin, keyword);
                cout << "Enter new meaning: ";
                getline(cin, meaning);
                dict.updateMeaning(keyword, meaning);
                break;
            case 4:
                dict.displayAscending();
                break;
            case 5:
                dict.displayDescending();
                break;
            case 6:
                cout << "Enter keyword to find: ";
                getline(cin, keyword);
                dict.findKeyword(keyword);
                break;
            case 7:
                dict.maxComparisons();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 8);

    return 0;
}
