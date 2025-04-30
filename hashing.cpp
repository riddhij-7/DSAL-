#include <iostream>
#include <string>
using namespace std;

struct node {
    int telephone;
    string name;
    struct node* next;
};

struct node1 {
    int telephone;
    string name;
};

class linear {
    node1* hashtable[10];
public:
    linear() {
        for (int i = 0; i < 10; i++) {
            hashtable[i] = NULL;
        }
    }

    void insert() {
        int telephone;
        string name;

        cout << "\nEnter the telephone number: ";
        cin >> telephone;
        cout << "Enter the name: ";
        cin >> name;

        int loc = telephone % 10;
        node1* ptr = new node1{telephone, name};

        int startLoc = loc;
        while (hashtable[loc] != NULL) {
            loc = (loc + 1) % 10;
            if (loc == startLoc) {
                cout << "Hash table is full!" << endl;
                delete ptr;
                return;
            }
        }

        hashtable[loc] = ptr;
        cout << "Inserted at position " << loc << "!\n";
    }

    void search() {
        int telephone, comparison = 0;
        cout << "\nEnter the telephone number to search: ";
        cin >> telephone;

        int loc = telephone % 10;
        int originalloc = loc;

        while (hashtable[loc] != NULL) {
            comparison++;
            if (hashtable[loc]->telephone == telephone) {
                cout << "Telephone found at location " << loc << " with name: " << hashtable[loc]->name << "\n";
                cout << "Total comparisons: " << comparison << endl;
                return;
            }
            loc = (loc + 1) % 10;
            if (loc == originalloc) break;
        }

        cout << "Telephone " << telephone << " not found.\n";
        cout << "Total comparisons: " << comparison << endl;
    }

    void display() {
        for (int i = 0; i < 10; i++) {
            if (hashtable[i] != NULL) {
                cout << "[" << i << "] Telephone: " << hashtable[i]->telephone
                     << ", Name: " << hashtable[i]->name << "\n";
            } else {
                cout << "[" << i << "] -- EMPTY --\n";
            }
        }
    }
};

class colision {
    node* hashtable[10];
public:
    colision() {
        for (int i = 0; i < 10; i++) {
            hashtable[i] = NULL;
        }
    }

    void insert() {
        int telephone;
        string name;
        cout << "\nEnter the telephone number: ";
        cin >> telephone;
        cout << "Enter the name: ";
        cin >> name;

        int loc = telephone % 10;
        node* ptr = new node{telephone, name, NULL};

        if (hashtable[loc] == NULL) {
            hashtable[loc] = ptr;
            cout << "Inserted successfully at index " << loc << "!\n";
        } else {
            node* current = hashtable[loc];
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = ptr;
            cout << "Inserted in linked list at index " << loc << "!\n";
        }
    }

    void search() {
        int telephone, comparisons = 0;
        cout << "\nEnter the telephone number to search: ";
        cin >> telephone;

        int loc = telephone % 10;
        node* current = hashtable[loc];

        while (current != NULL) {
            comparisons++;
            if (current->telephone == telephone) {
                cout << "Telephone found at index " << loc << " with name: " << current->name << "\n";
                cout << "Total comparisons: " << comparisons << endl;
                return;
            }
            current = current->next;
        }

        cout << "Telephone " << telephone << " not found.\n";
        cout << "Total comparisons: " << comparisons << endl;
    }

    void display() {
        for (int i = 0; i < 10; i++) {
            cout << "[" << i << "] ";
            node* current = hashtable[i];
            if (current == NULL) {
                cout << "-- EMPTY --\n";
            } else {
                while (current != NULL) {
                    cout << "-> [Telephone: " << current->telephone << ", Name: " << current->name << "] ";
                    current = current->next;
                }
                cout << "\n";
            }
        }
    }
};

int main() {
    int choice, method;
    linear l1;
    colision c1;

    cout << "\nChoose hashing method:\n";
    cout << "1. Closed hashing (Linear Probing)\n";
    cout << "2. Open hashing (Chaining)\n";
    cout << "Enter your choice: ";
    cin >> method;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n2. Search\n3. Display\n4. Exit\n";
        cout << "Enter a valid choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (method == 1)
                    l1.insert();
                else if (method == 2)
                    c1.insert();
                break;

            case 2:
                if (method == 1)
                    l1.search();
                else if (method == 2)
                    c1.search();
                break;

            case 3:
                if (method == 1)
                    l1.display();
                else if (method == 2)
                    c1.display();
                break;

            case 4:
                cout << "--- EXIT ---\n";
                break;

            default:
                cout << "Enter a valid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
