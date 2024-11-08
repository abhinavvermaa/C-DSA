#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Task {
    string description;
    string priority;
    bool completed;
};

// Function to display a task with its details
void displayTask(const Task& task, int index) {
    cout << index + 1 << ". " << task.description 
         << " [Priority: " << task.priority 
         << ", Status: " << (task.completed ? "Completed" : "Incomplete") << "]\n";
}

// Function to add a new task
void addTask(vector<Task>& tasks) {
    Task newTask;
    int priorityChoice;

    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);

    cout << "Select priority (1 - High, 2 - Medium, 3 - Low): ";
    cin >> priorityChoice;

    switch (priorityChoice) {
        case 1: newTask.priority = "High"; break;
        case 2: newTask.priority = "Medium"; break;
        case 3: newTask.priority = "Low"; break;
        default: cout << "Invalid priority, defaulting to Low.\n"; newTask.priority = "Low";
    }
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }
    cout << "\n--- To-Do List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        displayTask(tasks[i], i);
    }
}

// Function to mark a task as complete
void completeTask(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter the task number to mark as complete: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks[index - 1].completed = true;
        cout << "Task marked as complete!\n";
    }
}

// Function to delete a task
void deleteTask(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter the task number to delete: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully!\n";
    }
}

// Function to save tasks to a file
void saveTasks(const vector<Task>& tasks) {
    ofstream outFile("tasks.txt");
    for (const auto& task : tasks) {
        outFile << task.description << "\n" 
                << task.priority << "\n" 
                << task.completed << "\n";
    }
    cout << "Tasks saved to file.\n";
}

// Function to load tasks from a file
void loadTasks(vector<Task>& tasks) {
    ifstream inFile("tasks.txt");
    if (!inFile) return;

    Task task;
    while (getline(inFile, task.description)) {
        getline(inFile, task.priority);
        inFile >> task.completed;
        inFile.ignore();
        tasks.push_back(task);
    }
    cout << "Tasks loaded from file.\n";
}

int main() {
    vector<Task> tasks;
    loadTasks(tasks);  // Load tasks from file on program start

    int choice;
    do {
        cout << "\n--- Enhanced To-Do List ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Complete\n";
        cout << "4. Delete Task\n";
        cout << "5. Save Tasks to File\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                completeTask(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                saveTasks(tasks);
                break;
            case 6:
                saveTasks(tasks);  // Save tasks before exiting
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
