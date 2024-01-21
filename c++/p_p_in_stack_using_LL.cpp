#include <iostream>
using namespace std;

// Define a structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    Stack() {
        top = nullptr; // Initialize an empty stack
    }

    // Function to push an item onto the stack
    void push(int item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << item << " onto the stack." << endl;
    }

    // Function to pop an item from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        int poppedItem = temp->data;
        delete temp;
        cout << "Popped " << poppedItem << " from the stack." << endl;
    }

    // Function to display the stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack contents: ";
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

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
                stack.push(item);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
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

