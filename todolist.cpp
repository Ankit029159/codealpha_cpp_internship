#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& task) {
        tasks.emplace_back(task);
        cout << "Task \"" << task << "\" added." << endl;
    }

    void markCompleted(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task " << taskNumber << " marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "\nCurrent Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                 << " - " << (tasks[i].completed ? "Done" : "Pending") << endl;
        }
    }
};

void showMenu() {
    cout << "\nTo-Do List Application" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Mark Task as Completed" << endl;
    cout << "3. View Tasks" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    TodoList todoList;
    int choice;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear input buffer
                cout << "Enter the task description: ";
                string task;
                getline(cin, task);
                todoList.addTask(task);
                break;
            }
            case 2: {
                todoList.viewTasks();
                cout << "Enter the task number to mark as completed: ";
                int taskNumber;
                cin >> taskNumber;
                todoList.markCompleted(taskNumber);
                break;
            }
            case 3: {
                todoList.viewTasks();
                break;
            }
            case 4: {
                cout << "Exiting the application. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
}
