#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> shoppingList;
    int choice;
    string item;

    while (true) {
        cout << "\n--- Shopping List Menu ---\n";
        cout << "1. Store items (Add)\n";
        cout << "2. Add an item\n";
        cout << "3. Remove an item\n";
        cout << "4. Search for an item\n";
        cout << "5. Display all items\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear buffer

        if (choice == 1 || choice == 2) {
            cout << "Enter item name to add: ";
            getline(cin, item);
            shoppingList.push_back(item);
            cout << item << " added to list.\n";
        }
        else if (choice == 3) {
            cout << "Enter item name to remove: ";
            getline(cin, item);
            bool found = false;
            for (int i = 0; i < shoppingList.size(); i++) {
                if (shoppingList[i] == item) {
                    shoppingList.erase(shoppingList.begin() + i);
                    found = true;
                    cout << item << " removed.\n";
                    break;
                }
            }
            if (!found) cout << "Item not found!\n";
        }
        else if (choice == 4) {
            cout << "Enter item name to search: ";
            getline(cin, item);
            bool found = false;
            for (int i = 0; i < shoppingList.size(); i++) {
                if (shoppingList[i] == item) {
                    cout << item << " found at position " << i+1 << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Item not found!\n";
        }
        else if (choice == 5) {
            cout << "\n--- Shopping List ---\n";
            if (shoppingList.empty()) {
                cout << "List is empty.\n";
            } else {
                for (int i = 0; i < shoppingList.size(); i++) {
                    cout << i+1 << ". " << shoppingList[i] << endl;
                }
            }
        }
        else if (choice == 6) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}