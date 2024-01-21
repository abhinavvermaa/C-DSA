#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the queue

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int data) {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue is full. Cannot enqueue." << endl;
        } else {
            arr[++rear] = data;
            if (front == -1) {
                front = 0;
            }
            cout << data << " has been enqueued." << endl;
        }
    }

    // Function to remove an element from the queue (dequeue)
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            int data = arr[front++];
            cout << data << " has been dequeued." << endl;
            if (front > rear) {
                front = rear = -1; // Reset front and rear when the queue is empty
            }
        }
    }

    // Function to display the queue elements
    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue queue;
    int choice, data;

    do {
        cout << "Queue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                queue.enqueue(data);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
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

