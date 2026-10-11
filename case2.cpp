#include <iostream>
#include <string>
using namespace std;

struct Coach {
    string name;
    Coach* next;
};

Coach* head = NULL;

void addBeginning(string name) {
    Coach* newCoach = new Coach();
    newCoach->name = name;
    newCoach->next = head;
    head = newCoach;
    cout << name << " added at beginning.\n";
}

void addEnd(string name) {
    Coach* newCoach = new Coach();
    newCoach->name = name;
    newCoach->next = NULL;
    if (head == NULL) {
        head = newCoach;
    } else {
        Coach* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newCoach;
    }
    cout << name << " added at end.\n";
}

void removeCoach(string name) {
    if (head == NULL) { cout << "No coaches!\n"; return; }
    if (head->name == name) {
        Coach* temp = head;
        head = head->next;
        delete temp;
        cout << name << " removed.\n";
        return;
    }
    Coach *curr = head, *prev = NULL;
    while (curr != NULL && curr->name != name) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) cout << "Coach not found!\n";
    else {
        prev->next = curr->next;
        delete curr;
        cout << name << " removed.\n";
    }
}

void display() {
    if (head == NULL) { cout << "Train is empty!\n"; return; }
    Coach* temp = head;
    cout << "Train: ";
    while (temp != NULL) {
        cout << temp->name;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

int main() {
    int choice; string name;
    while (true) {
        cout << "\n--- Train Coach Menu ---\n";
        cout << "1. Add at beginning\n2. Add at end\n3. Remove a coach\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 5) break;
        if (choice == 1 || choice == 2 || choice == 3) {
            cout << "Enter coach name (ex: Coach1): ";
            getline(cin, name);
        }
        if (choice == 1) addBeginning(name);
        else if (choice == 2) addEnd(name);
        else if (choice == 3) removeCoach(name);
        else if (choice == 4) display();
        else cout << "Invalid!\n";
    }
    return 0;
}