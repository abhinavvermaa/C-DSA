#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack Overflow. Cannot push more elements." << endl;
    } else {
        stack[++top] = item;
        cout << "Pushed " << item << " onto the stack." << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack is empty. Cannot pop." << endl;
    } else {
        cout << "Popped " << stack[top--] << " from the stack." << endl;
    }
}

void display() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack contents: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, item;
    
    do {
        cout << "Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter item to push: ";
                cin >> item;
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

