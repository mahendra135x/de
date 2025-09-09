#include <iostream> 
#include <list> 
using namespace std; 
 
class HashTable { 
    int size; 
    list<int> *table; 
 
public: 
    HashTable(int size) { 
        this->size = size; 
        table = new list<int>[size]; 
    } 
 
    int hashFunction(int key) { 
        return key % size; 
    } 
 
    void insert(int key) { 
        int index = hashFunction(key); 
        table[index].push_back(key); 
        cout << key << " inserted at index " << index << endl; 
    } 
 
    bool search(int key) { 
        int index = hashFunction(key); 
        for (int x : table[index]) { 
            if (x == key) { 
                cout << key << " found at index " << index << endl; 
                return true; 
            } 
        } 
        cout << key << " not found!" << endl; 
        return false; 
    } 
 
    void remove(int key) { 
        int index = hashFunction(key); 
        for (auto it = table[index].begin(); it != table[index].end(); it++) { 
            if (*it == key) { 
                table[index].erase(it); 
                cout << key << " deleted from index " << index << endl; 
                return; 
            } 
        } 
        cout << key << " not found, cannot delete!" << endl; 
    } 
 
    void display() { 
        for (int i = 0; i < size; i++) { 
            cout << "Index " << i << ": "; 
            for (int x : table[i]) { 
                cout << x << " -> "; 
            } 
            cout << "NULL" << endl; 
        } 
    } 
}; 
 
int main() { 
    int size; 
    cout << "Enter the size of hash table: "; 
    cin >> size; 
 
    HashTable h(size); 
 
    int choice, key; 
    while (true) { 
        cout << "\n--- Hash Table Menu ---\n"; 
        cout << "1. Insertion\n2. Search Operation\n3. Deletion\n4. Displaying the table\n5. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                cout << "Enter the value to insert: "; 
                cin >> key; 
                h.insert(key); 
                break; 
 
            case 2: 
                cout << "Enter the value to search: "; 
                cin >> key; 
                h.search(key); 
                break; 
 
            case 3: 
                cout << "Enter value to delete: "; 
                cin >> key; 
                h.remove(key); 
                break; 
 
            case 4: 
                h.display(); 
                break; 
 
            case 5: 
                cout << "Exiting program..." << endl; 
                return 0; 
 
            default: 
                cout << "Invalid choice! Try again." << endl; 
        } 
    } 
 
    return 0; 
} 