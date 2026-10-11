#include <iostream>
#include <string>
using namespace std;

#define MAX 10
string garage[MAX];
int top = -1;

void carEnters(string car) {
    if (top == MAX - 1) {
        cout << "Garage is FULL! Cannot park " << car << endl;
    } else {
        top++;
        garage[top] = car;
        cout << car << " parked at position " << top << endl;
    }
}

void carLeaves() {
    if (top == -1) {
        cout << "Garage is EMPTY!" << endl;
    } else {
        cout << garage[top] << " left the garage (LIFO order)" << endl;
        top--;
    }
}

void display() {
    if (top == -1) {
        cout << "Garage is empty!" << endl;
    } else {
        cout << "\nCars in garage (Last entered is on TOP - will leave first):" << endl;
        cout << "-----------------" << endl;
        for (int i = top; i >= 0; i--) {
            cout << i << ". " << garage[i];
            if (i == top) cout << " <- TOP (last entered, first to leave)";
            cout << endl;
        }
        cout << "-----------------" << endl;
        cout << "LIFO: Last In First Out - " << garage[top] << " will leave first!" << endl;
    }
}

int main() {
    int choice;
    string car;

    cout << "=== NARROW PARKING GARAGE SIMULATION ===" << endl;
    cout << "Cars can only leave in reverse order (LIFO)" << endl;

    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Car Enters Garage (PUSH)\n";
        cout << "2. Car Leaves Garage (POP)\n";
        cout << "3. Display Garage\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 4) {
            cout << "Exiting program." << endl;
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter car number (ex: TN01 AB1234): ";
                getline(cin, car);
                carEnters(car);
                break;
            case 2:
                carLeaves();
                break;
            case 3:
                display();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}