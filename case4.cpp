#include <iostream>
#include <string>
using namespace std;

#define MAX 20
string history[MAX];
int top = -1;

void visit(string url) {
    if (top == MAX - 1) {
        cout << "History Full!" << endl;
    } else {
        top++;
        history[top] = url;
        cout << "Visited: " << url << endl;
    }
}

void pressBack() {
    if (top == -1) {
        cout << "No history to go back!" << endl;
    } else {
        cout << "Back from: " << history[top] << endl;
        top--;
        if (top!= -1) {
            cout << "Current page: " << history[top] << endl;
        } else {
            cout << "No pages left!" << endl;
        }
    }
}

void display() {
    if (top == -1) {
        cout << "History empty!" << endl;
        return;
    }
    cout << "\nBrowser History (TOP = current page):" << endl;
    cout << "--------------------------" << endl;
    for (int i = top; i >= 0; i--) {
        cout << i << ". " << history[i];
        if (i == top) cout << " <- TOP (Current Page)";
        cout << endl;
    }
    cout << "--------------------------" << endl;
}

int main() {
    cout << "=== BROWSER HISTORY SIMULATION ===" << endl;

    // Initial visits from question
    visit("google.com");
    visit("youtube.com");
    visit("abesc.com");
    visit("facebook.com");

    cout << "\nInitial TOP: " << history[top] << " (facebook.com)" << endl;
    display();

    cout << "\n--- QUESTION: If Back is pressed twice? ---" << endl;
    cout << "Pressing Back 1st time..." << endl;
    pressBack(); // Removes facebook.com, top = abesc.com
    cout << "Pressing Back 2nd time..." << endl;
    pressBack(); // Removes abesc.com, top = youtube.com

    cout << "\n>>> ANSWER: After 2 Back presses, TOP is: " << history[top] << " <<<" << endl;
    cout << "So youtube.com is currently at the top!" << endl;

    // Interactive menu after showing answer
    int choice;
    string url;
    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Visit new page\n";
        cout << "2. Press Back\n";
        cout << "3. Display History\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 4) break;

        if (choice == 1) {
            cout << "Enter URL: ";
            getline(cin, url);
            visit(url);
        } else if (choice == 2) {
            pressBack();
        } else if (choice == 3) {
            display();
        }
    }
    return 0;
}