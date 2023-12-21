#include <iostream>
#include <vector>
#include <limits> // Include the necessary header for numeric_limits

using namespace std;

// Function to display the to-do list
void displayToDoList(const vector<string>& toDoList) {
    cout << "To-Do List:" << endl;
    if (toDoList.empty()) {
        cout << "No tasks in the list." << endl;
    } else {
        for (size_t i = 0; i < toDoList.size(); ++i) {
            cout << i + 1 << ". " << toDoList[i] << endl;
        }
    }
    cout << endl;
}

// Function to add a task to the to-do list
void addTask(vector<string>& toDoList, const string& task) {
    toDoList.push_back(task);
    cout << "Task added successfully!" << endl << endl;
}

// Function to mark a task as completed
void markTaskAsCompleted(vector<string>& toDoList, size_t taskIndex) {
    if (taskIndex >= 0 && taskIndex < toDoList.size()) {
        cout << "Marking task as completed: " << toDoList[taskIndex] << endl;
        // Optionally, you can move the completed task to a separate list or remove it.
        // For simplicity, this example removes the task from the to-do list.
        toDoList.erase(toDoList.begin() + taskIndex);
        cout << "Task marked as completed!" << endl << endl;
    } else {
        cout << "Invalid task index!" << endl << endl;
    }
}

int main() {
    vector<string> toDoList;

    cout << "Welcome to the To-Do List Manager!" << endl;

    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Display To-Do List" << endl;
        cout << "2. Add Task" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Quit" << endl;

        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        // Check for valid input
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue; // Skip the rest of the loop
        }

        // Clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                displayToDoList(toDoList);
                break;
            case 2:
            {
                string task;
                cout << "Enter the task: ";
                getline(cin, task);
                addTask(toDoList, task);
            }
            break;
            case 3:
            {
                size_t taskIndex;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> taskIndex;

                // Check for valid input
                if (cin.fail() || taskIndex <= 0 || taskIndex > toDoList.size()) {
                    cout << "Invalid task index." << endl;
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    continue; // Skip the rest of the loop
                }

                markTaskAsCompleted(toDoList, taskIndex - 1);
            }
            break;
            case 4:
                cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
                return 0; // End the program
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl << endl;
        }
    }

    return 0; // This line is not strictly necessary but included for completeness
}
